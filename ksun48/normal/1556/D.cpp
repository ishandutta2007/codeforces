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
	int n, k;
	cin >> n >> k;
	k--;
	vector<pair<int,int> > edges(n-1);
	for(int i = 0; i < n-1; i++){
		edges[i] = {i, i+1};
	}
	edges.push_back({0, 2});
	vector<pair<int,int> > forest;
	UF uf(n);
	UF uf2(2*n);
	vector<vector<int> > fedges(n);
	for(auto [a, b] : edges){
		if(uf.join(a, b)){
			uf2.join(a, b+n);
			uf2.join(b, a+n);
			fedges[a].push_back(b);
			fedges[b].push_back(a);
		}
	}
	for(int i = 0; i < n; i++) assert(uf2.find(i) != uf2.find(i+n));
	vector<pair<int,int> > extras;
	for(auto [a, b] : edges){
		if(uf2.join(a, b+n)){
			extras.push_back({a, b});
		}
	}
	for(int i = 0; i < n; i++) assert(uf2.find(i) == uf2.find(i+n));
	vector<int> ans(n, 0);
	vector<int> par(n);
	vector<int> par_and(n), par_or(n);

	const int B = 30;
	vector<vector<vector<int> > > values(n, vector<vector<int> >(B, vector<int>(2, 0)));
	for(auto [a, a2] : extras){
		int root = a;
		y_combinator(
			[&](auto self, int v, int p) -> void {
				for(int w : fedges[v]){
					if(w == p) continue;
					self(w, v);
					cout << "and " << (v+1) << " " << (w+1) << '\n';
					cout << flush;
					cin >> par_and[w];
					cout << "or " << (v+1) << " " << (w+1) << '\n';
					cout << flush;
					cin >> par_or[w];
				}
			}
		)(root, -1);

		cout << "or " << (a+1) << " " << (a2+1) << '\n';
		cout << flush;
		int special;
		cin >> special;

		vector<vector<int> > f(B, {0, 1});
		vector<vector<int> > works(B, vector<int>(2, 1));
		y_combinator(
			[&](auto self, int v, int p, vector<vector<int> > z) -> void {
				values[v] = z;
				for(int w : fedges[v]){
					if(w == p) continue;
					vector<vector<int> > newz(B, vector<int>(2, -1));
					for(int b = 0; b < B; b++){
						for(int r = 0; r < 2; r++){
							if(z[b][r] == -1){
								newz[b][r] = -1;
							} else {							
								int and_need = 1 & (par_and[w] >> b);
								int or_need = 1 & (par_or[w] >> b);
								for(int s = 0; s < 2; s++){
									if((z[b][r] | s) == or_need && (z[b][r] & s) == and_need){
										// assert(newz[b][r] == -1);
										newz[b][r] = s;
									}
								}
							}
							if(newz[b][r] == -1) works[b][r] = 0;
						}
					}
					self(w, v, newz);
				}
			}
		)(root, -1, f);
		for(int b = 0; b < B; b++){
			int found = -1;
			if(works[b][0] && works[b][1]){
				int need_or = (special >> b) & 1;
				found = need_or;
			} else if(works[b][0]){
				found = 0;
			} else if(works[b][1]){
				found = 1;
			} else {
				assert(false);
			}
			y_combinator(
				[&](auto self, int v, int p) -> void {
					ans[v] |= (values[v][b][found] << b);
					for(int w : fedges[v]){
						if(w == p) continue;
						self(w, v);
					}
				}
			)(root, -1);
		}
	}
	sort(ans.begin(), ans.end());
	cout << "finish " << ans[k] << '\n';
}