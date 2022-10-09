#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
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
#define maxn 10010
const double EPS = 1e-7;
double DP[maxn][1010];
int n, k;
int zap;
int main()
{
	cin >> k >> zap;
	DP[0][0] = 2000.0;
	FOR(i, 1, 10000)
	{
		FOR(j, 1, k) DP[i][j] = DP[i-1][j] * j / k + DP[i-1][j-1] * (k - j + 1)/k;
	}
	
	while (zap--)
	{
		double pi;
		cin >> pi;
		int wal = n;
		while (DP[wal][k] < pi + EPS) ++wal;
		cout << wal << endl;
	}
}