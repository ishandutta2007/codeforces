#include <bits/stdc++.h>
using namespace std;

#define bufferSiz  1 << 16
char B[bufferSiz], *_S = B, *_T = B;
#define getchar() (_S == _T && (_T = (_S = B) + fread(B, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    register T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c))
    {
        if(c=='-') f=-f;
        c = getchar();
    }
    while (isdigit(c)) num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
    return f * num;
}

#define maxn 205

vector<vector<int> > graph;

int n,K,a[maxn],f[maxn][maxn];

void dfs(int p,int fa)
{
    f[p][0]=a[p];
    for(vector<int>::iterator i=graph[p].begin();i!=graph[p].end();i++)
        if(*i!=fa)
        {
            dfs(*i,p);
            for(int j=0;j<=n;j++) f[p][j]=max(f[p][j]+f[*i][max(j,K-j)-1],f[p][max(j,K-j)]+f[*i][j-1]);
        }
    for(register int i=n;~i;--i) f[p][i]=max(f[p][i],f[p][i+1]);
    return;
}

int main()
{
    n=read<int>(),K=read<int>()+1;
    for(register int i=1;i<=n;i++) a[i]=read<int>();
    graph.resize(n+1);
    for(register int i=1,from,to;i<n;i++)
    {
        from=read<int>(),to=read<int>();
        graph[from].push_back(to),graph[to].push_back(from);
    }
    dfs(1,0);
    int ans=0;
    for(register int i=0;i<=n;i++) ans=max(ans,f[1][i]);
    printf("%d\n",ans);
    return 0;
}