#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include<climits>
typedef long long ll;
using namespace std;
const ll N=4000000;
ll n;
ll a[N+5];
ll Gcd;
map<ll,ll> p;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	Gcd=a[1];
	for(ll i=2;i<=n;i++) Gcd=__gcd(Gcd,a[i]);
	ll S=sqrt(Gcd)+1;
	for(ll i=2;i<=S;i++)
	{
		while(Gcd%i==0)
		{
			Gcd/=i;
			p[i]++;
		}
	}
	if(Gcd!=1) p[Gcd]++;
	map<ll,ll>::iterator it;
	ll ans=1;
	for(it=p.begin();it!=p.end();it++) ans=ans*(it->second+1);
	printf("%lld\n",ans);
	return 0;
}