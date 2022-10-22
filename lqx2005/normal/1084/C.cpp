#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
const ll MOD=1e9+7;
string s;
ll slen,vlen;
int main()
{
	cin>>s;
	slen=s.length();
	vector<ll> v;
	ll step=0;
	bool flag=0;
	for(ll i=0;i<s.length();i++) 
	{
		if(flag)
		{
			if(s[i]=='b') continue;
			else if(s[i]=='a') flag=0,step=1;
			else  continue;
		}
		else 
		{
			if(s[i]=='b') v.push_back(step),step=0,flag=1;
			else if(s[i]=='a') step++;
			else continue;
		}
	}  
	if(!flag) v.push_back(step);
	vlen=v.size();
	ll ans=1;
	for(ll i=0;i<vlen;i++) ans=(ans*(v[i]+1))%MOD;
	ans--;
	if(ans<0) ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}