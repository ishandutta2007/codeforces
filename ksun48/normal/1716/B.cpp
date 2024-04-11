#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) a[i] = i;
	cout << n << '\n';
	for(int g = 0; g < n; g++){
		for(int x : a){
			cout << (x+1) << ' ';
		}
		cout << '\n';
		if(g + 1 < n){
			swap(a[g], a[g+1]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}