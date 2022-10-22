#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +5;
int t,n,a[N];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)	
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		if(n & 1) printf("%d ",a[n+1>>1]);
		int p = n>>1,q = n+3>>1;
		for(int i = 1;i <= (n>>1);++i)
			printf("%d %d ",a[p],a[q]),--p,++q;
		puts("");
	}
	return 0;
}