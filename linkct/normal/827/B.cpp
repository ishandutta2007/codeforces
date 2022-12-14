#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, m, k, last[MAXN];

int main(){
	int i, ans;
	scanf("%d%d", &n, &k);
	m = n - k;
	if(m <= k){
		if(m == 1){
			printf("2\n");
			for(i = 2; i <= n; ++ i)
				printf("1 %d\n", i);
			return 0;
		}
		if(m == 2){
			printf("3\n");
			printf("1 2\n1 3\n");
			for(i = 4; i <= n; ++ i)
				printf("2 %d\n", i);
			return 0;
		}
		printf("4\n");
		for(i = 2; i <= m; ++ i)
			printf("1 %d\n", i);
		for(i = 1; i < m; ++ i)
			printf("%d %d\n", i + 1, m + i);
		for(; i <= k; ++ i)
			printf("%d %d\n", 1, m + i);
		return 0;
	}
	ans = (m - 1) / k * 2;
	printf("%d\n", ans + 2 + min((m - 1) % k, 2));
	for(i = 1; i <= k; ++ i){
		printf("1 %d\n", i + 1);
		last[i % k] = i + 1;
	}
	for(i = k + 2; i <= m; ++ i){
		printf("%d %d\n", i - k, i);
		last[(i - 1) % k] = i;
	}
	for(i = 0; i < k; ++ i)
		printf("%d %d\n", last[i], i + m + 1);
	return 0;
}