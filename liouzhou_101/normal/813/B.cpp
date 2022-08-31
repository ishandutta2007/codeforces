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

const int MAXN = 1111;

int main()
{
	
	ll x, y, l, r;
	cin >> x >> y >> l >> r;
	set<ll> F;
	for (ll a = 1; ; a *= x)
	{
		for (ll b = 1; ; b *= y)
		{
			F.insert(a+b);
			if (b > 1000000000000000000LL/y) break;
		}
		if (a > 1000000000000000000LL/x) break;
	}
	vector<ll> v;
	v.push_back(l-1);
	for (auto x : F)
		if (l <= x && x <= r)
			v.push_back(x);
	v.push_back(r+1);
	
	ll ans = 0;
	for (int i = 0; i+1 < v.size(); ++ i)
		ans = max(ans, v[i+1]-v[i]-1);
	cout << ans << endl;
	
	return 0;
}