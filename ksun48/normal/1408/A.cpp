#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > a(3, vector<int>(n));
	for(vector<int>& b : a) for(int& x : b) cin >> x;
	int prv = a[0][0];
	int fst = a[0][0];
	cout << prv;
	for(int i = 1; i < n; i++){
		int z = 0;
		while(a[z][i] == prv || a[z][i] == fst) z++;
		prv = a[z][i];
		cout << ' ' << a[z][i];
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}