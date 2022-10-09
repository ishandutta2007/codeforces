#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef unsigned long long int ll;
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
#define maxn 1500100

int PI[maxn], tab[maxn], n;
int t[maxn];
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &tab[i + n + 1]);
	for (int i=1; i<=n; ++i) scanf("%d", &tab[i]);
	tab[n + 1] = -1;
	int dl = n + n + 1, DL = 0;

	for (int i=1; i<=dl; ++i)
	  if (tab[i] != 0) t[++DL] = tab[i];
	  
	for (int i=n+2; i<=dl; ++i)
	  if (tab[i] != 0) t[++DL] = tab[i];
	--n;
	PI[0] = PI[1] = 0;
	int b = 0;
	for (int i=2; i<=DL; ++i)
	{
		while (b > 0 && t[b + 1] != t[i]) b = PI[b];
		if (t[b + 1] == t[i]) ++b;
		PI[i] = b;
		if (PI[i] == n && i > n) OUT("YES");
	}
	OUT("NO");
}