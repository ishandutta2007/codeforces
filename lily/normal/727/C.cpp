/*	Never stop fighting for what you believe in.	*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

#define MAXN 5005
int n;

int a[MAXN];
int ans[MAXN];



int main() {
	scanf("%d",&n);
	if (n&1) {	
		for (int i=1;i<n;i++) {
			printf("? %d %d\n",i,i+1);
			fflush(stdout);
			scanf("%d",a+i);
		}
		printf("? 1 %d\n",n);
		fflush(stdout);
		scanf("%d",a+n);
		long long sum=0;
		for (int i=1;i<=n;i++) {
			sum+=a[i];
		}
		sum/=2;
		for (int j=2;j<=n;j+=2) {
			sum-=a[j];
		}
		ans[1]=sum;
		for (int i=2;i<=n;i++) {
			ans[i]=a[i-1]-ans[i-1];
		}
		printf("!");
		for (int i=1;i<=n;i++) {
			printf(" %d",ans[i]);
		}
		fflush(stdout);
	}
	else {
		printf("? 1 3\n");
		fflush(stdout);
		scanf("%d",&a[0]);
		for (int i=1;i<n;i++) {
			printf("? %d %d\n",i,i+1);
			fflush(stdout);
			scanf("%d",a+i);
		}
		ans[1]=(a[1]+a[0]-a[2])/2;
		for (int i=2;i<=n;i++) {
			ans[i]=a[i-1]-ans[i-1];
		}
		printf("!");
		for (int i=1;i<=n;i++) {
			printf(" %d",ans[i]);
		}
		fflush(stdout);
	}
	return 0;
}