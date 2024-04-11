#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n);
	for(int i = 0; i < n; i++) a[i] = s[i] - '0';
	for(int x : a){
		if(x == 1 || x == 4 || x == 6 || x == 8 || x == 9){
			cout << 1 << '\n';
			cout << x << '\n';
			return;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int z = a[i] * 10 + a[j];
			int prime = 1;
			for(int p = 2; p * p <= z; p++) if(z % p == 0) prime = 0;
			if(!prime){
				cout << 2 << '\n';
				cout << z << '\n';
				return;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				int z = a[i] * 100 + a[j] * 10 + a[k];
				int prime = 1;
				for(int p = 2; p * p <= z; p++) if(z % p == 0) prime = 0;
				if(!prime){
					cout << 3 << '\n';
					cout << z << '\n';
					return;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				for(int l = k+1; l < n; l++){
					int z = a[i] * 1000 + a[j] * 100 + a[k] * 10 + a[l];
					int prime = 1;
					for(int p = 2; p * p <= z; p++) if(z % p == 0) prime = 0;
					if(!prime){
						cout << 4 << '\n';
						cout << z << '\n';
						return;
					}
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}