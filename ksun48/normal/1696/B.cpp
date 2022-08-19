#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	if(a == vector<int>(n, 0)){
		cout << 0 << '\n';
		return;
	}
	int i = 0;
	while(i < n && a[i] == 0) i++;
	int j = n;
	while(j > 0 && a[j-1] == 0) j--;
	for(int k = i; k < j; k++){
		if(a[k] == 0){
			cout << 2 << '\n';
			return;
		}
	}
	cout << 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}