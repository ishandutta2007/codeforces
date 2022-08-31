#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	ll n;
	cin >> n;
	cout << (n*n*n-n)/3 << '\n';

}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}