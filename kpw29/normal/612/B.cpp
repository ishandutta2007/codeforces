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
int n, m, k, a, b, c;
ll wyn = 0;
int tab[maxn];
int main()
{
		boost;
		cin >> n;
		for (int i=1; i<=n; ++i) {
			cin >> a;
			tab[a] = i;
		}
		for (int i=2; i<=n; ++i) wyn += abs(tab[i] - tab[i-1]);
		cout << wyn;
}