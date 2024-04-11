#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
const int inf = 2e9+9091203;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int BASE=10000;
int n, m, b,a, c, k;
#define maxn 2000100
int tab[maxn];
string s1[maxn];
char s[maxn];

map <string, int> odw;

void dfs(string x) {
	if (odw[x]) return;
	odw[x] = 1;
	if ((int)x.length() == n) return;
	for (int i=1; i<=m; ++i) {
		if (s[i] == x[0]) {
			string nev = s1[i];
			for (ui j=1; j<x.size(); ++j) nev += x[j];
			dfs(nev);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i=1; i<=m; ++i) cin >> s1[i] >> s[i];
	dfs("a");
	int wyn = 0;
	for (auto it : odw)
	  if (it.e1.length() == n) ++wyn;
	cout << wyn;
}