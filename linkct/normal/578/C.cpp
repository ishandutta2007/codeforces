#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int MAXN = 200005;

int n, a[MAXN];

double getWeakness(double x){
	double cur = 0.0, maxv = 0.0, minv = 0.0, ret = 0.0;
	for(int i = 1; i <= n; ++ i){
		cur += a[i] + x;
		ret = max(ret, fabs(maxv - cur));
		ret = max(ret, fabs(cur - minv));
		maxv = max(maxv, cur);
		minv = min(minv, cur);
	}
	return ret;
}
int main(){
	int i; double l, r, mid1, mid2;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	l = - 10000.0, r = 10000.0;
	for(i = 1; i <= 100; ++ i){
		mid1 = l + (r - l) / 3.0;
		mid2 = r - (r - l) / 3.0;
		if(getWeakness(mid1) > getWeakness(mid2)) l = mid1;
		else r = mid2;
	}
	printf("%.15f\n", getWeakness(r));
	return 0;
}