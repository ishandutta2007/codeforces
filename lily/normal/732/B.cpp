/*	Never stop fighting for what you believe in.	*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAXN 5005
int n,k;
int b[MAXN],tot=0;
int main() {
	scanf("%d%d",&n,&k);
	int last=k;
	for (int i=1,a;i<=n;i++) {
		scanf("%d",&a);
		if (a+last<k) {
			tot+=k-last-a;
			a=k-last;
		}
		b[i]=a;
		last=a;
	}
	printf("%d\n",tot);
	for (int i=1;i<=n;i++) {
		printf("%d ",b[i]);
	}


	return 0;
}