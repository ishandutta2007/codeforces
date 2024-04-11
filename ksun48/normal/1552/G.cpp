#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<ull> masks;
	for(int i = 0; i < k; i++){
		int q;
		cin >> q;
		ull mask = 0;
		for(int j = 0; j < q; j++){
			int a;
			cin >> a;
			a--;
			mask ^= (ull(1) << a);
		}
		masks.push_back(mask);
	}
	vector<ull> cur = {ull(0)};
	ull seen = 0;
	for(ull m : masks){
		ull c = m & (~seen);
		vector<ull> cand;
		while(true){
			cand.push_back(c);
			if(c == 0) break;
			c = c & (c - 1);
		}
		reverse(cand.begin(), cand.end());
		seen |= m;
		c = m;
		vector<ull> smasks;
		while(true){
			smasks.push_back(c);
			if(c == 0) break;
			c = c & (c - 1);
		}
		reverse(smasks.begin(), smasks.end());
		vector<ull> newcur;
		for(ull b1 : cur){
			for(ull b2 : cand){
				ull a = b1 ^ b2;
				newcur.push_back((a & (~m)) ^ smasks[__builtin_popcountll(a & m)]);
			}
		}
		// sort(newcur.begin(), newcur.end());
		// newcur.resize(unique(newcur.begin(), newcur.end()) - newcur.begin());
		cur = newcur;
	}
	ull total = (ull(1) << n) - 1;
	bool okay = true;
	if(n > 1 && seen != total){
		okay = false;
	}
	for(ull x : cur){
		assert(__builtin_popcountll(x) <= n);
		if(x != (ull(1) << n) - (ull(1) << (n - __builtin_popcountll(x)))) okay = false;
	}
	cout << (okay ? "ACCEPTED" : "REJECTED") << '\n';
}