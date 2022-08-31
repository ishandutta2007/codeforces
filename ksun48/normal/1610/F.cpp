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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> u(m), v(m), w(m);
	for(int i = 0; i < m; i++){
		cin >> u[i] >> v[i] >> w[i];
		u[i]--; v[i]--;
	}
	vector<vector<set<int> > > e(2, vector<set<int>>(n));
	for(int i = 0; i < m; i++){
		e[w[i]-1][u[i]].insert(i);
		e[w[i]-1][v[i]].insert(i);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(e[0][i].size() % 2 == 1) ans ++;
	}
	cout << ans << '\n';
	vector<int> ori(m, 0);
	vector<int> used(m, 0);
	vector<vector<pair<int,int> > > nadj(n);
	vector<vector<int> > paths;
	vector<vector<int> > pverts;
	for(int st = 0; st < m; st++){
		if(used[st]) continue;
		int type = w[st]-1;
		int a = u[st];
		int b = v[st];
		vector<int> verts = {a, b};
		vector<int> edges = {st};
		used[st] = 1;
		e[type][a].erase(st);
		e[type][b].erase(st);
		for(int j = 0; j < 2; j++){
			while(!e[type][verts.back()].empty()){
				int x = *e[type][verts.back()].begin();
				assert(e[type][u[x]].count(x));
				assert(e[type][v[x]].count(x));
				used[x] = 1;
				e[type][u[x]].erase(x);
				e[type][v[x]].erase(x);
				verts.push_back(u[x] ^ v[x] ^ verts.back());
				edges.push_back(x);
			}
			reverse(verts.begin(), verts.end());
			reverse(edges.begin(), edges.end());
		}
		if(verts.begin() == verts.end()){
			for(int z = 0; z < (int)edges.size(); z++){
				int ze = edges[z];
				if(u[ze] == verts[z]){
					ori[ze] = 0;
				} else if(v[ze] == verts[z]){
					ori[ze] = 1;
				} else assert(false);
			}
		} else {
			int k = (int)paths.size();
			paths.push_back(edges);
			pverts.push_back(verts);
			nadj[verts.front()].push_back({verts.back(), k});
			nadj[verts.back()].push_back({verts.front(), k});
		}
	}
	vector<int> done(paths.size(), 0);
	for(int i = 0; i < (int)paths.size(); i++){
		if(done[i]) continue;
		int st = pverts[i].front();
		int en = pverts[i].back();
		vector<tuple<int,int,int, int > > dirs;
		dirs.push_back({st, en, 0, i});
		done[i] = 1;
		auto go = y_combinator(
			[&](auto self, int v, int dir) -> void {
				for(auto [w, pid] : nadj[v]){
					if(done[pid]) continue;
					dirs.push_back({v, w, dir, pid});
					done[pid] = 1;
					self(w, dir);
				}
			}
		);
		go(st, 1);
		go(en, 0);
		for(auto [a, b, dir, pid] : dirs){
			if(dir) swap(a, b);
			vector<int>& edges = paths[pid];
			vector<int>& verts = pverts[pid];
			if(verts.front() != a){
				reverse(verts.begin(), verts.end());
				reverse(edges.begin(), edges.end());
			}
			for(int z = 0; z < (int)edges.size(); z++){
				int ze = edges[z];
				if(u[ze] == verts[z]){
					ori[ze] = 0;
				} else if(v[ze] == verts[z]){
					ori[ze] = 1;
				} else assert(false);
			}
		}
	}
	for(int x : ori){
		cout << (x+1);
	}
	cout << '\n';
}