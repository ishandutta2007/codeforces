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
#define MAXN 300013
#define LLINF 2696969696969696969

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC, N;
ll A, B;
bitset<MAXN> flag;
pll dp;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	while(TC--)
	{
		cin >> N >> A >> B; //pipeline, pillar
		string temps; cin >> temps;
		FOR(i, 0, N)
		{
			flag[i] = (temps[i] == '1');
		}
		dp = {B, LLINF};
		FOR(i, 0, N)
		{
			if (flag[i])
			{
				dp = {LLINF, dp.se + A + 2 * B};
			}
			else
			{
				dp = {min(dp.fi + A + B, dp.se + 2 * A + B), min(dp.se + A + 2 * B, dp.fi + 2 * A + 2 * B)};
			}
		}
		cout << dp.fi << '\n';
	}
	return 0;
}