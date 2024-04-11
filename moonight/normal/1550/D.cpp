#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=200005,P=1000000007;
int n,n1,n2,ans,fac[N],ifac[N];ll l,r;
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int C(int a,int b)
{
	if(a<0||b<0||a<b)return 0;
	return 1ll*fac[a]*ifac[b]%P*ifac[a-b]%P;
}
inline ll calc(int p,int q)
{
	if(p+q<n)return 0;
	int t=p+q-n;p-=t;q-=t;
	return C(t,n1-p);
}
int main()
{
	int T=rd();fac[0]=1;ifac[0]=1;
	rep0(i,1,N)fac[i]=1ll*fac[i-1]*i%P,ifac[i]=pw(fac[i],P-2);
	while(T--)
	{
		n=rd();l=rd();r=rd();
		n1=n/2;n2=n-n1;//n1<=n2
		ll l1=l-1,r1=r-1;
		ll ln=l-n,rn=r-n;
		ll t=std::min(-l1,rn);
		if(t)ans=1ll*t*calc(n,n)%P;else ans=0;
		if(n1!=n2)ans=2ll*ans%P;
		rep(i,1,n)
		{
			ll x=t+i;
			ll p=l+x;ll q=r-x;
			if(p>n||q<1)break;
			if(p<1)p=1;
			if(q>n)q=n;
			p=n-p+1;
			ans=(ans+calc(q,p))%P;
			if(n1!=n2)ans=(ans+calc(p,q))%P;
		}
		printf("%d\n",ans);
	}
	return 0;
}