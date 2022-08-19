#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;

int main(){
	LL n;
	scanf("%I64d", &n);
	LL h[n+2];
	for(LL i = 1; i <= n; i++){
		scanf("%I64d", &h[i]);
		h[i]--;
	}
	h[0] = 0;
	h[n+1] = 0;
	LL good[n+2];
	LL ans = 0;
	good[0] = 0;
	for(LL i = 1; i <= n+1; i++){
		ans += h[i];
		good[i] = min(h[i],h[i+1]);
		ans += good[i-1]*min(h[i],h[i-1]);
		good[i] += good[i-1]*min(h[i],min(h[i-1],h[i+1]));
		ans %= MOD;
		good[i] %= MOD;
	//cout << ans << endl;
	}
	cout << ans << endl;


}