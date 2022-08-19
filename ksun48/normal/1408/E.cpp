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
	int m, n;
	cin >> m >> n;
	using ll = long long;
	vector<ll> a(m), b(n);
	for(ll& x : a) cin >> x;
	for(ll& x : b) cin >> x;
	vector<pair<int,int> > d;
	for(int i = 0; i < m; i++){
		int r;
		cin >> r;
		for(int j = 0; j < r; j++){
			int s;
			cin >> s;
			s--;
			d.push_back({i, s});
		}
	}
	sort(d.begin(), d.end(), [&](pair<int,int> f, pair<int,int> g){
		return a[f.first] + b[f.second] > a[g.first] + b[g.second];
	});
	UF uf(m+n);
	ll ans = 0;
	for(pair<int,int> f : d){
		if(!uf.join(f.first, m+f.second)){
			ans += a[f.first] + b[f.second];
		}
	}
	cout << ans << '\n';
}