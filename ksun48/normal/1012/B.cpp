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
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	UF uf(n + m);
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf.join(a, b + n);
	}
	int ncc = 0;
	for(int i = 0; i < n + m; i++){
		if(uf.find(i) == i){
			ncc++;
		}
	}
	cout << ncc - 1 << endl;
}