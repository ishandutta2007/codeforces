#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll query(ll x, ll y){
	cout << "? " << (x+1) << ' ' << (y+1) << '\n';
	cout << flush;
	ll res;
	cin >> res;
	return res;
}

void solve(){
	ll n;
	cin >> n;
	ll no = 1;
	ll yes = n;
	while(no + 1 < yes){
		ll mid = (no + yes) / 2;
		if(query(0, mid-1)){
			yes = mid;
		} else {
			no = mid;
		}
	}
	ll i = no-1;
	ll z = query(i, n-1) - query(i+1, n-1);
	ll j = i + z+1;
	ll y = query(j, n-1) - query(j+1, n-1);
	ll k = j + y;
	cout << "! " << (i+1) << ' ' << (j+1) << ' ' << (k+1) << '\n';
	cout << flush;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}