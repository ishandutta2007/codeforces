#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	bool same = true;
	for(int i = 0; i < n; i++) if(a[i] != a[0]) same = false;
	if(same){
		cout << 1 << '\n';
		for(int i = 0; i < n; i++) cout << 1 << ' ';
		cout << '\n';
		return;
	}
	if(n % 2 == 0){
		cout << 2 << '\n';
		for(int i = 0; i < n; i++){
			cout << 1 + (i & 1) << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i = 0; i < n; i++){
		if(a[i] == a[(i+1) % n]){
			cout << 2 << '\n';
			for(int j = 0; j < n; j++){
				cout << 1 + (1 & ((j - i - 1 + n) % n)) << ' ';
			}
			cout << '\n';
			return;
		}
	}
	cout << 3 << '\n';
	cout << 3 << ' ';
	for(int i = 1; i < n; i++){
		cout << 1 + (i & 1) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}