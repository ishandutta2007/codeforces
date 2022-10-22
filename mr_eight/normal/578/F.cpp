#include<bits/stdc++.h>
#define eps 1e-15
#define maxn 105
#define maxm 200010
#define inf 1000000007
//#define mod 1000000007
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int>pii;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,mod;
char s[maxn][maxn];
int fa[maxn*maxn];
int id(int i,int j)
{
    return (i-1)*(m+1)+j;
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int u=find(x),v=find(y);
    fa[u]=v;
}
int quick_pow(int x,int p)
{
    int an=1,po=x;
    while(p)
    {
        if(p&1)  an=1ll*an*po%mod;
        po=1ll*po*po%mod;
        p>>=1;
    }
    return an;
}
int idx[maxn*maxn];
struct Matrix{
    int a[maxn*5][maxn*5],N;
    void add(int x,int y)
    {
        if(x==y)  return;
        a[x][x]++;a[y][y]++;
        a[x][y]--;a[y][x]--;
    }
    int solve()
    {
        for(int i=1;i<=N;i++)
          for(int j=1;j<=N;j++)  a[i][j]=(a[i][j]+mod)%mod;
        int res=1;
        for(int i=1;i<N;i++)
        {
            int pos=i;
            while(pos<N&&!a[pos][i])  pos++;
            if(pos>=N)  continue;
            if(pos!=i)  res=mod-res,swap(a[pos],a[i]);
            int inv=quick_pow(a[i][i],mod-2);
            for(int j=i+1;j<N;j++)
            {
                int tmp=1ll*inv*a[j][i]%mod;
                for(int k=i;k<N;k++)  a[j][k]=(a[j][k]-1ll*a[i][k]*tmp%mod+mod)%mod;
            }
        }
        for(int i=1;i<N;i++)  res=1ll*res*a[i][i]%mod;
        return res;
    }
}G[2];
int main()
{
    n=read();m=read();mod=read();
    for(int i=1;i<=n;i++)  scanf("%s",s[i]+1);   
    for(int i=1;i<=(n+1)*(m+1);i++)  fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='/')  merge(id(i+1,j),id(i,j+1));
            else if(s[i][j]!='*')  merge(id(i,j),id(i+1,j+1));
        }
    }
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=m+1;j++)
        {
            if(find(id(i,j))==id(i,j))  G[(i+j)&1].N++,idx[id(i,j)]=G[(i+j)&1].N;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='*')
            {
                G[(i+j)&1].add(idx[find(id(i,j))],idx[find(id(i+1,j+1))]);
                G[(i+j+1)&1].add(idx[find(id(i+1,j))],idx[find(id(i,j+1))]);
            }
        }
    }
    int ans=(G[0].solve()+G[1].solve())%mod;
    cout<<ans<<endl;
    return 0;
}