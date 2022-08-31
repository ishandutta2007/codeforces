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
	int n, d;
	cin >> n >> d;
	UF uf(n);
	int extra = 0;
	for(int i = 1; i <= d; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		if(!uf.join(x, y)) extra++;
		vector<int> csz(n, 0);
		for(int j = 0; j < n; j++) csz[uf.find(j)] += 1;
		sort(csz.rbegin(), csz.rend());
		int ans = 0;
		for(int j = 0; j <= extra && j < n; j++) ans += csz[j];
		cout << (ans-1) << '\n';
	}
}