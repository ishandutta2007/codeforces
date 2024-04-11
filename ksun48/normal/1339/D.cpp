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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int,int> > edges;
	vector<int> deg(n);
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges.push_back({a, b});
		edges.push_back({b, a});
		deg[a]++;
		deg[b]++;
	}
	int minv = 1;
	UF uf(2*n);
	for(auto e : edges){
		uf.join(e.first, n + e.second);
	}
	int leaf = -1;
	for(int i = 0; i < n; i++){
		if(deg[i] == 1){
			if(leaf == -1) leaf = i;
			if(uf.find(i) != uf.find(leaf)) minv = 3;
		}
	}
	vector<bool> touch_leaf(n, false);
	int maxv = n-1;
	for(auto e : edges){
		if(deg[e.first] == 1){
			if(touch_leaf[e.second]){
				maxv--;
			} else {
				touch_leaf[e.second] = true;
			}
		}
	}
	cout << minv << ' ' << maxv << '\n';
}