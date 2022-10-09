#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
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
int n, m, k;
int pref[2000100];
int tab[maxn];
PII shop[maxn];
const int MX = 2000000;

bool check(int sr)
{
	int wsk = 0;
	FOR(i, 0, MX) pref[i] = 0;
	FOR(i, 1, n) pref[tab[i]]++;
	FOR(i, 1, sr) pref[shop[m - i + 1].e1]++;
	pref[MX + 1] = inf;
	FOR(days, 0, MX)
	{
		FOR(kk, 1, k)
		{
			while (pref[wsk] == 0) ++wsk;
			pref[wsk]--;
			while (pref[wsk] == 0) ++wsk;
			if (wsk == MX + 1) return 1;
		}
		if (wsk <= days) return 0;
	}
	return 1;
}
inline int readint() {
	int x = 0; char zn;
	while (1) {
		zn = getchar();
		if (isspace(zn)) return x;
		x = (x << 1) + (x << 3) + zn - '0';
	}
}

int main()
{
	boost;
	cin >> n >> m >> k;
	FOR(i, 1, n) {
		cin >> tab[i];
		tab[i] = min(tab[i], MX + 1);
	}
	FOR(i, 1, m) 
	{
		cin >> shop[i].e1;
		shop[i].e1 = min(shop[i].e1, MX + 1);
		shop[i].e2 = i;
	}
	
	sort(shop+1, shop+m+1);
	if (!check(0)) OUT(-1);
	int x = 0, y = m;
	while (x < y)
	{
		int sr = ((x + y) >> 1) + 1;
		if (!check(sr)) y = --sr;
		else x = sr;
	}
	cout << x << "\n";
	FOR(i, 1, x) cout << shop[m - i + 1].e2 << ' ';
}