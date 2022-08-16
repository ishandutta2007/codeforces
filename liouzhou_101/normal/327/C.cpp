#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MOD=1000000007;

string s;
int n,k;
ll ans;

ll power(ll x,ll y)
{
	if (!y) return 1;
	ll t=power(x,y/2);
	t=t*t%MOD;
	if (y&1) t=t*x%MOD;
	return t;
}

ll rev(ll x)
{
	return power(x,MOD-2);
}

int main()
{
	cin>>s>>k;
	n=s.size();
	for (int i=0;i<n;++i)
		if (s[i]=='5'||s[i]=='0')
			(ans+=power(2,i)*(power(2,(ll)k*n%(MOD-1))-1)%MOD*rev(power(2,n)-1)%MOD)%=MOD;
	cout<<ans<<endl;
	return 0;
}