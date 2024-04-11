#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n;
	string s;
	cin >> n >> s;
	vector<pair<ll, ll> > segs;
	ll total = 0;
	ll csum = 0;
	ll cur1 = 0;
	for(ll i = 0; i < n; i++){
		if(s[i] == '0'){
			for(ll f = cur1; f >= 1; f--) segs.push_back({1, f});
			cur1 = 0;
			segs.push_back({1, 0});
			total += csum;
		} else if(s[i] == '1'){
			cur1++;
			ll ccnt = 0;
			while(!segs.empty() && segs.back().second < cur1){
				csum -= segs.back().first * segs.back().second;
				ccnt += segs.back().first;
				segs.pop_back();
			}
			if(ccnt > 0){
				csum += ccnt * cur1;
				segs.push_back({ccnt, cur1});
			}
			csum += cur1;
			total += csum;
		} else assert(false);
	}
	cout << total << '\n';
}