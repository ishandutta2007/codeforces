#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct UF{
    int n;
    vector<int> par;
    UF(int n) : n(n) {
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

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> x(k);
	for(int i = 0; i < k; i++){
		cin >> x[i];
		x[i]--;
	}
	vector<pair<int, pair<int,int> > > e;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		e.push_back({w, {u,v}});
	}
	sort(e.begin(), e.end());
	int ans = 0;
	UF uf(n);
	int idx = 0;
	for(auto r : e){
		while(idx < k && uf.find(x[0]) == uf.find(x[idx])) idx++;
		if(idx == k) break;
		int s = r.second.first;
		int t = r.second.second;
		if(uf.find(s) != uf.find(t)){
			ans = r.first;
			uf.join(s, t);
		}
	}
	for(int i = 0; i < k; i++){
		cout << ans << ' ';
	}
	cout << '\n';
}