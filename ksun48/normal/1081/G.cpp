#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL MOD;

LL powmod(LL a, LL n){
    if(n == 0) return 1;
    if(n % 2) return (a*powmod(a,n-1)) % MOD;
    LL c = powmod(a, n/2);
    return (c*c) % MOD;
}
LL inv(LL a){
    return powmod(a, MOD-2);
}
LL fact[110000];
LL invfact[110000];

LL ncr(LL n, LL r){
    if(r < 0 || n < 0) return 0;
    if(n < r) return 0;
    LL a = fact[n];
    a = (a * invfact[r]) % MOD;
    a = (a * invfact[n-r]) % MOD;
    return a;
}

LL get(LL a, LL b){
	LL ans = 0;
	for(LL q = 2; q <= a+b; q++){
		LL f = min(a, q-1) - max(1LL, q-b) + 1;
		ans += f * inv(q);
		ans %= MOD;
	}
	return ans;
}

int main(){
	LL n, k, q;
	cin >> n >> k >> q;
	MOD = q;

	map<LL,LL> r;
	r[n] = 1;
	for(int j = 1; j < k; j++){
		map<LL,LL> rr;
		for(auto x : r){
			if(x.first == 1){
				rr[x.first] += x.second;
			} else {
				rr[x.first / 2] += x.second;
				rr[(x.first + 1) / 2] += x.second;
			}
		}
		r = rr;
		if(rr.count(1) && rr[1] == n) break;
	}
	LL avg = n * (n-1) / 2;
	avg %= MOD;
	avg = (avg * inv(2)) % MOD;

	if(r.size() == 1){
		auto x = *r.begin();
		LL freq = x.second;
		LL g = x.first;
		avg -= (freq * (freq - 1) / 2) % MOD * get(g,g);
		avg %= MOD;
	} else if(r.size() == 2){
		vector<pair<int,int> > x;
		for(auto b : r) x.push_back(b);
		LL freq0 = x[0].second;
		LL freq1 = x[1].second;
		avg -= (freq0 * (freq0 - 1) / 2) % MOD * get(x[0].first, x[0].first);
		avg %= MOD;
		avg -= (freq1 * (freq1 - 1) / 2) % MOD * get(x[1].first, x[1].first);
		avg %= MOD;
		avg -= (freq0 * freq1) % MOD * get(x[0].first, x[1].first);
		avg %= MOD;
	}
	avg %= MOD;
	if(avg < 0) avg += MOD;
	cout << avg << '\n';
}