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
#define maxn 1010100

int mi[maxn], wi[maxn], n, m, x, y, a, b, t[maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &t[i]);
		if (t[i - 1] >= t[i]) wi[i] = wi[i-1];
		else wi[i] = i;
		if (t[i - 1] <= t[i]) mi[i] = mi[i-1];
		else mi[i] = i;
		wi[1] = mi[1] = 0;
	}
	for (int i=1; i<=m; ++i) {
		scanf("%d%d", &a, &b);
		if (b - a <= 1) puts("Yes");
		else {
			int el = wi[b];
			if (mi[el] <= a) puts("Yes");
			else puts("No");
		}
	}
}