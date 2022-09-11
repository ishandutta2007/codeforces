#include <cstdio>

int main() {
	int n; scanf("%d",&n);
	int ret=0; for(int i=1;i<=n-1;++i) if((n-i)%i==0) ++ret; printf("%d\n",ret);
	return 0;
}