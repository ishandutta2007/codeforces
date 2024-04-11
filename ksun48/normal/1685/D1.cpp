#include <bits/stdc++.h>
using namespace std;

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pair<int,int> > eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges);
	vector<pair<int,int> > ret, s = {{src, -1}};
	// D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x, eid;
		tie(x, eid) = s.back();
		int y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back({x, eid}); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

void solve(){
	int n;
	cin >> n;
	vector<int> _p(n);
	vector<int> jmp(n);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a--;
		_p[i] = a;
		jmp[a] = i;
	}
	vector<int> cid(n, -1);
	for(int i = 0; i < n; i++){
		if(cid[i] >= 0) continue;
		int c = i;
		while(true){
			cid[c] = i;
			c = jmp[c];
			if(c == i) break;
		}
	}
	UF uf(n);
	vector<vector<pii> > gr(n);
	int E = 0;
	for(int i = 0; i < n; i++){
		gr[i].push_back({jmp[i], E});
		E++;
	}
	for(int i = 0; i + 1 < n; i++){
		if(uf.join(cid[i], cid[i+1])){
			gr[i].push_back({i+1, E});
			E++;
			gr[i+1].push_back({i, E});
			E++;
		}
	}
	// cerr << (E - n) << '\n';
	vector<pii> et = eulerWalk(gr, E, 0);
	vector<int> ans;
	for(auto [v, e] : et){
		if(e < n && e >= 0){
			ans.push_back(jmp[e]);
		}
	}
	for(int x : ans){
		cout << (x+1) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}