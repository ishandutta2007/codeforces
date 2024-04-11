#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 100;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
#define maxn 1010
int n, M;
string s[maxn];
int main()
{
	M = 6;
	boost;
	cin >> n;
	if (n == 1) OUT(6);
	for (int i=1; i<=n; ++i) cin >> s[i];
	for (int i=1; i<=n; ++i)
	  for (int j=i+1; j<=n; ++j)
	  {
		  int d = 0;
		  for (int k=0; k<6; ++k)
		    if (s[i][k] != s[j][k]) ++d;
		  M = min(M, (d - 1) /2 );
	  }
	cout << M;
}