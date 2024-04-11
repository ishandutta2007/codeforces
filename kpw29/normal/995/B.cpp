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
int pos[2][105], n;

int main()
{
	boost;
	cin >> n;
	int res = 0;
	FOR(i, 1, 2*n) {
		int a;
		cin >> a;
		if (pos[0][a] == 0) pos[0][a] = i;
		else pos[1][a] = i;
	}
	
	FOR(i, 1, n)
		FOR(j, 1, n) {
			if (i == j) continue;
			if (pos[0][i] > pos[0][j]) continue;
			if (pos[0][i] < pos[0][j] && pos[0][j] < pos[1][i] && pos[1][i] < pos[1][j]) ++res;
			else if (pos[0][i] < pos[0][j] && pos[1][j] < pos[1][i]) res += 2;
		}
	
	cout << res;
}