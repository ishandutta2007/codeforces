#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, a;
int wyn[maxn], t[maxn];
char p[4];
char s[maxn];
int main()
{
	p[0] = 'B';
	p[1] = 'G';
	p[2] = 'R';
	scanf("%d", &n);
	scanf("%s", s + 1);
	if (n == 1) OUT(s[1]);
	for (int i=1; i<=n; ++i)
	{
		if (s[i] == 'B') t[0]++;
		if (s[i] == 'G') t[1]++;
		if (s[i] == 'R') t[2]++;
	}
	int sum = n;
	for (int j=0; j<3; ++j)
	{
		bool dobrze = 1;
		if (t[j] == 0)
		{
			if (t[0] == sum || t[1] == sum || t[2] == sum) dobrze = 0;
		}
		else
		{
			if ((sum - t[j]) == 1) dobrze = 0;
		}
		if (dobrze) cout << p[j];
	}
	
}