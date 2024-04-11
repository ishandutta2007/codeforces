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
const int maxn = 1000100;
int n, m, k, c;
int tab[maxn];
bool pal[210][210];
map <int, int> M;

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n)
	{
		int a, val;
		cin >> a >> val;
		M[a] = val;
	}
	
	cin >> n;
	FOR(i, 1, n)
	{
		int a, val;
		cin >> a >> val;
		M[a] = max(M[a], val);
	}
	
	ll res = 0;
	for (auto u : M) res += u.e2;
	cout << res;
}