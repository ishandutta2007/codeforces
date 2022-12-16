#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn],ans,n;

int main(){
	scanf("%lld", &n);
	for(ll i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);

	for(ll i = 1,j,k; i <= n;){
		ans++;

		ll cnt = 0;
		for(j = i; j <= n && a[j] == -1; ++j) ++cnt;
		
		if(j > n) break;
		
		for(k = j + 1; k <= n && a[k] == -1; ++k);
		if(k > n) break;
		
		if((a[j] - a[k]) % (j - k)) {
			i = k;
			continue;
		}

		ll d = (a[k] - a[j]) / (k - j), val = a[k];
		if(a[j] - d * cnt <= 0) {
			i = k; continue;
		}
		for(++k; k <= n && val + d > 0 && (a[k] == val + d || a[k] == -1); ++k, val += d);
//		printf("%d %d\n", j, k);
		i = k;
	}

	printf("%lld", ans);

	return 0;
}
//CF416D