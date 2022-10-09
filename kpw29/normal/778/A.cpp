#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
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
#define maxn 1000100
int n, m, k, a, b, c;
int t[maxn], block[maxn];
string s, p;

bool check(int k)
{
	FOR(i, 0, n-1) block[i] = 0;
	FOR(i, 1, k) block[t[i] - 1] = 1;
	int st = 0;
	for (int i=0; i<p.size(); ++i)
	{
		while (st < n &&( block[st] || s[st] != p[i])) ++st;
		if (st >= n) return 0;
		++st;
	}
	return 1;
}
int main()
{
	boost;
	cin >> s >> p;
	int x = 0, y = (int)s.length();
	n = y;
	FOR(i, 1, y) cin >> t[i];
	
	while (x < y)
	{
		//cout << x << ' ' << y << endl;
		int sr = (x + y)/2 + 1;
		if (!check(sr)) y = sr - 1;
		else x = sr;
	}
	cout << x;
}