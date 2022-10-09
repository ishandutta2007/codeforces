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
const int mod = 998244353;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 301000;
int A[maxn], B[maxn];
int match[maxn], n, m;

void solve()
{
	cin >> n >> m;
	int N = 3 * n;
	FOR(i, 1, N) match[i] = 0;
	int range = 0;
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		if (!match[a] && !match[b] && range < n)
		{
			match[a] = b;
			match[b] = a;
			++range;
		}
		
		A[i] = a; B[i] = b;
	}
	
	if (range >= n) {
		cout << "Matching\n";
		FOR(i, 1, m)
			if (match[A[i]] == B[i] && match[B[i]] == A[i]) cout << i << ' ';
		
		cout << "\n";
	}
	
	else {
		cout << "IndSet\n";
		int value = 0;
		FOR(i, 1, N)
			if (value < n && !match[i]) ++value, cout << i << ' ';
		
		cout << "\n";
	}
}

int main()
{
	int T;
	boost;
	cin >> T;
	FOR(z, 1, T) solve();
}