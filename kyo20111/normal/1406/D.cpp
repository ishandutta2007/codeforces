#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
ll a[100100], b[100100];

ll f(ll a){
	if(a >= 0) return (a + 1) / 2;
	return a / 2;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=2;i<=n;i++) b[i] = a[i] - a[i-1];

	ll s = a[1], p = 0;
	for(int i=2;i<=n;i++) p += max(0ll, b[i]);

	cout << f(s + p) << "\n";
	
	cin >> q;
	while(q--){
		int l, r; ll a; cin >> l >> r >> a;

		if(l == 1) s += a;

		if(1 < l){
			if(b[l] >= 0) p -= b[l];

			b[l] += a;
			if(b[l] >= 0) p += b[l];
		}

		if(r < n){
			if(b[r+1] >= 0) p -= b[r+1];

			b[r+1] -= a;
			if(b[r+1] >= 0) p += b[r+1];
		}
		cout << f(s + p) << "\n";
	}
}