#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int pa = 1e8;
	int pb = 0;
	for(int i = 0; i < n; i++){
		int na = min(a[i] - pb, pa);
		if(na < 0){
			cout << "NO" << '\n';
			return;
		}
		pa = na;
		pb = a[i] - pa;
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}