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
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 50;
int tab[51][51];
bool usedX[51];

int f[maxn + 5];
vector <int> col;
vector <int> help[55];

int find(int x)
{
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

int main()
{
	boost;
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n-1) {
		string s;
		cin >> s;
		FOR(j, 0, m-1) {
			if (s[j] == '.') tab[i][j + 1]=  0;
			else tab[i][j + 1] = 1;
		}
	}
	
	FOR(i, 1, m) f[i] = i;
	
	FOR(i, 0, n-1) {
		vector <int> lacz;
		
		FOR(j, 1, m)
			if (tab[i][j]) lacz.pb(j);
		
		for (int j=0; j + 1 < (int)lacz.size(); ++j)
			f[find(lacz[j])] = find(lacz[j + 1]);
	}
	
	bool ans = 1;
	FOR(j, 1, m) {
		vector <int> tmp;
		FOR(i, 0, n-1) tmp.pb(tab[i][j]);
		help[j] = tmp;
	}
	
	FOR(i, 1, m)
		FOR(j, i + 1, m)
			if (find(i) == find(j) && help[i] != help[j]) ans = 0;
	
	if (ans) cout << "Yes";
	else cout << "No";
}