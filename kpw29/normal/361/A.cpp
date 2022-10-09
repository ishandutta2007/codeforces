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
typedef unsigned long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1010
int tab[maxn][maxn], place;
int n ,k;
int main()
{
	boost;
	cin >> n >> k;
	place = 0;
	int val = k - n + 1;
	FOR(i, 1, n)
	{
		++place;
		for (int j=1; j<=n; ++j)
			if (j == place) cout << val << ' ';
			else cout << 1 << ' ';
			cout << endl;
	}
}