#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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

const int maxn = 100100;
ll pot[maxn];

ll LEN[10], VAL[10];
char znak[maxn];
string change[maxn];
string from;
string init;

inline ll potmod(ll a, ll b, ll M)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = (res * a) % M;
		b /= 2;
		a = (a * a)%M;
	}
	return res;
}

int main()
{
	pot[0] = 1;
	for (int i=1; i<maxn; ++i) pot[i] = pot[i-1] * 10LL % mod;
	FOR(i, 0, 9) LEN[i] = 1, VAL[i] = i;
	
	cin >> init;
	int n = init.length(), q;
	cin >> q;
	for (int z=1; z<=q; ++z)
	{
		string st;
		cin >> st;
		znak[z] = st[0];
		for (int j=3; j<(int)st.length(); ++j) change[z] += st[j];
	}

	for (int z=q; z>0; --z)
	{
		ll NL[10], NVAL[10];
		int value = znak[z] - '0';
		FOR(i, 0, 9) {
			if (i == value) {
				NL[i] = NVAL[i] = 0;
			}
			else NL[i] = LEN[i], NVAL[i] = VAL[i];
		}
		
		ll len = 0, res = 0;
		//key thing - len gets moduloed by mod - 1!!!
		int m = change[z].length();
		for (int i=0; i<m; ++i) {
			res = (res * potmod(10, LEN[change[z][i] - '0'], mod) + VAL[change[z][i] - '0']) % mod;
			len = (len + LEN[change[z][i] - '0']) % (mod - 1);
		}
		
		FOR(i, 0, 9) LEN[i] = NL[i], VAL[i] = NVAL[i];
		LEN[value] = len;
		VAL[value] = res;
	}
	
	ll len = 0, res = 0;
	for (int i=0; i<n; ++i) {
		res = (res * potmod(10, LEN[init[i] - '0'], mod) + VAL[init[i] - '0']) % mod;
		len = (len + LEN[init[i] - '0']) % (mod - 1);
		//cout << res << ' ' << len << endl;
	}

	cout << res;
}