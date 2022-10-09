#include <bits/stdc++.h>
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
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 110

ll LCM;
int jest[maxn], n;
int t[maxn];

bool odw[maxn];


int main() {
	cin >> n;
	LCM = 1;
	FOR(i, 1, n) {
		cin >> t[i];
		jest[t[i]] = 1;
	}
	FOR(i, 1, n)
	  if (!jest[i]) OUT(-1);
	
	FOR(i, 1, n)
	  if (!odw[i]) {
		  int DL = 0, j = i;
		  do {
			  odw[j] = 1;
			  j = t[j];
			  DL++;
		  }while (!odw[j]);

		  if (DL % 2 == 0) DL /= 2;
		  ll dziel = __gcd(LCM, (ll)DL);
		  LCM /= dziel;
		  LCM *= DL;
	  }
	
	cout << LCM;
}