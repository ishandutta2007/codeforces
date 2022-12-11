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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC;
int N, K;
string str, goal;
vpi ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> TC;
	while(TC--)
	{
		cin >> N >> K >> str;
		ans.clear();
		goal = "";
		FOR(i, 0, K - 1)
		{
			goal += "()";
		}
		FOR(i, 0, (N - 2 * K + 2) / 2)
		{
			goal += "(";
		}
		FOR(i, 0, (N - 2 * K + 2) / 2)
		{
			goal += ")";
		}
		FOR(i, 0, N)
		{
			if (str[i] != goal[i])
			{
				//find any thing to put it in place.
				int idx = i + 1;
				while(str[idx] != goal[i]) idx++;
				ans.PB({i, idx});
				reverse(str.begin() + i, str.begin() + idx + 1);
			}
		}
		cout << SZ(ans) << '\n';
		for (pii p : ans)
		{
			cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
		}
	}
	return 0;
}