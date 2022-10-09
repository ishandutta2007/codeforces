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
int PI[maxn], cnt[maxn];

void countPI(int n)
{
	int b = 0;
	PI[0] = PI[1] = 0;
	for (int i=2; i<=n; ++i)
	{
	  while (b && s[i] != s[b + 1]) b = PI[b];
	  if (s[b + 1] == s[i]) ++b;
	  PI[i] = b;
	  if (i != n) cnt[PI[i]]++;
    }
}

int main()
{
	scanf("%s", s + 1);
	n = 1;
	while (s[n]) ++n; --n;
	countPI(n);
	int p = PI[n];
	while (p > 0)
	{
		if (cnt[p] > 0) {
			for (int i=1; i<=p; ++i) printf("%c", s[i]);
			exit(0);
		}
		else p = PI[p];
	}
	OUT("Just a legend");
}