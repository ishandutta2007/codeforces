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



void pop_heap(vector<int>& a, int x){
	if(x >= (int)a.size() || a[x] == 0){
		return;
	}
	int l = x * 2;
	int r = x * 2 + 1;
	if(l >= (int)a.size()){
		a[x] = 0;
		return;
	} else if(a[l] > a[r]){
		a[x] = a[l];
		pop_heap(a, l);
	} else {
		a[x] = a[r];
		pop_heap(a, r);
	}
}

void call_pop(vector<int>& a, int x, vector<int>& ops){
	ops.push_back(x);
	pop_heap(a, x);
}

bool used[1200000];

void make_array(vector<int>& a, int x, vector<int>& ops){
	if(x >= (int)a.size()) return;
	if(a[x] == 0) return;
	make_array(a, 2*x, ops);
	make_array(a, 2*x + 1, ops);
	if(!used[a[x]]){
		call_pop(a, x, ops);
	}
}

void solve(){
	int h, g;
	cin >> h >> g;
	int len = (1 << h);
	vector<int> a(len);
	for(int i = 1; i < len; i++) cin >> a[i];
	long long ans = 0;
	for(int b = g-1; b >= 0; b--){
		for(int x = (1 << b); x < (1 << (b+1)); x++){
			int need = 0;
			for(int l = 0; l + b < h; l++){
				for(int y = 0; y < (1 << l); y++){
					int cur = (x << l) + y;
					if(used[a[cur]]) need = max(need, a[cur]);
				}
			}
			int best = 1e9;
			for(int l = 0; l + b < h; l++){
				for(int y = 0; y < (1 << l); y++){
					int cur = (x << l) + y;
					if(!used[a[cur]]){
						if(a[cur] > need && a[cur] < best){
							best = a[cur];
						}
					}
				}
			}
			ans += best;
			used[best] = true;
		}
	}
	vector<int> saved_a = a;
	vector<int> ops;
	make_array(a, 1, ops);
	for(int p : saved_a){
		used[p] = false;
	}
	cout << ans << '\n';
	for(int x : ops){
		cout << x << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}