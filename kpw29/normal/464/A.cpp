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

const int maxn = 1000100;
int n, p;
string s;

int main()
{
	boost;
	cin >> n >> p;
	cin >> s;
	if (p == 1) OUT("NO");
	if (p == 2)
	{
		if (n > 2) OUT("NO");
		if (n == 2 && s == "ab") OUT("ba");
		if (n == 2 && s == "ba") OUT("NO");
		if (n == 1)
		{
			if (s == "a") OUT("b");
			OUT("NO");
		}
	}
	
	//p is at least 3
	for (int i=n-1; i>=0; --i)
	{
		int which = s[i] - 'a' + 1;
		int sm = 1;
		while (which + sm <= p && (s[i] + sm == s[i-1] || s[i] + sm == s[i-2])) ++sm;
		if (sm + which > p) continue;
		s[i] += sm;
		for (int j=i+1; j<n; ++j)
		{
			char val = 'a';
			if (s[j-1] == val || s[j-2] == val) ++val;
			if (s[j-1] == val || s[j-2] == val) ++val;
			if (s[j-1] == val || s[j-2] == val) ++val;
			s[j] = val;
		}
		cout << s;
		exit(0);
	}
	
	cout << "NO";
}