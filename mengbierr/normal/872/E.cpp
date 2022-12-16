#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;
const int MOD=1000000007;

int n,x[N],y[N],w[N],f[N*2],size[N*2],val[N*2];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int ksm(int x,int y)
{
    int ans=1;
    while (y)
    {
        if (y&1) ans=(LL)ans*x%MOD;
        x=(LL)x*x%MOD;y>>=1;
    }
    return ans;
}

int find(int x)
{
    if (f[x]==x) return x;
    else return f[x]=find(f[x]);
}

int main()
{
    n=read();
    for (int i=1;i<=n;i++) x[i]=read(),y[i]=read(),w[i]=x[i];
    sort(w+1,w+n+1);
    int w1=unique(w+1,w+n+1)-w-1;
    for (int i=1;i<=n;i++) x[i]=lower_bound(w+1,w+w1+1,x[i])-w;
    for (int i=1;i<=n;i++) w[i]=y[i];
    sort(w+1,w+n+1);
    w1=unique(w+1,w+n+1)-w-1;
    for (int i=1;i<=n;i++) y[i]=lower_bound(w+1,w+w1+1,y[i])-w;
    for (int i=1;i<=n*2;i++) f[i]=i,size[i]=1;
    for (int i=1;i<=n;i++)
    {
        int p=find(x[i]),q=find(y[i]+n);
        if (p!=q) f[p]=q,val[q]+=val[p]+1,size[q]+=size[p];
        else val[p]++;
    }
    int ans=1;
    for (int i=1;i<=n*2;i++)
        if (f[i]==i) ans=(LL)ans*(ksm(2,size[i])-(val[i]<size[i]))%MOD;
    printf("%d",ans);
    return 0;
}