#include <bits/stdc++.h>
using namespace std;

int mex(vector<int> b){
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for(int i = 0; i < (int)b.size(); i++){
		if(b[i] != i) return i;
	}
	return (int)b.size();
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> ops;
	int f = n;
	while(true){
		int v = mex(a);
		assert(v <= f);
		if(v == f){
			a[v-1] = v;
			ops.push_back(v-1);
			f--;
		} else {
			a[v] = v;
			ops.push_back(v);
		}
		bool done = true;
		for(int i = 1; i < n; i++){
			if(a[i-1] > a[i]) done = false;
		}
		if(done) break;
	}
	assert((int)ops.size() <= 2*n);
	// for(int r : a) cerr << r << ' ';
	// cerr << '\n';
	cout << ops.size() << '\n';
	for(int o : ops) cout << o + 1 << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}