#include<cstdio>
int n;
int main() {
	int t; scanf("%d",&t);
    while(t--) {
		scanf("%d",&n);
        if(n==1) puts("-1");
        else{
			printf("8");
			for(int i=2; i<=n; i++) putchar('9');
			puts("");
		}
    }
    return 0;
}