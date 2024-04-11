#include<bits/stdc++.h>
using namespace std;
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
const int N=200005,P=998244353;
int n,o[N];ll x[N],y[N],f[N],s[N];
int main()
{
	n=rd();
	rep(i,1,n)x[i]=rd(),y[i]=rd(),o[i]=rd();
	x[n+1]=x[n]+1;
	rep(i,1,n)
	{
		int p=upper_bound(x+1,x+n+1,y[i])-x;
		if(p<i)
		{
			f[i]=(x[p]-y[i]+s[i-1]+P-s[p-1]+x[i+1]-x[i])%P;
		}
		else
		{
			f[i]=(x[i+1]-y[i])%P;
		}
//		cout<<f[i]<<endl;
		s[i]=(s[i-1]+f[i])%P;
	}
	ll ans=x[1]%P;
	rep(i,1,n)
	{
		if(o[i])ans=(ans+f[i])%P;
		else ans=(ans+x[i+1]-x[i])%P;
	}
	printf("%lld\n",ans);return 0;
}