#include<cstdio>

int n, k;
int rem;
long long ans;

int main() {
	scanf("%d%d", &n, &k);
	rem = 0;
	ans = 0LL;
	for(int i=0;i<n;i++) {
		int x; scanf("%d", &x);
		if(rem>0 && rem+x<=k) {
			ans++; rem = 0;
		} else {
			ans += (rem+x)/k;
			rem = (rem+x)%k;
		}
	}
	if (rem>0) ans++;
	printf("%I64d\n", ans);
	
	return 0;
}