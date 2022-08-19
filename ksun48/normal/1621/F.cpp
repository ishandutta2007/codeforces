#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	cin >> s;
	int zeros = 0;
	int ones = 0;
	vector<int> groups;
	for(int i = 0; i + 1 < s.size(); i++){
		if(s[i] == '0' && s[i+1] == '0') zeros++;
		if(s[i] == '1' && s[i+1] == '1') ones++;
		if(s[i] == '1' && s[i+1] == '0'){
			int j = i+1;
			while(j < s.size() && s[j] == '0') j++;
			if(j < s.size()){
				groups.push_back(j-i-1);
			}
		}
	}
	int all_zeros = 0;
	for(char z : s) if(z == '0') all_zeros++;

	ll ans = a * min(zeros, ones + 1) + b * min(ones, zeros + 1);
	// {
	// 	ll n0 = min(all_zeros, ones + 1);
	// 	ll n1 = min(ones, all_zeros + 1);
	// 	ans = min(ans, min(n0, zeros) * a + n1 * b - (n0 - min(n0, zeros)) * c);
	// }
	sort(groups.begin(), groups.end());
	ll cneed = 0;
	int cnt = 0;
	auto check = [&](){
		if(cneed <= ones){
			int have_ones = ones + cnt;
			int ones_use = min(have_ones, all_zeros+1);
			int Z = max(ones_use - 1, 0);
			for(int zeros_use : {Z, Z+1, Z+2}){
				if(zeros_use > all_zeros) continue;
				if(zeros_use > ones_use + 1) continue;
				if(zeros_use < cnt) continue;
				zeros_use = max(zeros_use, cnt);
				int good_zeros = min(zeros_use - cnt, zeros);
				ans = max(ans, b * ones_use + a * good_zeros - c * (zeros_use - good_zeros));

			}
		}
	};
	check();
	for(int x : groups){
		cneed += (x-1);
		cnt++;
		check();
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}