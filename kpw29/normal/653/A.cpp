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
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
const int inf = 2e9+9091203;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int BASE=10000;
int n, m, b,a, c, k;
#define maxn 2000100
int tab[maxn];

int main()
{
	boost;
	cin >> n;
	for (int i=1; i<=n; ++i)
	{
		cin >> a;
		tab[a]++;
	}
	for (int i=1; i<maxn; ++i)
	{
		if (tab[i] && tab[i-1] && tab[i+1]) OUT("YES");
	}
	OUT("NO");
}