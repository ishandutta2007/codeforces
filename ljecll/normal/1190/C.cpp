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
#define MAXN 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, K;
bitset<MAXN> arr;
int pref[2][MAXN];
int f0, f1, l0, l1;

void draw()
{
	cout << "once again\n";
	exit(0);
}
void win1()
{
	cout << "tokitsukaze\n";
	exit(0);
}
void win2()
{
	cout << "quailty\n";
	exit(0);
}
int getrange(int v, int l, int r)
{
	if (l > r) return 0;
	return pref[v][r + 1] - pref[v][l];
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	string temps; cin >> temps;
	FOR(i, 0, N)
	{
		arr[i] = (temps[i] == '1');
		pref[0][i + 1] = pref[0][i] + (arr[i] == 0);
		pref[1][i + 1] = pref[1][i] + (arr[i] == 1);
	}
	//check if the first player has an immediate win!
	FOR(i, K - 1, N)
	{
		if (getrange(0, 0, i - K) + getrange(0, i + 1, N - 1) == (N - K))
		{
			win1();
		}
		if (getrange(1, 0, i - K) + getrange(1, i + 1, N - 1) == (N - K))
		{
			win1();
		}
	}
	FOR(i, 0, N)
	{
		if (arr[i] == 0) l0 = i;
		else l1 = i;
	}
	FORD(i, N, 0)
	{
		if (arr[i] == 0) l0 = i;
		else l1 = i;
	}
	if (N >= 2 * K + 1)
	{
		draw();
	}
	FOR(i, K - 1, N)
	{
		if (getrange(0, 0, i - K) == i - K + 1 || getrange(0, i + 1, N - 1) == N - i - 1) continue;
		draw();
	}
	FOR(i, K - 1, N)
	{
		if (getrange(1, 0, i - K) == i - K + 1 || getrange(1, i + 1, N - 1) == N - i - 1) continue;
		draw();
	}
	win2();
	return 0;
}