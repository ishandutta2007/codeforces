#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[111];

void solve(){
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=1;i<n;i++){
		while(a[i] && k){
			a[i]--, k--, a[n]++;
		}
	}

	for(int i=1;i<=n;i++) cout << a[i] << " ";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}