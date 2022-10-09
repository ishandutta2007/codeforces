#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1000000;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;
int n, m, a, b, c, k;
int tab[maxn];
PII help[maxn];
bool odw[maxn];
int pos[maxn];

vector <vector <int> > ret;

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
		help[i] = mp(tab[i], i);
	}
	

	sort(help+1, help+n+1);
	FOR(i, 1, n) tab[help[i].e2] = i;
	FOR(i, 1, n) pos[tab[i]] = i;

	vector <int> cycle;
	FOR(i, 1, n) {
		if (!odw[i]) {
			cycle.clear();
			int j = i;
			while (!odw[j]) {
				cycle.pb(j);
				odw[j] = 1;
				j = tab[j];
			}
			ret.pb(cycle);
		}
	}
	
	cout << (int)ret.size () << endl;
	for (int i=0; i<ret.size(); ++i) {
		int sz = ret[i].size();
		cout << sz << ' ';
		for (auto u : ret[i]) cout << u << ' ';
		cout << "\n";
	}
	
}