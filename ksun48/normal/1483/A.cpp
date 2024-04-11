#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int th = (m + 1) / 2;
	vector<int> freq(n, 0);
	vector<vector<int> > a(m);
	vector<int> chosen(m);
	for(int i = 0; i < m; i++){
		int r;
		cin >> r;
		a[i].resize(r);
		for(int& x : a[i]){
			cin >> x;
			x--;
		}
		chosen[i] = a[i][0];
		freq[chosen[i]]++;
	}
	for(int i = 0; i < m; i++){
		if(a[i].size() == 1) continue;
		if(freq[chosen[i]] > th){
			freq[chosen[i]]--;
			chosen[i] = a[i][1];
			freq[chosen[i]]++;
		}
	}
	for(int i = 0; i < n; i++){
		if(freq[i] > th){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
	for(int r : chosen){
		cout << (r+1) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}