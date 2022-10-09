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
const ll mod = 1e9+696969;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
string s;

ll pref[maxn], suf[maxn];
char tab[maxn];

int main()
{
	boost;
	cin >> s;
	int n = s.length();
	FOR(i, 1, n) tab[i] = s[i - 1];
	ll result = 0;
	for (int i=n; i>0; --i)
	{
		suf[i] = suf[i + 1];
		if (tab[i] == 'v' && tab[i + 1] == 'v') suf[i]++;
	}
	
	FOR(i, 1, n)
	{
		pref[i] = pref[i-1];
		if (tab[i] == 'v' && tab[i - 1] == 'v') pref[i]++;
		if (tab[i] == 'o') result += pref[i-1] * suf[i+1];
	}
	
	cout << result;
}