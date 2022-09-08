#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

int a[N];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	a[n + 1] = -999999;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if(k == 0) {
		if(a[1] == 1) printf("-1");
		else printf("1");
		return 0;
	}
	if(a[k] == a[k + 1]) printf("-1");
	else printf("%d", a[k]);
	return 0;
}