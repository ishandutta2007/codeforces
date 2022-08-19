#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	bool works = true;
	for(int i = 0; i < n; i++){
		int c = b[i] - a[i];
		if(! (c == 0 || c == 1)) works = false;
	}
	cout << (works ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}