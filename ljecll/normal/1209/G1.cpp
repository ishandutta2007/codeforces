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
#define MAXN 200013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, Q;
int arr[MAXN];
int freq[MAXN];
int rm[MAXN];
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	FOR(i, 0, N)
	{
		cin >> arr[i];
		freq[arr[i]]++;
		rm[arr[i]] = i;
	}
	int rt = 0, mx = 0, sz = 0;
	FOR(i, 0, N)
	{
		sz++;
		ckmax(mx, freq[arr[i]]);
		ckmax(rt, rm[arr[i]]);
		if (rt == i)
		{
			ans += (sz - mx);
			rt = i + 1;
			mx = 0;
			sz = 0;
			//solve!
		}
	}
	cout << ans << '\n';
	return 0;
}