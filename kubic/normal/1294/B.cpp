#include <bits/stdc++.h>
using namespace std;
#define N 1005
int T,n;struct Point {int x,y;}a[N]; 
bool cmp(Point x,Point y) {return x.x==y.x?x.y<y.y:x.x<y.x;}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		bool fl=0;scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d %d",&a[i].x,&a[i].y);
		sort(a+1,a+n+1,cmp);
		for(int i=0;i<n;++i) if(a[i].y>a[i+1].y) {fl=1;puts("NO");break;}
		if(!fl)
		{
			puts("YES");
			for(int i=0;i<n;++i)
			{
				for(int j=a[i].x;j<a[i+1].x;++j) putchar('R');
				for(int j=a[i].y;j<a[i+1].y;++j) putchar('U');
			}puts("");
		}
	}return 0;
}