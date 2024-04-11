#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,n,phi,p,tmp,ans,l1,l2,fla;char s1[1000005],s2[1000005];
inline ll qpow(ll x,ll tmp) {ll r=1;for(;tmp;tmp>>=1,x=x*x%p) if(tmp&1) r=r*x%p;return r%p;}
signed main()
{
	scanf("%s %s %lld",s1+1,s2+1,&p),l1=strlen(s1+1),l2=strlen(s2+1),phi=tmp=p,a=n=fla=0;
	for(ll i=2,e=sqrt(tmp);i<=e;i++) if(tmp%i==0) {phi-=phi/i;while(tmp%i==0) tmp/=i;}
	for(ll i=1;i<=l1;i++) a=(a*10+s1[i]-'0')%p;if(tmp>1) phi-=phi/tmp;
	for(ll i=l2;i>=1;i--) if(s2[i]=='0') s2[i]='9';else {s2[i]--;break;}
	for(ll i=1;i<=l2;i++) n=n*10+s2[i]-'0',fla+=(n>=phi),n%=phi;
	return fla?n+=phi:0,ans=((a-1)*qpow(a,n)%p+p)%p,printf("%lld\n",ans?ans:p),0;
}