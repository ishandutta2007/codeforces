#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
const int maxn = 1000100;
int n, k, m;
int jest[27], ile = 0;
bool bylo[27];
int main()
{
	FOR(i, 0, 25) jest[i] = 1;
	ile = 26;
	boost;
	cin >> n;
	int shots = 0;
	FOR(i, 1, n) {
		char ope;
		cin >> ope;
		if (ope != '?') {
		string s;
		cin >> s;
		FOR(j, 0, 25) bylo[j] = 0;
		for (int j=0; j<s.size(); ++j) bylo[s[j] - 'a'] = 1;
		if (ope == '!') {
			if (ile == 1) ++shots;
			FOR(j, 0, 25)
				if (!bylo[j] && jest[j]) jest[j] = 0, --ile;
		}
		if (ope == '.') {
			FOR(j, 0, 25)
				if (bylo[j] && jest[j]) jest[j] = 0, --ile;
		}
		}
		else {
			char z;
			cin >> z;
			if (ile == 1) ++shots;
			if (ile > 1) {
				if (jest[z - 'a']) jest[z - 'a'] = 0, --ile;
			}
			else {
				if (jest[z - 'a']) --shots;
			}
			
		}
	}
	
	cout << shots;
}