#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

int main()
{
	
	ll m, b;cin >> m >> b;
	ll ans = 0;
	for (ll y = 0; y <= b; ++ y)
	{
		ll x = (ll)(b-y)*m;
		ans = max(ans, x*(x+1)/2*(y+1)+y*(y+1)/2*(x+1));
	}
	cout << ans << endl;
	
	return 0;
}