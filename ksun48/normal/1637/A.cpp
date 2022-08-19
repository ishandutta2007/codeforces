#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> b = a;
	sort(b.begin(), b.end());
	if(a == b){
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}