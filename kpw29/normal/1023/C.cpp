#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for (int i=(a); i<=(b); ++i)
#define boost ios_base::sync_with_stdio(false);
#define OUT(x) {cout << x; exit(0); }
typedef pair <int, int> PII;
typedef long long ll;
typedef unsigned int ui;
const int mod = 1e9+7;

const int maxn = 1000100;
int tab[maxn], n, m, k;

int main()
{
	boost;
	cin >> n >> k;
	string s;
	cin >> s;
	string ret = "";
	int ans = 0, ss = 0;
	FOR(i, 0, n-1)
	{
		if (s[i] == '(' && ans != k) ans += 2, ++ss, ret += '(';
		else if (ss) ss --, ret += ')';
	}
	
	cout << ret;
}