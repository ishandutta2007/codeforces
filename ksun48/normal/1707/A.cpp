#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, Q;
	cin >> n >> Q;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> test(n, 0);
	int ciq = 0;
	for(int i = n-1; i >= 0; i--){
		if(ciq + 1 <= a[i]){
			if(ciq + 1 <= Q){
				test[i] = 1;
				ciq++;
			}
		} else {
			test[i] = 1;
		}		
	}
	for(int x : test){
		cout << x;
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}