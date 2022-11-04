#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll s, e;

void solve(){
	cin >> s >> e;

	if(__builtin_popcountll(s) < __builtin_popcountll(e)){
		cout << "NO";
		return;
	}

	if(s == e){
		cout << "YES";
		return;
	}

	ll r = 1ll << 30;
	while((s & r) == (e & r)) r >>= 1;

	if((s & r) && !(e & r)){
		cout << "NO";
		return;
	}

	s &= (r << 1) - 1;
	e &= (r << 1) - 1;

	while((s & 1) == (e & 1)) s >>= 1, e >>= 1;

	if(!(s & 1) && (e & 1)){
		cout << "NO";
		return;
	}

	int c = 1;
	s >>= 1, e >>= 1;
	while(e){
		c += s & 1;
		c -= e & 1;
		if(c < 0){
			cout << "NO";
			return;
		}
		s >>= 1, e >>= 1;
	}

	cout << "YES";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}