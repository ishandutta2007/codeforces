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

bool check(int x)
{
	int nww = (x / 6); //tyle miejsca na nww
	int trzy = (x / 3) - nww;
	int dwa = (x / 2) - nww;
	if ((trzy + dwa + nww >= n + m) && (trzy + nww >= m) && (dwa + nww >= n)) return 1;
	return 0;
}

int binsearch(int x, int y)
{
	while (x < y)
	{
		int sr = ((x + y) >> 1);
		if (check(sr) == false) x = sr + 1;
		else y = sr;
	}
	return x;
}

int main()
{
	scanf("%d%d", &n, &m);
	int wyn = binsearch(0, 10 * (n + m));
	cout << wyn;
}