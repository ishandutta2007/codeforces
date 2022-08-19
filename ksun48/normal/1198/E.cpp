#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> xa(m), xb(m), ya(m), yb(m);
	set<int> xv, yv;
	for(int i = 0; i < m; i++){
		cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
		xa[i]--; ya[i]--;
		xv.insert(xa[i]);
		xv.insert(xb[i]);
		yv.insert(ya[i]);
		yv.insert(yb[i]);
	}
	xv.insert(0);
	xv.insert(n);
	yv.insert(0);
	yv.insert(n);
	vector<int> xl, yl;
	for(int x : xv){
		xl.push_back(x);
	}
	for(int y : yv){
		yl.push_back(y);
	}
	int a = (int)xl.size() - 1;
	int b = (int)yl.size() - 1;

	PushRelabel flow(a + b + 2);
	for(int i = 0; i < a; i++){
		flow.add_edge(a+b, i, xl[i+1] - xl[i]);
	}
	for(int i = 0; i < b; i++){
		flow.add_edge(i+a, a+b+1, yl[i+1] - yl[i]);
	}
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			bool needs = false;
			for(int c = 0; c < m; c++){
				if(xl[i+1] <= xa[c] || xb[c] <= xl[i]) continue;
				if(yl[j+1] <= ya[c] || yb[c] <= yl[j]) continue;
				needs = true;
			}
			if(needs){
				flow.add_edge(i, j+a, 1e16);
			}
		}
	}
	cout << flow.maxflow(a+b, a+b+1) << '\n';
}