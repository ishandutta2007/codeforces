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
int arr[MAXN];
vpi guys;
int up[MAXN], dn[MAXN];
bitset<MAXN> ans[MAXN];
bitset<MAXN> used;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> N;
	FOR(i, 0, N)
	{
		cin >> arr[i];
	}
	FOR(i, 0, N + 1)
	{
		up[i] = N;
		dn[i] = 0;
	}
	//can't we put some condition on these vectors.
	//you divide each set into two smaller subsets.
	//hm you want to make sure each time at least one subset doesn't all get the same nu mber.
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
		{
			//can you do a block j => j + 1.
			if (up[j] == j)
			{
				continue;
			}
			int szr = up[j + 1] - (j + 1) + 1;
			int szl = j - dn[j] + 1;
			// cerr << "SPLIT " << j << " -> " << j + 1 << endl;
			int lt = dn[j], rt = up[j + 1];
			// cerr << "MOVE " << lt << " -> " << rt << endl;
			// cerr << szr << ' ' << arr[i] << ' ' << szl << ' ' << N + 1 - arr[i] << endl;
			if (szr <= arr[i] && szl <= N + 1 - arr[i])
			{
				FOR(k, j + 1, rt + 1)
				{
					// cerr << "OK " << k << endl;
					ans[i][k] = 1;
				}
			}
			else if (szl <= arr[i] && szr <= N + 1 - arr[i])
			{
				FOR(k, lt, j + 1)
				{
					// cerr << "NO " << k << endl;
					ans[i][k] = 1;
				}
			}
			else
			{
				continue;
			}
			// cerr << "ROW " << i << " SPLIT " << j << endl;
			int rem = arr[i] - ans[i].count();
			// cerr << "REM " << rem << endl;
			FOR(k, 0, N + 1)
			{
				if (lt <= k && k <= rt) continue;
				if (rem)
				{
					rem--;
					ans[i][k] = 1;
				}
			}
			FOR(k, lt, j + 1)
			{
				up[k] = j;
			}
			FOR(k, j + 1, rt + 1)
			{
				dn[k] = j + 1;
			}
			break;
		}
	}
	FOR(i, 0, N + 1)
	{
		FOR(j, 0, N)
		{
			if (ans[j][i])
			{
				used[i] = true;
			}
		}
	}
	cout << used.count() << '\n';
	FOR(i, 0, N + 1)
	{
		if (!used[i]) continue;
		FOR(j, 0, N)
		{
			cout << ans[j][i];
		}
		cout << '\n';
	}
	return 0;
	//distinct bit vectors summing to these.
}