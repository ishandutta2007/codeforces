#include <stdio.h>
#include <vector>
using namespace std;

#define MAXN 100005

int T,N,K,P[MAXN],dep[MAXN],num[MAXN],OUT[MAXN],tar[MAXN],mom[MAXN][18];
int stk[MAXN],I[MAXN],scnt;
vector <int> con[MAXN],list[MAXN];

void dfs(int n)
{
    int top,k;
    scnt = 0;
    stk[++scnt] = n; dep[n] = 1;
    while (scnt){
        top = stk[scnt];
        if (!num[top]){
            num[top] = ++K; tar[K] = top;
        }
        if (I[top] < con[top].size()){
            k = con[top][I[top]++];
            dep[k] = dep[top]+1;
            stk[++scnt] = k;
        }else{
            OUT[top] = K;
            stk[scnt--] = 0;
        }
    }
}

int get_mom(int n,int p)
{
    int i;
    for (i=0;i<18;i++) if ((p>>i)&1) n = mom[n][i];
    return n;
}

int count(int dep,int l,int r)
{
    int s,e,m,p=1e8,q=-1e9;
    for (s=0,e=list[dep].size()-1;s<=e;){
        m = (s+e)>>1;
        if (list[dep][m] <= r) s = m+1, q = m;
        else e = m-1;
    }
    for (s=0,e=list[dep].size()-1;s<=e;){
        m = (s+e)>>1;
        if (list[dep][m] >= l) e = m-1, p = m;
        else s = m+1;
    }
    return q-p+1>0?q-p+1:0;
}

int main()
{
    int i,j,k,v,p;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",P+i), mom[i][0] = P[i], con[P[i]].push_back(i);
    for (i=1;i<18;i++) for (j=1;j<=N;j++) mom[j][i] = mom[mom[j][i-1]][i-1];
    for (i=1;i<=N;i++) if (!P[i]){
        dfs(i);
    }
    for (i=1;i<=N;i++) list[dep[tar[i]]].push_back(i);
    for (scanf("%d",&T);T--;){
        scanf("%d%d",&v,&p);
        k = get_mom(v,p);
        if (!k) printf("0 ");
        else{
            j = get_mom(v,p-1);
            printf("%d ",count(dep[v],num[k],OUT[k])-1);
        }
    }
}