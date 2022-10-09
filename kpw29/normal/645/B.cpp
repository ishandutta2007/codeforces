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
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int BASE=10000;
int n, m, b, c, k;
#define maxn 100100
int goal[5];
int dr[maxn], tab[maxn];
void add(int p) {
	for (; p < maxn; p += p & (-p)) dr[p]++;
}
int get(int p) {
	int ret = 0;
	for (; p > 0; p -= p & (-p)) ret += dr[p];
	return ret;
}
int main()
{
	/*char a;
	int tab[5], DL = 0;
	for (int i=1; i<=2; ++i)
	  for (int j=1; j<=2; ++j) scanf(" %c", &a), tab[++DL] = a;
	  DL = 0;
	for (int i=1; i<=2; ++i)
	  for (int j=1; j<=2; ++j) scanf(" %c", &a), goal[++DL] = a;
	int posx1 = 0, posx2 = 0;
	for (int i=1; i<=4; ++i)
	  if (tab[i] == 'X') posx1 = i;
	for (int i=1; i<=4; ++i)
	  if (goal[i] == 'X') posx2 = i;
	*
	OUT("NO");*/
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; ++i) tab[i] = i;
	k = min(k, n / 2);
	for (int i=1; i<=k; ++i) swap(tab[i], tab[n-i+1]);
	ll N = n;
	ll wyn = N * (N-1)/2;
	for (int i=1; i<=n; ++i) {
		wyn -= get(tab[i]);
		add(tab[i]);
	}
	cout << wyn;
	
}