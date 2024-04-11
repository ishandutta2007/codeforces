#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,a[N],t,ok;
int cnt[N],ans[N];
int main() {
	scanf("%d",&t);
	while(t--) {
		ok = 1;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)
			scanf("%d",a+i),(i != 1 && a[i] != a[i-1] && (ok = 0));
		if(ok) {
			puts("1");
			for(int i = 1;i <= n;++i)
				printf("1 ");
			puts("");
		}
		else if(n & 1) {
			ok = 0;
			for(int i = 1;i <= n;++i)
				if(a[i] == a[i%n+1]) {
					int x = 0,p = i%n+1,q = i;
					while(p != q) {
						ans[p] = x+1;
						x ^= 1;
						p = p % n + 1;
					}
					ans[q] = 1;ok = 1;
					break;
				}
			if(ok) {
				puts("2");
				for(int i = 1;i <= n;++i)
					printf("%d ",ans[i]);
				puts("");
			}
			else {
				puts("3");
				for(int i = 1;i < n;++i)
					printf("%d ",(i&1) + 1);
				puts("3");
			}
		}
		else {
			puts("2");
			for(int i = 1;i <= n;++i)
				printf("%d ",(i&1) + 1);
			puts("");
		}
	}
	return 0;
}