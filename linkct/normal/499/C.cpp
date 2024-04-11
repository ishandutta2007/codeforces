#include <cstdio>
typedef long long int ll;

int a, b, c, xh, yh, xu, yu, n;

inline ll eval(int x, int y){
	return (ll)x * a + (ll)y * b + (ll)c;
}
inline int sign(ll x){return x > 0LL ? 1 : (x == 0LL ? 0 : -1);}
int main(){
	int i, ans = 0;
	scanf("%d%d%d%d%d", &xh, &yh, &xu, &yu, &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d%d", &a, &b, &c);
		if(sign(eval(xh, yh)) != sign(eval(xu, yu))) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}