#include <cstdio>
typedef long long int ll;

int n, m;

inline double quickPow(double base){
	double retval = 1.0000;
	int cnt = n;
	while(cnt){
		if(cnt & 1) retval *= base;
		base *= base;
		cnt >>= 1;
	}
	return retval;
}
int main(){
	int i; double ans;
	scanf("%d%d", &m, &n);
	ans = quickPow(1.000 / m);
	for(i = 2; i <= m; ++ i)
		ans += (quickPow((double)i / m) - quickPow((double)(i - 1) / m)) * i;
	printf("%.15f\n", ans);
	return 0;
}