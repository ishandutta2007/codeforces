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

const int M = 1010101;

vector<vector<int> > pf;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	pf.assign(M, {});
	for(int p = 2; p < M; p++){
		if(pf[p].empty()){
			for(int x = p; x < M; x += p){
				pf[x].push_back(p);
			}			
		}
	}
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	UF uf(M + n);
	for(int i = 0; i < n; i++){
		for(int p : pf[a[i]]){
			uf.join(p, M+i);
		}
	}
	vector<set<int> > joins(M+n);
	for(int x : a){
		vector<int> cc;
		for(int y = x; y <= x+1; y++){
			for(int p : pf[y]){
				cc.push_back(uf.find(p));
			}
		}
		for(int r : cc){
			for(int s : cc){
				joins[r].insert(s);
				joins[s].insert(r);
			}
		}
	}
	for(int _ = 0; _ < q; _++){
		int s, t;
		cin >> s >> t;
		s--; t--;
		int c1 = uf.find(M+s);
		int c2 = uf.find(M+t);
		if(c1 == c2){
			cout << 0 << '\n';
		} else if(joins[c1].count(c2)){
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}