#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1000005;
int n, a[N], ans[N], len = 0, maxn, d = 0;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
bool check(int x) {
	printf("\n> %d\n", x);
	fflush(stdout);
	int r; scanf("%d", &r);
	return r;
}
int inline rd(int x) {
	return (LL)rand() * rand() % x;
}
int main(){
	srand(time(0));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i] = i;
	
	int l = 0, r = 1e9;
	
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	maxn = r + 1;
	
	
	int tot = n;
	for(int i = 1; i <= 30; i++){
		if(!tot) break;
		int loc = rd(tot) + 1;
		ans[++len] = a[loc];
		swap(a[tot], a[loc]);
		tot--;
	}
	
	
	int last = maxn;
	for(int i = 1; i <= len; i++) {
		printf("\n? %d\n", ans[i]);
		fflush(stdout);
		int x; scanf("%d", &x);
		d = gcd(d, abs(last - x));
		last = x;
	}
	printf("! %d %d\n", maxn - (n - 1) * d, d);
    return 0;
}