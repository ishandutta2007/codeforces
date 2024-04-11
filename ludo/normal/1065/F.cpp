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

const int maxn = 1e6 + 100;

int N, K, H[maxn], A[maxn];
vi E[maxn];

// binary hopping of 2^i

vvi comps;
vi tidx, lnk, cnr, st;
vector<bool> vis;
int age, ncomps;

void tarjan(int v) {
	tidx[v] = lnk[v] = ++age; vis[v] = true; st.pb(v);
	for (int w : E[v]) {
		if (!tidx[w]) tarjan(w), lnk[v] = min(lnk[v], lnk[w]);
		else if (vis[w]) lnk[v] = min(lnk[v], tidx[w]);
	}
	if (lnk[v] != tidx[v]) return;
	comps.pb(vi());
	int w;
	do {
		vis[w = st.back()] = false; cnr[w] = ncomps; comps.back().pb(w);
		st.pop_back();
	} while (w != v);
	ncomps++;
}

void findSCC(int n) {
	age = ncomps = 0; vis.assign(n, false); tidx.assign(n, 0);
	lnk.resize(n); cnr.resize(n); comps.clear();
	for (int i = 0; i < n; i++)
		if (tidx[i] == 0) tarjan(i);
}

vi dfsStack;

void dfs(int v)
{
	A[v] = (int) dfsStack.size() < K ? 0 : dfsStack[dfsStack.size() - K];
	dfsStack.pb(v);
	for (int u : E[v]) {
		H[u + 1] = H[v] + 1;
		dfs(u);
	}
	dfsStack.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i < N; i++) {
		int x;
		cin >> x;
		E[x - 1].pb(i);
	}

	H[0] = 0;
	dfs(0);

	vi leaves;
	REP(i, N) {
		if (E[i].empty()) {
			leaves.pb(i);
			E[i].pb(A[i]);
		}
	}

	findSCC(N);

	// find DAG
vi nleafs;
vi sumleaves;

	nleafs = vi(ncomps, 0);
	sumleaves = vi(ncomps, 0);
	for (int v : leaves) nleafs[cnr[v]]++;

	set<ii> indE;
	vvi indEE(ncomps);
	vi indeg(ncomps, 0);
	REP(i, N) for (int j : E[i]) {
		ii pr(cnr[i], cnr[j]);
		if (cnr[i] != cnr[j] && indE.find(pr) == indE.end()) {
			indE.emplace(cnr[i], cnr[j]);
			indEE[cnr[j]].eb(cnr[i]);
			indeg[cnr[i]]++;
		}
	}

	vector<bool> vis2(ncomps, false);

	queue<int> q;
	REP(i, ncomps) if (indeg[i] == 0) {
		sumleaves[i] = nleafs[i]; // terminal node
		q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		vis2[cur] = true;
		q.pop();
		for (int nxt : indEE[cur]) {
			sumleaves[nxt] = max(sumleaves[nxt], nleafs[nxt] + sumleaves[cur]);
			if (--indeg[nxt] == 0) q.push(nxt);
		}
	}
	REP(i, ncomps) assert(vis2[i]);

	cout << sumleaves[cnr[0]] << endl;

	return 0;
}