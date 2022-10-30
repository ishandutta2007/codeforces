# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define all(a) a.begin(),a.end()
#define For(i, l, r) for(int i = l; i <= r; ++i)
#define rep(i, n) For(i, 0, n-1)
#define pb push_back

const int maxn = 100000 + 10;
inline void rd(int &x) { scanf("%d", &x); }

vector<int> vv[maxn];
vector<int> cc[maxn];

struct Query {
	int u, v, w;
} qi[maxn];

int get(const vector<int> &vec,int x) {
	const int n = vec.size();
	int ret = 0;
	for(int i = x; i; i -= i & -i) 
		ret = max(ret, vec[i-1]);
	return ret;
}

void add(vector<int> &vec,int x,int v) {
	const int n = vec.size();
	for(int i = x; i <= n; i += i & -i) 
		vec[i - 1] = max(vec[i - 1], v);
}

int main() {
	int n, m; rd(n); rd(m);
	rep(i, m) {
		int u, v, w;
		rd(u); rd(v); rd(w);
		qi[i] = (Query){u, v, w};
		vv[v].pb(w);
	}
	For(i, 1, n) {
		sort(all(vv[i]));
		vv[i].resize(unique(all(vv[i])) - vv[i].begin());
		cc[i].resize(vv[i].size());
	}
	int ans = 0;
	rep(i, m) {
		int u = qi[i].u;
		int k = lower_bound(all(vv[u]), qi[i].w) - vv[u].begin();
		int val = 1 + get(cc[u], k);
		ans = max(ans, val);
		int v = qi[i].v;
		int p = lower_bound(all(vv[v]), qi[i].w) - vv[v].begin();
		add(cc[v], p + 1, val);
	}
	cout << ans << endl;
}