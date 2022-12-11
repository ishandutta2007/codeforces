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

int N;
vi ans;
int x;
int tot, sum;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N)
	{
		int y; cin >> y;
		tot += y;
		if (i == 0)
		{
			x = y;
		}
		if (i == 0 || y * 2 <= x)
		{
			ans.PB(i);
			sum += y;
		}
	}
	if (sum * 2 <= tot)
	{
		cout << "0\n";
		return 0;
	}
	cout << SZ(ans) << '\n';
	for (int x : ans)
	{
		cout << x + 1 << ' ';
	}
	cout << '\n';
	return 0;
}