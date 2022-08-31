#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n;
	cin >> n;
	vector<ll> freq(20, 0);
	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		for(int j = 0; j < 20; j++) if(a & (1 << j)) freq[j]++;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll a = 0;
		for(int j = 0; j < 20; j++){
			if(freq[j]){
				freq[j]--;
				a ^= (1 << j);
			}
		}
		ans += a * a;
	}
	cout << ans << '\n';
}