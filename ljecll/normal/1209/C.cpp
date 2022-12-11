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

int TC, N;
int arr[MAXN];
int ans[MAXN];
vi ord;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		string temps; cin >> temps; N = SZ(temps);
		FOR(i, 0, N)
		{
			arr[i] = (temps[i] - '0');
		}
		bool ok = false;
		FOR(i, 0, 10)
		{
			//everything <i gets color i. everythign >i gets color 2. everything i can get split appropriately.
			ord.clear();
			ok = true;
			bool seen = false;
			FOR(j, 0, N)
			{
				if (arr[j] < i)
				{
					ans[j] = 1;
				}
				else if (arr[j] > i)
				{
					ans[j] = 2;
					seen = true;
				}
				else
				{
					ans[j] = (seen ? 1 : 2);
				}
			}
			FOR(j, 0, N)
			{
				if (ans[j] == 1) ord.PB(arr[j]);
			}
			FOR(j, 0, N)
			{
				if (ans[j] == 2) ord.PB(arr[j]);
			}
			FOR(j, 0, N - 1)
			{
				if (ord[j] > ord[j + 1]) ok = false;
			}
			if (ok)
			{
				FOR(i, 0, N)
				{
					cout << ans[i];
				}
				cout << '\n';
				break;
			}
		}
		if (!ok)
		{
			cout << "-\n";
		}
	}
}