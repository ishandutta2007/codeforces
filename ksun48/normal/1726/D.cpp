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
	int N, M;
	cin >> N >> M;
	vector<pair<int,int> > e(M);
	for(auto& x : e){
		cin >> x.first >> x.second;
		x.first--;
		x.second--;
	}
	UF uf(N);
	string res(M, '0');
	vector<int> extra_ids;
	for(int i = 0; i < M; i++){
		auto [u, v] = e[i];
		if(!uf.join(u, v)){
			res[i] = '1';
			extra_ids.push_back(i);
		}
	}
	UF extra_uf(N);
	bool works = true;
	for(auto i : extra_ids){
		auto [u, v] = e[i];
		if(!extra_uf.join(u, v)) works = false;
	}
	if(!works){
		UF uf2(N);
		res = string(M, '0');
		res[extra_ids[1]] = '1';
		res[extra_ids[2]] = '1';
		{
			auto [u, v] = e[extra_ids[0]];
			uf2.join(u, v);
		}
		for(int i = 0; i < N; i++){
			if(i == extra_ids[1] || i == extra_ids[2] || i == extra_ids[0]) continue;
			auto [u, v] = e[i];
			if(!uf2.join(u, v)) res[i] = '1';
		}
	}
	cout << res << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}