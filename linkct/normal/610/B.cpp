#include <cstdio>
typedef long long int LL;
const int MAXN = 200005;

int maxlen, n, a[MAXN];

int main(){
	int i, minv = 1000000001, prev, first;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		if(a[i] < minv) minv = a[i];
	}
	for(i = 1, prev = 0; i <= n; ++ i){
		if(a[i] != minv) continue;
		if(!prev) first = i;
		else if(i - prev - 1 > maxlen) maxlen = i - prev - 1;
		prev = i;
	}
	if(n - prev + first - 1 > maxlen) maxlen = n - prev + first - 1;
	printf("%I64d\n", LL(minv) * n + maxlen);
	return 0;
}