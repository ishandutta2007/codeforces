#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=200000;
const ll M=20;
const ll INF=1e8;
ll t,n,p2[M+5];
ll l[N+5];
string s;
int main()
{
	p2[0]=1;
	for(ll i=1;i<=M;i++) p2[i]=p2[i-1]*2;
	scanf("%lld",&t);
	while(t--)
	{
		ll ans=0;
		cin>>s;
		n=s.length();
		l[0]=0;
		for(ll i=1;i<n;i++) 
		{
			if(s[i-1]=='0') l[i]=l[i-1]+1;
			else l[i]=0;
		}
		for(ll i=0;i<n;i++)
		{
			ll now=0; 
			for(ll len=1;len<=M;len++)
			{
				if(i-len+1<0) break;
				if(s[i-len+1]=='0') continue;
				now=now+(s[i-len+1]-'0')*p2[len-1];
				ll step=len+l[i-len+1];
				if(now==0) continue;
				if(step>=now) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}