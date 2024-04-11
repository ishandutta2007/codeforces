#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
//#define FOR(i, a, b) for ((int)(i) = (a); i <= (b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000010

int n, m, a, b, c, k;
int t[maxn];
string s;

int main() {
	boost;
	cin >> n >> k;
	cin >> s;
	for (int i=0; i<n; ++i)
	  if (s[i] == 'a') t[i + 1] = 0;
	  else t[i + 1] = 1;
	  
	if (k == 0) {
		int R = 0, w = 0;
		t[0] = -1;
		for (int i=1; i<=n; ++i) {
		  if (t[i] == t[i-1]) ++R;
		  else R = 1;
		  w = max(w, R);
	  }
	  OUT(w);
	}
	t[n + 1] = inf;
	int wyn = 0, j = 0;
	int result = 0;
	for (int i=1; i<=n; ++i) {
		while (wyn <= k) ++j, wyn += t[j];
		wyn -= t[j], --j;
		result = max(result, j - i + 1);
		wyn -= t[i];
	}
	
	j = 0, wyn = 0;
	for (int i=1; i<=n; ++i) t[i] = (1 - t[i]);
	for (int i=1; i<=n; ++i) {
		while (wyn <= k) ++j, wyn += t[j];
		wyn -= t[j], --j;
		result = max(result, j - i + 1);
		wyn -= t[i];
	}
	
	cout << result << endl;
}