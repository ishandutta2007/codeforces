#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
int n;
int t[300000];
vector<int> plist[300000];
int st[300000];
LL pow2[600000];
LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n == 1) return a;
	if(n % 2) return (a*powmod(a,n-1)) % MOD;
	LL c = powmod(a,n/2);
	return (c*c) % MOD;
}
LL dp[300000];
LL ncr[400000];
LL ans = 0;
int main(){
	pow2[0] = 1;
	for(int i = 1; i < 600000; i++){
		pow2[i] = (pow2[i-1]*2) % MOD;
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &t[i]);
		for(int p = 2; p*p <= t[i]; p++){
			int r = 0;
			while(t[i] % p == 0){
				t[i] /= p;
				r++;
			}
			if(r > 0) plist[p].push_back(r);
		}
		if(t[i] > 1) plist[t[i]].push_back(1);
	}
	ncr[0] = 1;
	n--;
	for(LL i = 1; i <= n; i++){
		ncr[i] = ncr[i-1] * (n-i+1);
		ncr[i] %= MOD;
		ncr[i] *= powmod(i,MOD-2);
		ncr[i] %= MOD;
	}
	dp[0] = (pow2[n]+MOD-1) % MOD;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i-1] - ncr[i]-ncr[i-1] + MOD + MOD;
		dp[i] %= MOD;
	}
	for(int i = 0; i < 300000; i++){
		int k = plist[i].size();
		if(k == 0) continue;
		for(int j = 0; j < k; j++){
			st[j] = -plist[i][j];
		}
		sort(st, st+k);
		for(int j = 0; j < k; j++){
			st[j] = -st[j];
			LL c = st[j];
			ans += c*dp[j];
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}