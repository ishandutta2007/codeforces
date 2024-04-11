#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int z[n];
	LL c[n];
	LL cap[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &z[i]);
		c[i] = z[i];
		cap[i] = 0;
	}
	for(int i = 0; i < k; i++){
		int d;
		scanf("%d", &d);
		cap[d-1] = 1;
	}
	LL sum = 0;
	LL capsum = 0;
	LL ans = 0;
	for(int i = 0; i < n; i++){
		sum += c[i];
		capsum += cap[i]*c[i];
		if(!cap[i] && !cap[(i+1) % n]){
			ans += (LL)c[i]*(LL)c[(i+1)%n]*2;
		}
		ans -= cap[i]*c[i]*c[i];
	}
	ans += capsum*capsum;
	ans /= 2;
	ans += ((sum-capsum)*capsum);
	cout << ans << endl;
}