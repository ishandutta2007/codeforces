#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n;
struct Point {int x,y;}a[N];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d %d",&a[i].x,&a[i].y);if(n&1) {puts("NO");return 0;}
	for(int i=2;i<=(n>>1);++i)
		if(a[i].x+a[i+(n>>1)].x!=a[i-1].x+a[i-1+(n>>1)].x || a[i].y+a[i+(n>>1)].y!=a[i-1].y+a[i-1+(n>>1)].y)
		{puts("NO");return 0;}
	puts("YES");return 0;
}