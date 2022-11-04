#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

void solve(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	if(n % 2050){
		cout << -1;
		return;
	}

	n /= 2050;
	ll c = 0;
	while(n) c += n%10, n/=10;

	cout << c;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}