#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> freq(n+1, 0);
	vector<vector<int> > els(n);
	for(int i = 0; i < n; i++){
		els[freq[a[i]]].push_back(i);
		freq[a[i]]++;
	}
	vector<int> ans(n);
	for(auto& v : els){
		sort(v.begin(), v.end(), [&](int x, int y) { return a[x] < a[y]; });
		int k = (int)v.size();
		for(int j = 0; j < k; j++){
			ans[v[j]] = a[v[(j+1) % k]];
		}
	}
	for(int x : ans){
		cout << x << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}