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
const int N=200005,P=1e9+7;
int n,m,b[N],a[N],c[N],d[35],fac[N],ifac[N];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int C(int a,int b){return 1ll*fac[a]*ifac[b]%P*ifac[a-b]%P;}
int main()
{
    fac[0]=1;
    rep(i,1,200000)fac[i]=1ll*fac[i-1]*i%P;
    rep(i,0,200000)ifac[i]=pw(fac[i],P-2);
    n=rd();m=0;
    rep(i,1,n)b[i]=rd();
    rep(i,1,n)if(~b[i]&1)a[++m]=b[i];
    rep(i,1,m)
    {
        c[i]=0;int t=a[i];
        while(~t&1)t>>=1,c[i]++;
        d[c[i]]++;
    }
    int ss=0,ans=0;
    per(i,30,1)
    {
        int s=d[i],res=0,t=0;
        rep(j,0,s)if(j&1)res=(res+1ll*fac[s]*ifac[j]%P*ifac[s-j])%P;
        ans=(ans+1ll*pw(2,ss)*res)%P;
//        cout<<s<<" "<<ss<<" "<<ans<<endl;
        ss+=s;
    }
    ans++;
    printf("%d\n",(pw(2,n)+P-ans)%P);
    return 0;
}