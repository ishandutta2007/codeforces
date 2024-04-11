#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> freq(n);
	for(int i = 0; i < n; i++) cin >> freq[i];

	ll s = 0;
	ll e = ll(1e17);
	while(s + 1 < e){
		ll m = (s + e) / 2;
		vector<ll> copy_freq = freq;
		ll need1 = m;
		vector<pair<ll,ll> > rle_pair, rle_single;
		ll need2 = m;
		for(int i = n-1; i >= 0; i--){
			ll use = min(need1, copy_freq[i] / 2);
			need1 -= use;
			copy_freq[i] -= 2 * use;
			rle_pair.emplace_back(i, use);
		}
		reverse(rle_pair.begin(), rle_pair.end());
		for(int i = 0; i < n; i++){
			ll use = min(need2, copy_freq[i]);
			need2 -= use;
			copy_freq[i] -= use;
			rle_single.emplace_back(i, use);
		}
		if(need1 > 0 || need2 > 0){
			e = m; continue;
		}
		int idx1 = 0;
		int idx2 = 0;
		bool fail = false;
		while(idx1 < (int)(rle_pair.size()) || idx2 < (int)(rle_single.size())){
			if(idx1 < (int)(rle_pair.size()) && rle_pair[idx1].second == 0){
				idx1++; continue;
			}
			if(idx2 < (int)(rle_single.size()) && rle_single[idx2].second == 0){
				idx2++; continue;
			}
			if(rle_pair[idx1].first < rle_single[idx2].first){
				fail = true;
				break;
			}
			ll num = min(rle_pair[idx1].second, rle_single[idx2].second);
			rle_pair[idx1].second -= num;
			rle_single[idx2].second -= num;
		}
		if(fail){
			e = m;
		} else {
			s = m;
		}
	}
	cout << s << '\n';
}