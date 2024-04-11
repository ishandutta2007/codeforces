#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
	}
	vector<int> b(n);
	int i = 0;
	while(i < n){
		int j = i;
		while(j < n && a[j] == a[i]){
			j++;
		}
		if(j == i+1){
			cout << -1 << '\n';
			return;
		}
		for(int k = i; k < j; k++){
			if(k == i){
				b[k] = j-1;
			} else {
				b[k] = k-1;
			}
		}
		i = j;
	}
	for(int x : b){
		cout << (x+1) << " ";
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}