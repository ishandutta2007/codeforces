#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;

int n,m,k,a,b,c;
#define maxn 1000100
int main()
{
	string s;
	boost;
	cin >> s;
	int n = s.size();
	int last = -1;
	int wyn = 1;
	FOR(i, 0, n-1) {
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'Y' || s[i] == 'O' || s[i] == 'U' || s[i] == 'I') {
			wyn = max(wyn, i - last);
			last = i;
		}
	}
	wyn = max(wyn, n - last);
	cout << wyn;
}