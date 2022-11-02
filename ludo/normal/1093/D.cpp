#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 998244353;
const int maxn = 3e5 + 1;

int p2[maxn];

int run()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vvi E(n);
	REP(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		E[a].pb(b); E[b].pb(a);
	}

	ll ret = 1;
	int na = 0, nb = 0;
	vector<bool> seen(n, false), col(n);
	REP(i, n) {
		if (seen[i]) continue;

		int ca = 1, cb = 0;
		col[i] = 0;
		seen[i] = true;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int nxt : E[cur]) {
				if (seen[nxt]) {
					if (col[nxt] == col[cur]) return 0;
				} else {
					seen[nxt] = true;
					col[nxt] = !col[cur];
					if (col[nxt]) cb++;
					else ca++;
					q.push(nxt);
				}
			}
		}
		na += max(ca, cb);
		nb += min(ca, cb);

		ll prod = p2[ca] + p2[cb];
		if (prod >= mod) prod -= mod;

		// cerr << ca << " " << cb 
		ret = (ret * prod) % mod;
	}
	assert(na + nb == n);
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	p2[0] = 1;
	for (int i = 1; i < maxn; i++) {
		p2[i] = p2[i - 1] + p2[i - 1];
		if (p2[i] >= mod) p2[i] -= mod;
	}
	
	int n;
	scanf("%d", &n);
	while(n--) { int ans = run(); printf("%d\n", ans); }
	return 0;
}