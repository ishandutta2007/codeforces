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
	int n, m1, m2;
	cin >> n;
	cin >> m1 >> m2;
	UF uf1(n), uf2(n);
	for(int i = 0; i < m1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf1.join(a, b);
	}
	for(int i = 0; i < m2; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf2.join(a, b);
	}
	vector<pair<int,int> > added;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(uf1.find(i) != uf1.find(j) && uf2.find(i) != uf2.find(j)){
				uf1.join(i, j);
				uf2.join(i, j);
				added.push_back({i, j});
			}
		}
	}
	cout << added.size() << '\n';
	for(auto [a, b] : added){
		cout << (a+1) << ' ' << (b+1) << '\n';
	}
}