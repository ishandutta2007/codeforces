#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define INF 1000000007
#define LLINF 2696969696969696969ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

string s;
ll tot = 0, cur = 0, ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	FOR(i, 0, SZ(s) - 1)
	{
		if (s[i] == 'v' && s[i + 1] == 'v')
		{
			tot++;
		}
	}
	FOR(i, 0, SZ(s) - 1)
	{
		if (s[i] == 'v' && s[i + 1] == 'v')
		{
			cur++;
		}
		if (s[i] == 'o')
		{
			ans += cur * (tot - cur);
		}
	}
	cout << ans << '\n';
	//you are looking for "vv" -> o "vv" subsequences?
	return 0;
}