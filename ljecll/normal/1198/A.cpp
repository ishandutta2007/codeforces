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
#define MAXN 400013
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, I, K;
int arr[MAXN];
int freq[MAXN], pref[MAXN];
vi compress;
int ans = INF;

int range(int l, int r)
{
	return pref[r + 1] - pref[l];
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> I;
	I *= 8; I /= N;
	FOR(i, 0, N) cin >> arr[i];
	if (I >= 20)
	{
		cout << "0\n";
		return 0;
	}
	FOR(i, 0, N)
	{
		compress.PB(arr[i]);
	}
	sort(ALL(compress));
	compress.erase(unique(ALL(compress)), compress.end());
	K = SZ(compress);
	FOR(i, 0, N)
	{
		arr[i] = LB(ALL(compress), arr[i]) - compress.begin();
		freq[arr[i]]++;
	}
	if (K <= (1 << I))
	{
		cout << "0\n";
		return 0;
	}
	FOR(i, 0, K)
	{
		pref[i + 1] = pref[i] + freq[i];
	}
	FOR(i, 0, K - (1 << I) + 1)
	{
		ckmin(ans, N - range(i, i + (1 << I) - 1));
	}
	cout << ans << '\n';
	return 0;
}