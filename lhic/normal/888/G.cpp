#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MAXN = 200100;
const int MX = MAXN * 31;

int a[MAXN];
int go[MX][2];
int mx[MX];
int cc = 1;

ll gans = 0;

int newn() {
	return cc++;
}

int get(int x, int b) {
	int now = 0;
	int ans = 0;
	for (int i = 29; i >= 0; --i) {
		int g = (x >> i) & 1;
		if (go[now][g] && mx[go[now][g]] >= b)
			now = go[now][g];
		else
			now = go[now][1 - g], ans += (1 << i);
	}
	return ans;
}

void add(int x, int p) {
	int now = 0;
	for (int i = 29; i >= 0; --i) {
		mx[now] = max(mx[now], p);
		int g = (x >> i) & 1;
		if (go[now][g])
			now = go[now][g];
		else
			now = go[now][g] = newn();
	}
	mx[now] = max(mx[now], p);
}

void run(int l, int r, int k) {
	if (l + 1 >= r || k < 0)
		return;
	int mid = l;
	while (mid < r && !((a[mid] >> k) & 1))
		++mid;
	run(l, mid, k - 1);
	run(mid, r, k - 1);
	if (mid == l || mid == r)
		return;
	int ans = (1 << 30) + 100;
	for (int i = l; i < mid; ++i)
		ans = min(ans, get(a[i], mid));
	gans += ans;
}
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		add(a[i], i);
	run(0, n, 29);
	cout << gans << "\n";
	return 0;
}