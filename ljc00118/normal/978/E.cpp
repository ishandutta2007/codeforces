#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;

int a[N];
int n, w;
int minn = 0, maxn = 0;

int main() {
	scanf("%d %d", &n, &w);
	int tmp = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		tmp += a[i];
		minn = min(minn, tmp);
		maxn = max(maxn, tmp);
	}
	printf("%d", max(0, w - (maxn - minn) + 1));
	return 0; 
}