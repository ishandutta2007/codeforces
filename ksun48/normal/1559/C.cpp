#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x = -1;
	if(a[0] == 1){
		x = 0;
	} else if(a[n-1] == 0){
		x = n;
	} else {
		for(int i = 0; i + 1 < n; i++){
			if(a[i] == 0 && a[i+1] == 1) x = i+1;
		}
	}
	for(int i = 0; i < x; i++) cout << (i+1) << ' ';
	cout << (n+1) << ' ';
	for(int i = x; i < n; i++) cout << (i+1) << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}