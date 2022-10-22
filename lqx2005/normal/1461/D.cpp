#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double db;
const int N = 1e5 + 10;

int t, n, q, a[N], san[N], cnt[N], tot = 0;
ll sum[N];
set<ll> s;
void initsan(int n) {
	tot = 0;
	rep(i, 1, n) san[++tot] = a[i], cnt[tot] = 0;
	sort(san + 1, san + tot + 1);
	tot = unique(san + 1, san + tot + 1) - (san + 1);
	rep(i, 1, n) {
		int p = lower_bound(san + 1, san + tot + 1, a[i]) - (san);
		cnt[p]++; 
	}
	return;
}

void solve(int l, int r) {
	if(l > r) return;
	s.insert(sum[r] - sum[l - 1]);
	if(l == r) return;
	int mid = (san[l] + san[r]) / 2;
	int p = upper_bound(san + l, san + r + 1, mid) - san;
	p--;
	solve(l, p), solve(p + 1, r);
	return;
} 

int main() {
	scanf("%d", &t);
	rep(amo, 1, t) {
		s.clear();
		scanf("%d%d", &n, &q);
		rep(i, 1, n) scanf("%d", &a[i]);
		initsan(n);
		rep(i, 1, tot) sum[i] = sum[i - 1] + 1ll * cnt[i] * san[i];
		solve(1, tot);
		ll S;
		rep(C, 1, q) {
			scanf("%lld", &S);
			if(s.count(S)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}