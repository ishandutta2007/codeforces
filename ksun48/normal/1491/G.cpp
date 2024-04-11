#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> _c(n);
	for(int& x : _c){
		cin >> x;
		x--;
	}
	vector<int> invc(n);
	for(int i = 0; i < n; i++) invc[_c[i]] = i;
	vector<int> c = _c;

	vector<vector<int> > cycles;
	vector<int> vis(n, 0);
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		if(c[i] == i){
			vis[i] = 1;
			continue;
		}
		vector<int> cycle;
		int v = i;
		while(true){
			vis[v] = 1;
			cycle.push_back(v);
			v = c[v];
			if(v == i) break;
		}
		cycles.push_back(cycle);
	}
	vector<pair<int,int> > ops;
	while(cycles.size() >= 2){
		vector<int> a = cycles.back();
		cycles.pop_back();
		vector<int> b = cycles.back();
		cycles.pop_back();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		ops.push_back({a[a.size() - 2], b.back()});
		for(int i = (int)a.size() - 2; i > 0; i--){
			ops.push_back({a[i], a[i-1]});
		}
		ops.push_back({b[b.size() - 2], a.back()});
		for(int i = (int)b.size() - 2; i > 0; i--){
			ops.push_back({b[i], b[i-1]});
		}
		ops.push_back({a.back(), b.back()});
		ops.push_back({a.front(), b.front()});
	}
	if(!cycles.empty()){
		vector<int> a = cycles.back();
		if(a.size() >= 3){
			for(int i = 1; i < (int)a.size() - 1; i++){
				ops.push_back({a[i], a[i-1]});
			}
			ops.push_back({a[0], a.back()});
			ops.push_back({a[0], a[(int)a.size() - 2]});
			ops.push_back({a[0], a.back()});
		} else {
			int v = 0;
			while(v == a[0] || v == a[1]) v++;
			ops.push_back({a[0], v});
			ops.push_back({a[0], a[1]});
			ops.push_back({a[1], v});
		}
	}
	vector<int> st = invc;
	cout << ops.size() << '\n';
	vector<int> f(n, 0);

	// v.first = coin
	for(pair<int,int> v : ops){
		cout << st[v.first]+1 << ' ' << st[v.second]+1 << '\n';
		// cout << v.first << ' ' << v.second << '\n';
		swap(st[v.first], st[v.second]);
		f[v.first] ^= 1;
		f[v.second] ^= 1;
	}
}
// position ci has coin i
// choose i j
// swap positions of coins i and j
// flip positions of coins i and j