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
#define MAXN 113

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
pii arr[MAXN];
bitset<MAXN> beg;
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	string temps; cin >> temps;
	FOR(i, 0, N)
	{
		beg[i] = (temps[i] == '1');
	}
	FOR(i, 0, N)
	{
		cin >> arr[i].fi >> arr[i].se;
	}
	FOR(i, 0, 481)
	{
		//a[i] and b[i] b[i] + k(a[i]) is when it toggles
		FOR(j, 0, N)
		{
			int f = arr[j].fi, s = arr[j].se;
			if (i >= s && i % f == s % f)
			{
				beg[j] = beg[j] ^ 1;
			}
		}
		ckmax(ans, beg.count());
	}
	cout << ans << '\n';
}