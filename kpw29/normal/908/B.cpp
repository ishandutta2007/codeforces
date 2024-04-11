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
const int maxn = 2010;
int n, m, k, a, b, c;
int tab[maxn];

char s[maxn][maxn];

PII dir[5];
int help[4];
PII start, wyj;
string moves;
int HELP[1000];
int rozwal()
{
	PII akt = start;
	if (akt == wyj) return 1;
	FOR(i, 0, (int)moves.size() - 1) {
		if (s[akt.e1][akt.e2] == '#') return 0;
		int c = help[HELP[moves[i]]];
		akt.e1 += dir[c].e1; akt.e2 += dir[c].e2;
		if (akt == wyj) return 1;
		if (s[akt.e1][akt.e2] == '#') return 0;
	}
	return 0;
}
int main()
{
	HELP['0'] = 0; HELP['1'] = 1; HELP['2'] = 2; HELP['3'] = 3;
	boost;
	cin >> n >> m;
	FOR(i, 0, n+1)
		FOR(j, 0, m+1) s[i][j] = '#';
	
	FOR(i, 1, n) {
		string xd;
		cin >> xd;
		FOR(j, 1, m) s[i][j] = xd[j - 1];
	}
	cin >> moves;
	start = mp(0, 0); wyj = mp(0, 0);
	FOR(i, 1, n)
		FOR(j, 1, m)
			if (s[i][j] == 'S') start = mp(i, j);
			else if (s[i][j] == 'E') wyj = mp(i, j);
	
	dir[0] = mp(0, 1); dir[1] = mp(0, -1); dir[2] = mp(1, 0); dir[3] = mp(-1, 0);
	FOR(i, 0, 3) help[i] = i;
	int wyn = 0;
	do
	{
		wyn += rozwal();
	}while (next_permutation(help, help+4));
	cout << wyn;
}