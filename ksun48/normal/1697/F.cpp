#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int A = k+1;
	TwoSat twosat(n * (k+1));
	for(int i = 0; i < n; i++){
		twosat.setValue(~(i * A));
		twosat.setValue((i * A + k));
		for(int j = 0; j < k; j++){
			twosat.either(~(i * A + j), (i * A + (j+1)));
		}
		if(i + 1 < n){
			for(int j = 0; j <= k; j++){
				twosat.either((i * A + j), ~((i+1) * A + j));
			}
		}
	}
	while(m--){
		int type;
		cin >> type;
		if(type == 1){
			int i, x;
			cin >> i >> x;
			i--;
			twosat.either((i * A + x-1), ~(i * A + x));
			twosat.either(~(i * A + x-1), (i * A + x));
		} else if(type == 2 || type == 3){
			int i, j, x;
			cin >> i >> j >> x;
			i--; j--;;
			for(int v1 = 0; v1 <= k; v1++){
				for(int v2 = 0; v2 <= k; v2++){
					if(type == 2 && v1 + v2 + 2 > x){
						twosat.either((i * A + v1), (j * A + v2));
					}
					if(type == 3 && v1 + v2 < x){
						twosat.either(~(i * A + v1), ~(j * A + v2));
					}
				}
			}
		}
	}
	if(!twosat.solve()){
		cout << -1 << '\n';
		return;
	}
	vector<int> ret(n, -1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			if(twosat.values[i * A + j] != twosat.values[i * A + (j+1)]){
				assert(ret[i] == -1);
				ret[i] = j;
			}
		}
		assert(ret[i] != -1);
	}
	for(int x : ret){
		cout << (x+1) << ' ';
	}
	cout << '\n';
}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}