#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		while(a[i] && d >= i){
			d -= i; a[i]--; a[0]++;
		}
	}
	cout << a[0] << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}