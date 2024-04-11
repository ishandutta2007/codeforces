#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100005;
int n, L[N], R[N];
LL ans = 0;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", L + i, R + i);
	}
	sort(L + 1, L + 1 + n);
	sort(R + 1, R + 1 + n);
	for(int i = 1; i <= n; i++){
		ans += max(L[i], R[i]); 
	}
	printf("%lld\n", ans + n);
	return 0;
}