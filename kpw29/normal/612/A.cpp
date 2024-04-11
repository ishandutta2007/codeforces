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
int n, m, k, a, b, c, p, q;
ll wyn = 0;
int tab[maxn];
char s[maxn];
int main()
{
	cin >> n >> p  >> q;
	scanf("%s", s + 1);
	for (int i=0; i<=100; ++i)
	  for (int j=0; j<=100; ++j)
	  {
		  if (i * p + j * q  == n)
		  {
			  cout << i + j << endl;
			  for (int k=0; k<n; ++k)
			  {
				  cout << s[k+1];
				  if (k < i * p)
				  {
					  if (k % p == p-1) cout << endl;
				  }
				  else
				  {
					  int help = k - i * p;
					  if (help % q == q-1) cout << endl;
				  }
			  }
			  exit(0);
		  }
	  }
	puts("-1");
	  
}