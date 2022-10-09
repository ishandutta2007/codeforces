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
const int maxn = 1000100;
int n, q, m;
int value[25];

int odp[1 << 13], ile[1 << 13];

int pref[1 << 12][101];

int main()
{
	boost; cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	FOR(j, 0, 1 << n) odp[j] = -1;
	
	FOR(j, 0, n-1) cin >> value[j];
	FOR(i, 1, m) {
		string tmp;
		cin >> tmp;
		int liczba = 0;
		FOR(j, 0, n-1) liczba += (1 << j) * (tmp[j] - '0');
		ile[liczba]++;
	}

	int pot = (1 << n);
	FOR(j, 0, pot-1) {
		FOR(i, 0, pot-1) {
			if (!ile[i]) continue;
			int tmp_score = 0;
			FOR(k, 0, n -1)
				if ((j & (1 << k)) == (i & (1 << k))) tmp_score += value[k];
			
			if (tmp_score <= 100) pref[j][tmp_score] += ile[i];
		}
		
		FOR(i, 1, 100) pref[j][i] += pref[j][i-1];
	}
	
	FOR(i, 1, q) {
		string tmp;
		int kk;
		cin >> tmp >> kk;
		int liczba = 0;
		FOR(j, 0, n-1) liczba += (1 << j) * (tmp[j] - '0');
		cout << pref[liczba][kk] << "\n";
	}
}