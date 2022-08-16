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

const int MAXN = 1000010;

int n;
int a[MAXN];
vector<int> v[MAXN];

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
	}
	ll ans = 0;
	{
	set<int> H;
	H.insert(0);
	H.insert(n+1);
	for (int i = 1; i <= 1000000; ++ i)
		for (auto mid : v[i])
		{
			auto p = H.lower_bound(mid);
			int y = *p--;
			int x = *p;
			ans += (ll)(mid-x)*(y-mid)*(-i);
			H.insert(mid);
		}
	}
	{
	set<int> H;
	H.insert(0);
	H.insert(n+1);
	for (int i = 1000000; i >= 1; -- i)
		for (auto mid : v[i])
		{
			auto p = H.lower_bound(mid);
			int y = *p--;
			int x = *p;
			ans += (ll)(mid-x)*(y-mid)*i;
			H.insert(mid);
		}
	}
	cout << ans << endl;
	
	return 0;
}