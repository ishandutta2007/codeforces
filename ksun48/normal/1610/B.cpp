#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int l = 0;
	int r = n-1;
	vector<int> cands = {};
	while(l < r){
		if(a[l] == a[r]){
			l++;
			r--;
		} else {
			cands.push_back(a[l]);
			cands.push_back(a[r]);
			break;
		}
	}
	cands.push_back(-1);
	for(int x : cands){
		vector<int> b;
		for(int z : a) if(z != x) b.push_back(z);
		vector<int> c = b;
		reverse(c.begin(), c.end());
		if(c == b){
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}