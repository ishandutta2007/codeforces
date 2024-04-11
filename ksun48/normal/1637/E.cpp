#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = int64_t;
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	map<int,int> afreq;
	for(int x : a) afreq[x]++;
	map<int, vector<int> > freq_which;
	for(auto [k, f] : afreq){
		freq_which[f].push_back(k);
	}
	vector<int> freqs;
	for(auto& [f, v] : freq_which){
		freqs.push_back(f);
		sort(v.rbegin(), v.rend());
	}
	set<pair<int,int> > bad;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		bad.insert({u, v});
		bad.insert({v, u});
	}
	ll best = 0;
	for(int f1 : freqs){
		auto& v = freq_which[f1];
		int k = (int)v.size();
		for(int i = 0; i < k; i++){
			for(int j = 0; j < i; j++){
				int r = v[i];
				int s = v[j];
				if(ll(r + s) * ll(f1 + f1) <= best) break;
				if(bad.count({r, s})) continue;
				best = max(best, ll(r + s) * ll(f1 + f1));
			}
		}
	}
	sort(freqs.begin(), freqs.end());
	for(int f1 : freqs){
		for(int f2 : freqs){
			if(f2 >= f1) break;
			auto& v1 = freq_which[f1];
			auto& v2 = freq_which[f2];
			if(ll(v1[0] + v2[0]) * ll(f1 + f2) <= best) continue;
			for(int i = 0; i < v1.size(); i++){
				int r = v1[i];
				if(ll(r + v2[0]) * ll(f1 + f2) <= best) break;
				for(int j = 0; j < v2.size(); j++){
					int s = v2[j];
					if(ll(r + s) * ll(f1 + f2) <= best) break;
					if(bad.count({r, s})) continue;
					best = max(best, ll(r + s) * ll(f1 + f2));
				}
			}
		}
	}
	cout << best << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}