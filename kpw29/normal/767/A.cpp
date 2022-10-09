#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef pair <us, us> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, us> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int W = 1e9;
#define maxn 1000100
int n, m, b, c;
ll wyn;
string s;
int tab[maxn];
set <int> q, nowe;

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		q.insert(-i);
		cin >> tab[i];
	}
	bool ust = 0;
	FOR(i, 1, n) {
		int a = tab[i];
		q.erase(-a);
		nowe.insert(-a);
		while (!q.empty() && !nowe.empty())
		{
			int x = -(*nowe.begin()), y = -(*q.begin());
			if (x > y)
			{
				nowe.erase(nowe.begin());
				cout << x << ' ';
			}
			else break;
		}
		if (q.empty() && !ust)
		{
			ust = 1;
			for (auto u : nowe) cout << -u << ' ';
		}
		cout << "\n";
	}
}