#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
const int maxn = 1e6 + 5;
int tab[maxn], n, k, m, a, b, c;
int par[maxn], LAST;
int par2[maxn];

int main()
{
	boost;
	cin >> n;
	bool ok = 0;
	FOR(i, 0, n) {
		cin >> a;
		tab[i] = a;
		if (i > 1 && tab[i] > 1 && tab[i-1] > 1) {
			ok = 1;
		}
	}
	assert(tab[0] == 1);
	if (!ok) OUT("perfect");
	int all = 1;
	FOR(i, 1, n) {
		FOR(j, all + 1, all + tab[i]) par[j] = all;
		all += tab[i];
	}
	
	all = 1;
	FOR(i, 1, n) {
		if (tab[i] == 1 || tab[i-1] == 1) {
			FOR(j, all + 1, all + tab[i]) par2[j] = all;
			all += tab[i];
		}
		else {
			par2[all + 1] = all - 1;
			FOR(j, all + 2, all + tab[i]) par2[j] = all;
			all += tab[i];
		}
	}
	
	cout << "ambiguous\n";
	FOR(i, 1, all) cout << par[i] << ' ';
	cout << endl;
	FOR(i, 1, all) cout << par2[i] << ' ';
	
}