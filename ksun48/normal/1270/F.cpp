#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	using ll = long long;
	string s;
	cin >> s;
	const int B = 150;
	ll ans = 0;
	for(int n0 = 0; n0 < B; n0++){
		vector<int> z;
		int cur = 0;
		z.push_back(cur);
		for(char x : s){
			cur += (x == '1') ? n0 : -1;
			z.push_back(cur);
		}
		sort(z.begin(), z.end());
		int f = 0;
		for(int i = 0; i < (int)z.size(); i++){
			if(i == 0 || z[i] != z[i-1]) f = 0;
			ans += f;
			f++;
		}
	}

	int z = 0;
	vector<int> l0;
	vector<int> where;
	for(int i = 0; i < (int)s.size(); i++){
		char x = s[i];
		if(x == '1'){
			where.push_back(i);
			l0.push_back(z);
			z = 0;
		} else if(x == '0'){
			z++;
		}
	}
	l0.push_back(z);
	z = 0;
	int maxones = (int)(s.size()) / B + 1;

	vector<ll> psums(l0.size() + 1, 0);
	for(int i = 0; i < (int)l0.size(); i++){
		psums[i+1] = l0[i] - B + psums[i];
	}

	multiset<pair<ll, int> > idx; 

	auto cnt = [&](ll len, ll ones) -> ll {
		if(len < (B + 1) * ones) return 0;
		len += 1;
		ll x = len / ones;
		ll res = (len % ones) * ((x+1) * x / 2) + (ones - len % ones) * (x * (x-1) / 2);
		ll d = len * B - ones * B * (B+1) / 2;
		return res - d;
	};

	for(int i = 0; i < (int)l0.size(); i++){
		for(pair<ll, int> v : idx){
			if(psums[i] - v.first + l0[i] < 0) break;
			int j = v.second;
			// check j -> i
			int lpart = l0[j];
			int rpart = l0[i];
			int len = where[i-1] - where[j] + 1;
			int ones = i - j;
			ans += cnt(len + lpart + rpart, ones);
			ans -= cnt(len + lpart - 1, ones);
			ans -= cnt(len + rpart - 1, ones);
			ans += cnt(len - 2, ones);
		}
		idx.insert({psums[i], i});
		if(i >= maxones){
			idx.erase(idx.find({psums[i - maxones], i - maxones}));
		}
	}
	cout << ans << '\n';
}