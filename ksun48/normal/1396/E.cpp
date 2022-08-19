#include <bits/stdc++.h>
using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

using ll = long long;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	ll k;
	cin >> n >> k;
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int centroid = -1;
	{
		y_combinator(
			[&](auto self, int v, int p) -> int {
				int sz = 1;
				for(int w : edges[v]){
					if(w == p) continue;
					sz += self(w, v);
				}
				if(centroid == -1 && sz * 2 >= n){
					centroid = v;
				}
				return sz;
			}
		)(0, -1);
	}
	vector<int> sz(n);
	y_combinator(
		[&](auto self, int v, int p) -> void {
			sz[v] = 1;
			for(int w : edges[v]){
				if(w == p) continue;
				self(w, v);
				sz[v] += sz[w];
			}
		}
	)(centroid, -1);
	ll maxsz = 0;
	ll minsz = 0;
	for(int i = 0; i < n; i++){
		if(i == centroid) continue;
		maxsz += sz[i];
		minsz += sz[i] & 1;
	}
	if(k < minsz || k > maxsz || (k - minsz) & 1){
		cout << "NO" << '\n';
		exit(0);
	}
	cout << "YES" << '\n';
	int s = 1;
	int e = n;
	while(s + 1 < e){
		int m = (s + e) / 2;
		ll val = 0;
		for(int i = 0; i < n; i++){
			if(i == centroid) continue;
			ll z = min(m, sz[i]);
			if((sz[i] - z) & 1) z--;
			val += z;
		}
		if(val >= k){
			e = m;
		} else {
			s = m;
		}
	}
	ll nval = 0;
	for(int i = 0; i < n; i++){
		if(i == centroid) continue;
		int z = min(e, sz[i]);
		if((sz[i] - z) & 1) z--;
		nval += z;
		sz[i] = z;
	}
	assert(nval >= k);
	for(int i = 0; i < n; i++){
		if(sz[i] == e && nval > k){
			nval -= 2;
			sz[i] -= 2;
		}
	}
	assert(nval == k);
	vector<pair<int,int> > ans;
	sz[centroid] = 0;

	vector<set<pair<int,int> >> stuff;
	auto combine = [&](int a, int b) -> int {
		if(stuff[a].size() < stuff[b].size()) swap(a, b);
		for(auto r : stuff[b]) stuff[a].insert(r);
		return a;
	};
	int T = 0;
	y_combinator(
		[&](auto self, int v, int p) -> int {
			int c = (int)stuff.size();
			stuff.push_back({});
			stuff[c].insert({T, v});
			T++;
			for(int w : edges[v]){
				if(w == p) continue;
				c = combine(c, self(w, v));
			}
			vector<int> fr, bk;
			while((int)stuff[c].size() > sz[v]){
				fr.push_back(stuff[c].begin()->second);
				stuff[c].erase(stuff[c].begin());
				bk.push_back(prev(stuff[c].end())->second);
				stuff[c].erase(prev(stuff[c].end()));
			}
			reverse(bk.begin(), bk.end());
			for(int i = 0; i < (int)fr.size(); i++){
				ans.push_back({fr[i], bk[i]});
			}
			return c;
		}
	)(centroid, -1);
	for(pair<int,int> r : ans){
		cout << r.first + 1 << ' ' << r.second + 1 << '\n';
	}
}