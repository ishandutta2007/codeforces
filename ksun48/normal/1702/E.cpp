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

void solve(){
	int n;
	cin >> n;
	vector<int> deg(n);
	UF uf(n);
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		deg[a]++;
		deg[b]++;
		uf.join(a, b);
	}
	bool works = true;
	for(int x : deg) if(x > 2) works = false;
	vector<int> sz(n);
	vector<int> d2(n);
	for(int i = 0; i < n; i++){
		sz[uf.find(i)]++;
		if(deg[i] == 2){
			d2[uf.find(i)]++;
		}
	}
	for(int i = 0; i < n; i++){
		if(d2[i] == sz[i] && (d2[i] & 1)) works = false;
	}
	cout << (works ? "YES" : "NO") << '\n';

}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}