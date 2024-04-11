#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
int n, m, a, b, c, d;
int t[maxn];
string s[2];
int main()
{
	boost;
	cin >> s[0] >> s[1];
	cin >> n;
	cout << s[0] << ' ' << s[1] << "\n";
	FOR(step, 1, n)
	{
		string w, p;
		cin >> w >> p;
		if (s[0] == w) s[0] = p;
		else s[1] = p;
		cout << s[0] << ' ' << s[1] << "\n";
	}
}