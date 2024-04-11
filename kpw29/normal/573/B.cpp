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
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int l[maxn], r[maxn], t[maxn];
int n, m;
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &t[i]);
	int MIN = 0;
	for (int i=1; i<=n; ++i) {
		if (t[i] - i < MIN) MIN = t[i] - i;
		l[i] = i + MIN;
	}

	MIN = n+1;
	int w = -1;
	for (int i=n; i>0; --i) {
		if (t[i] + i < MIN) MIN = t[i] + i;
		r[i] = min(l[i], MIN - i);
		w = max(w, r[i]);
	}
	cout << w;
}