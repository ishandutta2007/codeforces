#include<bits/stdc++.h>
#define MAXN 110000
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL sum[MAXN+1];
LL ans = 0;
LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n == 1) return a;
	if(n % 2) return (a*powmod(a,n-1))%MOD;
	LL c = powmod(a,n/2);
	return (c*c) % MOD;
}
int main(){
	LL n;
	cin >> n;
	LL a[n];
	for(LL i = 0; i <= MAXN; i++){
		sum[i] = 0;
	}
	for(LL i = 0; i < n; i++){
		cin >> a[i];
		sum[a[i]]++;
	}
	for(LL i = 1; i <= MAXN; i++){
		sum[i] += sum[i-1];
	}
	for(LL d = 1; d <= 100000; d++){
		vector<LL> z;
		for(LL i = 1; i*i <= d; i++){
			if(d % i == 0){
				z.push_back(i);
			}
		}
		LL l = z.size();
		for(LL i = l-1; i >= 0; i--){
			if(z[i]*z[i] < d){
				z.push_back(d/z[i]);
			}
		}
		z.push_back(MAXN);
		LL c = 1;
		for(LL a = 0; a < z.size()-1; a++){
			LL e = sum[z[a+1]-1]-sum[z[a]-1];
			c *= powmod(a+1,e);
			c %= MOD;
		}
		LL f = 1;
		z.pop_back();
		z.pop_back();
		z.push_back(MAXN);
		for(LL a = 0; a < z.size()-1; a++){
			LL e = sum[z[a+1]-1]-sum[z[a]-1];
			f *= powmod(a+1,e);
			f %= MOD;
		}
		LL e = ((c-f)%MOD+MOD)%MOD;
		ans += e;
		ans %= MOD;
	}
	ans++;
	ans %= MOD;
	cout << ans << endl;
}