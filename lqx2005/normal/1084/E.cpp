#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,k;
string s,t;
int main()
{
	scanf("%lld%lld",&n,&k);
	cin>>s>>t;
	ll now=1,ans=0;
	for(ll i=0;i<n;i++)
	{
		if(now>k)
		{
			ans+=k;
			continue;
		}
		now*=2;
		if(s[i]=='b') now--;
		if(t[i]=='a') now--;
		if(now<0) break;
		if(now>k) ans+=k;
		else ans+=now;
	}
	printf("%lld\n",ans);
	return 0;
}