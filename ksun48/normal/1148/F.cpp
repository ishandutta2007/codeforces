#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> val(n);
	vector<ll> mask(n);
	for(int i = 0; i < n; i++) cin >> val[i] >> mask[i];
	ll s = 0;

	ll orig_sum = 0;
	for(int i = 0; i < n; i++){
		orig_sum += val[i];
	}
	if(orig_sum < 0){
		orig_sum *= -1;
		for(int i = 0; i < n; i++){
			val[i] *= -1;
		}
	}
	for(ll b = 0; b < 62; b++){
		ll flip_sum = 0;
		ll g = (1ll << b);
		for(int i = 0; i < n; i++){
			if(mask[i] == g){
				flip_sum += val[i];
			}
		}
		if(flip_sum > 0){
			s ^= (1ll << b);
			for(int i = 0; i < n; i++){
				if(mask[i] & g){
					val[i] *= -1;
				}
			}
		}
		for(int i = 0; i < n; i++){
			mask[i] = mask[i] & (~g);
		}
	}
	cout << s << '\n';
}