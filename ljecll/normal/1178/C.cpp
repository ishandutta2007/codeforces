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
#define INF 998244353
#define LLINF 2696969696969696969ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

ll N, M;
ll expo(ll a, ll e)
{
	if (e == 0) return 1;
	if (e & 1) return expo(a * a % INF, e >> 1) * a % INF;
	return expo(a * a % INF, e >> 1);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	cout << expo(2, N + M) << '\n';
	return 0;
}