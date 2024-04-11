#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, m;
char In[25][25], ans[55][55];
int idx[25][25], ci, ce, rem[25][25];
pii EP[1010], E[1010], ri[1010];
int pp[1010]; int Find(int x) { return pp[x] == x ? x : pp[x] = Find(pp[x]); }
int use[1010], crem[25][25], X1[1010], X2[1010];

vector <int> gr[1210];
void add(int x) {
	use[x] = 1; ans[EP[x].Fi][EP[x].Se] = ' ';
	crem[ri[x].Fi][ri[x].Se]++;
	int a = E[x].Fi, b = E[x].Se;
	gr[a].pb(b); gr[b].pb(a);
	pp[Find(a)] = Find(b);
}
void dfs(int x, int px) {
	pp[x] = pp[px];
	for(int e : gr[x]) if(e != px) dfs(e, x);
}

void del(int x) {
	use[x] = 0; ans[EP[x].Fi][EP[x].Se] = 'O';
	crem[ri[x].Fi][ri[x].Se]--;
	int a = E[x].Fi, b = E[x].Se;
	gr[a].erase(find(all(gr[a]), b));
	gr[b].erase(find(all(gr[b]), a));
	pp[b] = -1; pp[a] = a; dfs(a, a);
	if(pp[b] == -1) { pp[b] = b; dfs(b, b); }
}

int Ins() {
	for(int i=1;i<=ce;i++) X1[i] = X2[i] = 0;
	for(int i=1;i<=ce;i++) {
		int x, y; tie(x, y) = ri[i];
		if(rem[x][y] > crem[x][y]) X2[i] = 1;
	}
	vector <int> q;
	char vis[1010] = {};
	int pre[1010] = {};
	memset(pre, -1, sizeof pre);
	auto Fix = [&](int x) {
		for(int t=x;t!=-1;t=pre[t]) {
			if(use[t]) del(t);
			else add(t);
		}
	};
	auto add_q = [&](int x, int p) {
		if(vis[x]) return 0;
		vis[x] = 1; pre[x] = p;
		q.pb(x);
		if(X2[x]) {
			Fix(x);
			return 1;
		}
		return 0;
	};
	for(int i=1;i<=ce;i++) {
		int x, y; tie(x, y) = E[i];
		if(Find(x) != Find(y)) {
			if(add_q(i, -1)) return 1;
		}
	}
	rep(i, szz(q)) {
		int t = q[i];
		if(use[t] == 0) {
			int x, y; tie(x, y) = ri[t];
			if(crem[x][y] == rem[x][y]) {
				for(int a=1;a<=ce;a++) if(ri[a] == ri[t] && add_q(a, t)) return 1;
			}
			else {
				for(int a=1;a<=ce;a++) if(use[a] && add_q(a, t)) return 1;
			}
		}
		else {
			del(t);
			vector <int> can;
			for(int a=1;a<=ce;a++) {
				int x = Find(E[a].Fi), y = Find(E[a].Se);
				if(x != y) can.pb(a);
			}
			add(t);
			for(int e : can) if(add_q(e, t)) return 1;
		}
	}
	return 0;
}

int Do() {
	for(int i=1;i<=ce;i++) use[i] = 0;
	memset(crem, 0, sizeof crem);
	int res = 0;
	while(Ins()) ++res;
	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%s", In[i] + 1);
	rep(i, 2*n+1) rep(j, 2*m+1) ans[i][j] = ' ';
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		ans[2*i-1][2*j-1] = In[i][j];
		if(i < n && In[i][j] == 'O' && In[i+1][j] == 'O') ans[2*i][2*j-1] = 'O';
		if(j < m && In[i][j] == 'O' && In[i][j+1] == 'O') ans[2*i-1][2*j] = 'O';
	}
	auto output = [&](int x) {
		puts(x ? "YES" : "NO");
		if(x) {
			for(int i=1;i<2*n;i++, puts("")) for(int j=1;j<2*m;j++) printf("%c", ans[i][j]);
		}
	};

	memset(idx, 0, sizeof idx);
	ci = (n-1)*(m-1), ce = 0;
	rep(i, ci+1) pp[i] = i;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		int x = (i-1) * (m-1) + j;
		if(j < m && (In[i][j] != 'O' || In[i][j+1] != 'O')) {
			int y = (i == 1 ? 0 : x - (m-1));
			int z = (i == n ? 0 : x);
			pp[Find(z)] = Find(y);
		}
		if(i < n && (In[i][j] != 'O' || In[i+1][j] != 'O')) {
			int y = (j == 1 ? 0 : x - 1);
			int z = (j == m ? 0 : x);
			pp[Find(z)] = Find(y);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		int x = (i-1) * (m-1) + j;
		if(j < m && (In[i][j] == 'O' && In[i][j+1] == 'O')) {
			int y = (i == 1 ? 0 : x - (m-1));
			int z = (i == n ? 0 : x);
			EP[++ce] = {2*i-1, 2*j};
			E[ce] = {Find(z), Find(y)};
			ri[ce] = {i, j + ((i + j) & 1)};
		}
		if(i < n && (In[i][j] == 'O' && In[i+1][j] == 'O')) {
			int y = (j == 1 ? 0 : x - 1);
			int z = (j == m ? 0 : x);
			EP[++ce] = {2*i, 2*j-1};
			E[ce] = {Find(z), Find(y)};
			ri[ce] = {i + ((i + j) & 1), j};
		}
	}
	int xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1}, ok = 1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		if(((i+j) & 1) || In[i][j] != 'O') continue;
		int c = 0;
		rep(d, 4) {
			int ni = i + xx[d], nj = j + yy[d];
			if(1 <= ni && ni <= n && 1 <= nj && nj <= m && In[ni][nj] == 'O') ++c;
		}
		rem[i][j] = c - 2;
		if((i > 1 || j > 1) && c <= 1) ok = 0;
	}
	rem[1][1] = 4;
	if(!ok) {
		output(0);
		return;
	}
	Do();
	ok = 1;
	for(int i=0;i<=ci;i++) if(Find(i) != Find(0)) ok = 0;
	output(ok);
	for(int i=0;i<=ci;i++) gr[i].clear();
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}