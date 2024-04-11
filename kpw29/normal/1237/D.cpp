#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); }
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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 301000;
string s;

int n;
int st[maxn], DL = 0;
int pos[maxn];
int info[maxn];
int tab[maxn];

int UPD[maxn];
int res[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
		tab[n + i] = tab[i];
		tab[n + n + i] = tab[i];
	}
	
	st[++DL] = inf;
	
	FOR(i, 1, 3*n) {
		UPD[i] = 3 * n + 1;
		//cout << "Stack\n";
		//FOR(j, 1, DL) cout << st[j] << ' ';
		//cout << endl;
		while (st[DL] <= tab[i]) DL--;
		int x = 1, y = DL;
		//cout << "dec: " << tab[i] << endl;
		while (x < y) {
			int sr = (x + y) / 2 + 1;
			//cout << x << ' ' << y << ' ' << sr << ' ' << tab[i] << ' ' << st[sr] << endl;
			if (2 * tab[i] >= st[sr]) y = --sr;
			else x = sr;
		}
		
		if (x == 1) info[i] = -1;
		else info[i] = pos[x];
		
		st[++DL] = tab[i];
		pos[DL] = i;
		//cout << info[i] << ' ';
		if (info[i] != -1)
		 UPD[info[i]] = min(UPD[info[i]], i);
	}
	
	//cout << endl;
	//FOR(i, 1, 3 * n) cout << UPD[i] << ' ';
	//cout << endl;
	
	int MN = 3 * n + 1;
	for (int step = 3*n; step>0; --step) {
		MN = min(MN, UPD[step]);
		if (step <= n) {
			if (MN == 3 * n + 1) res[step] = -1;
			else res[step] = MN - step;
		}
	}
	
	FOR(i, 1, n) cout << res[i] << ' ';
}