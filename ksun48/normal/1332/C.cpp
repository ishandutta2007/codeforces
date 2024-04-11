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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	UF uf(n);
	for(int i = 0; i < n; i++){
		uf.join(i, n-1-i);
	}
	for(int i = 0; i + k < n; i++){
		uf.join(i, i+k);
	}
	vector<map<char, int> > q(n);
	for(int i = 0; i < n; i++){
		q[uf.find(i)][s[i]]++;
	}
	int ans = n;
	for(auto& r : q){
		int best = 0;
		for(auto f : r){
			best = max(best, f.second);
		}
		ans -= best;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}