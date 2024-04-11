#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll w;
	cin >> w;
	w += 2;
	vector<ll> ans(w, 0);

	ll gc = 0;
	for(int i = 0; i < n; i++){
		ll len;
		cin >> len;
		len += 2;
		vector<ll> a(len);
		a[0] = a[len-1] = 0;
		for(int j = 1; j < len-1; j++){
			cin >> a[j];
		}
		if(len == w){
			for(int j = 0; j < w; j++){
				ans[j] += a[j];
			}
		} else {
			vector<ll> idx;
			int s = 0;
			ll offset = -1e9;
			if(len * 2 + 3 < w){
				for(int j = 0; j < len; j++){
					offset = max(offset, a[j]);
				}
			}
			for(ll i = 0; i < w; i++){
				if(i < len){
					while((int)idx.size() > s && a[idx.back()] <= a[i]){
						idx.pop_back();
					}
					idx.push_back(i);
				}
				if(idx[s] == i - (w - len + 1)) s += 1;
				ans[i] += a[idx[s]] - offset;
				if(len * 2 + 3 < w && i == len){
					i = w - len - 2;
				}
			}
			gc += offset;
		}
	}
	for(int i = 1; i < w-1; i++){
		cout << gc + ans[i] << ' ';
	}
	cout << '\n';
}