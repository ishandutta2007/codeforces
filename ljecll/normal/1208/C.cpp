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
#define MAXN 1013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
int ans[MAXN][MAXN];
vi nums;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N * N / 4)
	{
		nums.PB(4 * i);
	}
	FOR(i, 0, N / 2)
	{
		FOR(j, 0, N / 2)
		{
			ans[i][j] = nums.back();
			nums.pop_back();
			ans[i + N / 2][j] = ans[i][j] ^ 1;
			ans[i][j + N / 2] = ans[i][j] ^ 2;
			ans[i + N / 2][j + N / 2] = ans[i][j] ^ 3;
		}
	}
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}