#include <bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int a[N];
char A[N];
char B[N];
vector<int> v[25];
int buc[250];
int find(int x){
    return buc[x]==x?x:buc[x]=find(buc[x]);
}
void solve(){

    n=read();
    scanf("%s",A+1);
    scanf("%s",B+1);
    for(int i=0;i<=20;i++) v[i].clear();
    for(int i=0;i<=200;i++) buc[i]=i;
    for(int i=1;i<=n;i++){
        int x=B[i]-'a';
        v[x].push_back(i);
    }
    int ans=0;
    int ls=-1;
    for(int i=0;i<=20;i++)
    {
        bool add=0;
        for(int j=0;j<v[i].size();j++)
        {
            int pos=v[i][j];
            if(A[pos]>B[pos])
            {
                puts("-1");
                return ;
            }
            int x=find(A[pos]),y=find(B[pos]);

            if(x!=y)
            {
                ans++;
                buc[x]=y;
            }

        }
    }
    printf("%d\n",ans);
}
int main()
{
//    freopen("big_zero.in","r",stdin);
    int T;
    T=read();
    while(T--) solve();
}