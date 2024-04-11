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

int n,ans,a,b;

int main() {
	scanf("%d",&n);
	ans=n;
	for (int i=1;i<=sqrt(n);i++) {
		if (n%i==0) if (n/i-i<ans) ans=n/i-i,a=n/i,b=i;
	}
	printf("%d %d\n",b,a);
	return 0;
}