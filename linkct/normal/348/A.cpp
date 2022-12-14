#include <cstdio>
typedef long long int ll;

inline ll max(ll a, ll b){return a > b ? a : b;}
int main(){
	int i, maxv = -1, t, n; ll sum = 0LL;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		if(t > maxv) maxv = t;
		sum += t;
	}
	printf("%I64d\n", max(maxv, (sum - 1) / (n - 1) + 1));
	return 0;
}