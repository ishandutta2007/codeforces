#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n % 2) return (a*powmod(a,n-1)) % MOD;
	LL c = powmod(a, n/2);
	return (c*c) % MOD;
}
LL inv(LL a){
	return powmod(a, MOD-2);
}
int main(){
	LL k;
	cin >> k;
	LL a[k];
	LL sum = 0;
	for(LL i = 0; i < k; i++){
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a+k);
	LL ans = 0;

	LL s = 0;
	LL x = ((sum-1)*(sum-1)) % MOD;
	x *= inv(sum);
	x %= MOD;

	LL hn = 0;
	LL asum = 0;
	for(LL i = 0; i <= sum; i++){
		if(i > 0){
			hn += (sum-1) * inv(sum-i);
			hn %= MOD;
		}
		while(s < k && a[s] == i){
			ans += (i*x) % MOD;
			ans -= asum;
			ans %= MOD;
			s++;
		}
		if(s == k) break;
		asum += hn;
		asum %= MOD;
	}
	while(ans < 0) ans += MOD;
	cout << ans << endl;
}