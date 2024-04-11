#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 2000000
using namespace std;
long long a[maxn];
long long vl[maxn];
long long n;
int main() {
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n==1) {
        printf("1 1\n");
        printf("0\n");
        printf("1 1\n");
        printf("0\n");
	}
	else {
        for(long long i=1;i<=n;i++) vl[(i*(n-1))%n]=i;
        printf("1 %lld\n",n-1);
        for(long long i=1;i<=n-1;i++) {
            long long x=a[i]%n;
            if(x<0) x+=n;
            x=n-x;
            a[i]+=vl[x]*(n-1);
            printf("%lld ",vl[x]*(n-1));
        }
        printf("\n");
        printf("2 %lld\n",n);
        for(long long i=2;i<=n;i++) {
            long long x=a[i]%n;
            if(x<0) x+=n;
            x=n-x;
            a[i]+=vl[x]*(n-1);
            printf("%lld ",vl[x]*(n-1));
        }
        printf("\n");
	}
	printf("1 %lld\n",n);
    for(long long i=1;i<=n;i++) {
        printf("%lld ",-a[i]);
    }
    printf("\n");
	return 0;
}