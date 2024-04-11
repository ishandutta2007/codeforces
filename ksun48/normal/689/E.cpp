#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
map<LL,LL> d;
vector<LL> b;
vector<LL> r;
LL nck[320000];

LL powmod(LL a, int n){
	if(n == 0) return 1;
	if(n % 2) return (a*powmod(a,n-1)) % MOD;
	LL c = powmod(a, n/2);
	return (c*c) % MOD;
}
LL inv(LL a){
	return powmod(a,MOD-2);
}

int main(){
	LL n, k;
	scanf("%I64d%I64d", &n, &k);

	for(int i = 0; i < k; i++) nck[i] = 0;
	nck[k] = 1;
	for(LL i = k+1; i < 300000; i++){
		nck[i] = (nck[i-1] * i) % MOD;
		nck[i] = (nck[i] * inv(i-k)) % MOD;
	}

	for(int i = 0; i < n; i++){
		LL l, r;
		scanf("%I64d%I64d", &l, &r);
		d[l]++;
		d[r+1]--;
	}
	LL c = 0;
	LL ans = 0;
	for(map<LL,LL>::iterator it = d.begin(); it != d.end(); it++ ){
		b.push_back(it->first);
		r.push_back(it->second);
	}
	for(int i = 0; i < b.size()-1; i++){
		c += r[i];
		ans += nck[c]*(b[i+1] - b[i]);
		ans %= MOD;
	}
	cout << ans << endl;

}