#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[2020];

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=2;i<=n;i++) a[i] ^= a[i-1];

	if(a[n] == 0){
		cout << "YES";
		return;
	}

	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] == (a[j] ^ a[i]) && a[i] == (a[n] ^ a[j])){
				cout << "YES";
				return;
			}
		}
	}

	cout << "NO";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}