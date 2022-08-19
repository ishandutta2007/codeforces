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
    void join(int a, int b){
        par[find(a)] = find(b);
    }
};

void solve(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	a--; b--;
	UF ufa(n), ufb(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		if(u != a && v != a) ufa.join(u, v);
		if(u != b && v != b) ufb.join(u, v);
	}
	int ca = 0;
	int cb = 0;
	for(int i = 0; i < n; i++){
		if(i != a && ufa.find(i) != ufa.find(b)) ca++;
		if(i != b && ufb.find(i) != ufb.find(a)) cb++;
	}
	cout << 1ll * ca * cb << '\n';
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}