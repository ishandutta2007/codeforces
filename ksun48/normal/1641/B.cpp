#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> oa = a;
	map<int, int> freq;
	for(int x : a){
		freq[x] ^= 1;
	}
	for(auto [x, f] : freq){
		if(f){
			cout << -1 << '\n';
			return;
		}
	}
	vector<pair<int,int> > ops;
	vector<int> lens;
	while(!a.empty()){
		int l = (int)a.size();
		int j = 0;
		while(a[j] != a[l-1]) j++;
		assert(j < l-1);
		int v = l - (j+1);
		for(int x = 0; x < v; x++){
			ops.push_back({j+1 + x, a[j+1+v-1-x]});
		}
		reverse(a.begin() + (j+1), a.begin() + l);
		lens.push_back(2 * v);
		v = l - j;
		for(int x = 0; x < v; x++){
			ops.push_back({j + x, a[j+v-1-x]});
		}
		lens.push_back(2 * v);
		reverse(a.begin() + j, a.begin() + l);
		assert(a[l-1] == a[l-2]);
		a.pop_back();
		a.pop_back();
		lens.push_back(2);
	}
	reverse(lens.begin(), lens.end());
	cout << ops.size() << '\n';
	for(auto [x, y] : ops){
		cout << x << ' ' << y << '\n';
		// oa.insert(oa.begin() + x, y);
		// oa.insert(oa.begin() + x, y);
	}
	cout << lens.size() << '\n';
	for(int x : lens) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}