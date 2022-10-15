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


int k,r,ans;

int main() {
	scanf("%d%d",&k,&r);
	for (int i=1;i;i++) {
		int to=k*i;
		if ((to-r)%10==0) {ans=i;break;}
		if (to%10==0) {ans=i;break;}
	}
	printf("%d\n",ans);
	return 0;
}