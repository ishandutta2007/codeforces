#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=15,M=1<<14,P=1000000007;
int n,nn,a[N],p[N][N],q[N][M],sz[M],f[M];
inline int pls(int a,int b){a+=b;return a>=P?a-P:a;}
inline int pw(int a,int b)
{
    int r=1;
    for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;
    return r;
}
int main()
{
    n=rd();nn=1<<n;
    rep0(i,0,n)a[i]=rd();
    rep0(i,0,n)rep0(j,0,n)p[i][j]=i==j?0:1ll*a[i]*pw(a[i]+a[j],P-2)%P;//i beat j
/*    rep0(i,0,n)
    {
        rep0(j,0,n)cout<<p[i][j]<<" ";
        cout<<endl;
    }*/
    rep0(i,0,n)
    {
        rep0(j,0,nn)if(~j>>i&1)
        {
            int s=1;
            rep0(k,0,n)if(j>>k&1)s=1ll*s*p[i][k]%P;
            q[i][j]=s;
//            cout<<i<<" "<<j<<" "<<s<<endl;
        }
    }
    rep0(i,1,nn)sz[i]=sz[i>>1]+(i&1);
    int ans=0;
    rep0(S,1,nn)
    {
        f[S]=0;
        for(int S1=(S-1)&S;S1;S1=(S1-1)&S)
        {
            int S2=S^S1,w=f[S1];
            rep0(i,0,n)if(S1>>i&1)w=1ll*w*q[i][S2]%P;
            f[S]=pls(f[S],w);
        }
        f[S]=P+1-f[S];
        int T=(nn-1)^S,t=f[S];
        rep0(i,0,n)if(S>>i&1)t=1ll*t*q[i][T]%P;
//        cout<<S<<" "<<sz[S]<<" "<<f[S]<<" "<<t<<endl;
        ans=(ans+1ll*t*sz[S])%P;
    }
    printf("%d\n",ans);
    return 0;
}