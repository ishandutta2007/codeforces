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
const int maxn = 1000100;
int n, m, k, a, b, c;

ll score[maxn];

int main()
{
	boost;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	ll zz = 0, zj = 0, jj = 0, jz = 0;
	FOR(i, 0, n-1)
	{
		if (s1[i] == '0' && s2[i] == '0') ++zz;
		if (s1[i] == '0' && s2[i] == '1') ++zj;
		if (s1[i] == '1' && s2[i] == '0') ++jz;
		if (s1[i] == '1' && s2[i] == '1') ++jj;
	}

	cout << zz * (jj + jz) + jz * zj;
}