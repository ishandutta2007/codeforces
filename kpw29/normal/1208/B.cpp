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
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
const int inf = 1e9+9;
const int mod = 998244353;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int n, m, a, b, c;
const int maxn = 1000100;
int tab[maxn];
map <int, int> ILE;

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	FOR(j, 1, n) ILE[tab[j]]++;
	int zle = 0;
	for (auto u : ILE)
		if (u.e2 > 1) ++zle;
	
	if (zle == 0) OUT(0);
	
	int wyn = n + 1;
	FOR(i, 1, n) {
		ILE.clear();
		int wa = 0;
		FOR(j, 1, n) ILE[tab[j]]++;
		
		FOR(j, i, n) {
			if (ILE[tab[j]] == 2) ++wa;
			ILE[tab[j]]--;
			if (wa == zle) wyn = min(wyn, j - i + 1);
		}
	}
	cout << wyn;
}