#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 100005;

int n, h[MAXN], destroy[MAXN];

int main(){
	int i, ans = 1, minv;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &h[i]);
	minv = 0;
	for(i = 1; i <= n; ++ i){
		if(h[i] - i < h[minv] - minv) minv = i;
		destroy[i] = h[minv] - minv + i;
	}
	minv = n + 1;
	for(i = n; i; -- i){
		if(h[i] + i < h[minv] + minv) minv = i;
		destroy[i] = min(destroy[i], h[minv] + minv - i);
		ans = max(ans, destroy[i]);
	}
	printf("%d\n", ans);
	return 0;
}