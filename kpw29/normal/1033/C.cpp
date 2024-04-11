#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1020000;

string s1, s2, s;
int n, m, k;

vector <PII> moves;
int tab[maxn];
PII help[maxn];
int nim[maxn];
int stan[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
		help[i] = mp(tab[i], i);
	}
	sort(help+1, help+n+1);
	
	for (int i=n; i>0; --i) {
		int pos = help[i].e2;
		for (int j = pos; j <= n; j += tab[pos])
			if (tab[j] > tab[pos]) stan[nim[j]] = i;
			
		for (int j = pos; j > 0; j -= tab[pos])
			if (tab[j] > tab[pos]) stan[nim[j]] = i;
			
		int iter = 0;
		while (stan[iter] == i) ++iter;
		nim[pos] = iter;
	}
	
	FOR(i, 1, n)
		if (nim[i]) cout << "A";
		else cout << "B";
}