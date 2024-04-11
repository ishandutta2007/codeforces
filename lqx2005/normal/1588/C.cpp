#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int n;
ll a[N];
struct node {
	int stk[N], top;
	ll tag;
	void init(int n) {top = tag = 0; }
	void insert(int i) {
		while(top && a[stk[top]] > a[i]) top--;
		stk[++top] = i;
	}
	void addtag(ll x) {
		tag += x;
	}

	int ask() {
		int p = lower_bound(stk + 1, stk + top + 1, - tag, [&](int x, ll y) {
			return a[x] < y;
		}) - stk;
		return stk[p - 1] - 1;
	}

	int query(int r) {
		int ed = lower_bound(stk + 1, stk + top + 1, r, [&](int x, int y) {
			return x > y;
		}) - stk;
		int be = lower_bound(stk + 1, stk + top + 1, - tag, [&](int x, ll y) {
			return a[x] <= y;
		}) - stk;
		be--;
		if(a[stk[be]] + tag != 0) return 0;
		return max(be - ed + 1, 0);
	}
}s[2];
void solve() {
	scanf("%d", &n);
	s[0].init(n), s[1].init(n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	a[n + 1] = -oo;
	s[0].insert(n + 1), s[1].insert(n + 1);
	ll ans = 0;
	for(int i = n; i >= 1; i--) {
		ll x = a[i];
		a[i] = - s[i & 1].tag;
		s[i & 1].insert(i);
		s[i & 1].addtag(x);
		s[(i & 1) ^ 1].addtag(-x);
		int r = min(s[0].ask(), s[1].ask());
		ans += s[0].query(r) + s[1].query(r);
	}
	printf("%lld\n", ans);
	return;
}

int main() {
	int T;
	for(cin >> T; T--; solve());
	return 0;
}