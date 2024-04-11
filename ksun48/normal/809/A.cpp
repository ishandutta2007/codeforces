#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long LL;
LL pow2[310000];
int main(){
	int n;
	scanf("%d", &n);
	int x[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	sort(x,x+n);	
	pow2[0] = 1;
	for(int i = 0; i < 310000; i++){
		pow2[i+1] = (pow2[i] * 2) % MOD;
	}
	LL a[n];
	LL ans = 0;
	for(int i = 0; i < n; i++){
		a[i] = x[i];
		ans -= a[i] * pow2[n-1-i];
		ans += a[i] * pow2[i];		
		ans %= MOD;
	}
	ans %= MOD;
	while(ans < 0) ans += MOD;
	ans %= MOD;
	cout << ans << endl;
}