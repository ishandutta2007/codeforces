#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100005;
typedef long long LL;
int n, S, a[N], f[N];
LL s[N];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &S);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			s[i] = s[i - 1] + a[i];
			f[i] = i;
		}
		
        for (int i = 2; i <= n; i++) {
            f[i] = a[i] > a[f[i - 1]] ? i : f[i - 1]; 
        }
		if(s[n] <= S) {
			puts("0"); continue;
		}
		int l = 0, r = n;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(s[mid] - a[f[mid]] <= S) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", f[r]);
	}
	return 0;
	
}