#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q, a[100100];

void solve(){
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];

	int c = 0;
	for(int i=1;i<=n;i++) c += a[i];

	while(q--){
		int x, y; cin >> x >> y;
		if(x == 1){
			c -= a[y];
			a[y] = 1 - a[y];
			c += a[y];
		}else{
			cout << (c >= y) << "\n";
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1;// cin >> tc;
	while(tc--) solve();
}