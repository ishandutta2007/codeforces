#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int best = 0;
	vector<int> a;
	for(int i = 0; i < 2*n; i++){
		int r;
		cin >> r;
		if(r > best) a.push_back(i);
		best = max(best, r);
	}
	a.push_back(2*n);
	using B = bitset<5000>;
	B r;
	r[0].flip();
	for(int i = 1; i < (int)a.size(); i++){
		r = r | (r << (a[i] - a[i-1]));
	}
	cout << (r[n] ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}