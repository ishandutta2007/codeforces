#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	set<int> r;
	for(int j = 0; j < (1 << n); j++){
		int z = 0;
		for(int b = 0; b < n; b++){
			if(j & (1 << b)) z += a[b];
		}
		r.insert(z);
	}
	cout << ((int)r.size() == (1 << n) ? "NO" : "YES") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}