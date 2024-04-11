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
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int mod = 1e8;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
char s[maxn];
int n, m;
vector <int> P[maxn];
ll one[maxn], wyn = 0;

int main()
{
	scanf("%s", s + 1);
	n = 1;
	while (s[n]) ++n; --n;
	s[0] = '$'; s[n + 1] = '#';
	for (int i=1; i<=n; ++i)
	{
		int k = 0;
		while (s[i - k] == s[i + k]) ++k; --k;
		for (int j=0; j<=k; ++j) P[i+j].pb(i-j);
		k = 0;
		while (s[i - k] == s[i + k + 1]) ++k; --k;
		for (int j=0; j<=k; ++j) P[i + j + 1].pb(i-j);
	}
	
	for (int i=1; i<=n; ++i) one[i] += P[i].size(), one[i] += one[i-1];
	for (int i=1; i<=n; ++i)
	  for (int j=0; j<P[i].size(); ++j) wyn += one[P[i][j] - 1];
	  
	cout << wyn; 
	
}