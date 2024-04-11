#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
/* Configuration */




int x,y,a[3],cnt=0;

int main() {
	scanf("%d%d",&x,&y);
	a[0]=a[1]=a[2]=y;
	while (1) {
		sort(a,a+3);
		if (a[0]==x) break;
		cnt++;
		a[0]=min(x,a[1]+a[2]-1);
	}
	printf("%d\n",cnt);
	return 0;
}