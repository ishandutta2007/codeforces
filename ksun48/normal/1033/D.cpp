#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL r2(LL a){
	LL s = 0;
	LL e = 2e9;
	while(s + 1 < e){
		LL m = (s + e) / 2;
		if(m * m == a) return m;
		if(m * m > a){
			e = m;
		} else {
			s = m;
		}
	}
	if(s * s == a) return s;
	if(e * e == a) return e;
	return -1;
}

LL r3(LL a){
	LL s = 0;
	LL e = 13e5;
	while(s + 1 < e){
		LL m = (s + e) / 2;
		if(m * m * m == a) return m;
		if(m * m * m > a){
			e = m;
		} else {
			s = m;
		}
	}
	if(s * s * s == a) return s;
	if(e * e * e == a) return e;
	return -1;
}

LL r4(LL a){
	LL s = 0;
	LL e = 4e4;
	while(s + 1 < e){
		LL m = (s + e) / 2;
		if(m * m * m * m == a) return m;
		if(m * m * m * m > a){
			e = m;
		} else {
			s = m;
		}
	}
	if(s * s * s * s == a) return s;
	if(e * e * e * e == a) return e;
	return -1;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	LL n;
	cin >> n;
	map<LL, LL> pf;
	vector<LL> other_stuff;
	for(LL i = 0; i < n; i++){
		LL c;
		cin >> c;
		if(r4(c) != -1){
			pf[r4(c)] += 4;
			continue;
		}
		if(r3(c) != -1){
			pf[r3(c)] += 3;
			continue;
		}
		if(r2(c) != -1){
			pf[r2(c)] += 2;
			continue;
		}
		other_stuff.push_back(c);
	}
	for(LL i = 0; i < other_stuff.size(); i++){
		for(LL j = 0; j < other_stuff.size(); j++){
			LL g = __gcd(other_stuff[i], other_stuff[j]);
			if(g == 1) continue;
			if(g < other_stuff[i]){
				assert(g < other_stuff[j]);
				pf[g] += 0;
				pf[other_stuff[i] / g] += 0;
				pf[other_stuff[j] / g] += 0;
			}
		}
	}
	while(1){
		LL did = 0;
		for(LL i = 0; i < other_stuff.size(); i++){
			LL f1 = -1;
			LL f2 = -1;
			for(auto x : pf){
				LL p = x.first;
				assert(p != 1);
				if(other_stuff[i] % p == 0){
					assert(other_stuff[i] != p);
					f1 = p;
					f2 = other_stuff[i] / p;
				}
			}
			if(f1 != -1){
				did = 1;
				pf[f1]++;
				pf[f2]++;
				other_stuff.erase(other_stuff.begin() + i);
				random_shuffle(other_stuff.begin(), other_stuff.end());
				break;
			}
		}
		if(did == 0) break;
	}
	map <LL, LL> pq;
	for(LL a : other_stuff){
		pq[a]++;
	}
	LL ans = 1;
	const LL MOD = 998244353;
	for(auto x : pf){
		ans *= (x.second + 1);
		ans %= MOD;
	}
	for(auto x : pq){
		ans *= (x.second + 1);
		ans %= MOD;
		ans *= (x.second + 1);
		ans %= MOD;
	}
	cout << ans << endl;
}