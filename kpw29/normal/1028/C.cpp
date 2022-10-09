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
const int maxn = 200100;
PP tab[maxn];
int n;
PP pref[maxn], suf[maxn];

void ok(PP tmp)
{
	if (tmp.e1.e1 <= tmp.e1.e2 && tmp.e2.e1 <= tmp.e2.e2)
	{
		cout << tmp.e1.e1 << ' ' << tmp.e2.e1;
		exit(0);
	}
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> tab[i].e1.e1 >> tab[i].e2.e1 >> tab[i].e1.e2 >> tab[i].e2.e2;
	pref[1] = tab[1];
	FOR(i, 2, n)
	{
		pref[i].e1.e1 = max(pref[i-1].e1.e1, tab[i].e1.e1);
		pref[i].e1.e2 = min(pref[i-1].e1.e2, tab[i].e1.e2);
		pref[i].e2.e1 = max(pref[i-1].e2.e1, tab[i].e2.e1);
		pref[i].e2.e2 = min(pref[i-1].e2.e2, tab[i].e2.e2);
	}
	
	suf[n] = tab[n];
	for (int i=n-1; i>0; --i)
	{
		suf[i].e1.e1 = max(suf[i+1].e1.e1, tab[i].e1.e1);
		suf[i].e1.e2 = min(suf[i+1].e1.e2, tab[i].e1.e2);
		suf[i].e2.e1 = max(suf[i+1].e2.e1, tab[i].e2.e1);
		suf[i].e2.e2 = min(suf[i+1].e2.e2, tab[i].e2.e2);
	}
	
	ok(pref[n]);
	ok(pref[n-1]);
	ok(suf[2]);
	
	for (int i=1; i+2<=n; ++i)
	{
		PP tmp = suf[i + 2];
		tmp.e1.e1 = max(tmp.e1.e1, pref[i].e1.e1);
		tmp.e1.e2 = min(tmp.e1.e2, pref[i].e1.e2);
		tmp.e2.e1 = max(tmp.e2.e1, pref[i].e2.e1);
		tmp.e2.e2 = min(tmp.e2.e2, pref[i].e2.e2);
		ok(tmp);
	}
}