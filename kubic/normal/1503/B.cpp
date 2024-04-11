#include <bits/stdc++.h>
using namespace std;
#define N 105
int n,a[N][N];
void f(int x,int y,int w)
{
	a[x][y]=w;printf("%d %d %d\n",w,x,y);
	fflush(stdout);
}
bool chk(int x,int y,int w)
{return !a[x][y] && a[x-1][y]!=w && a[x][y-1]!=w && a[x+1][y]!=w && a[x][y+1]!=w;}
bool find(int w)
{
	for(int x=1;x<=n;++x) for(int y=1;y<=n;++y)
		if(chk(x,y,w)) {f(x,y,w);return 1;}return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,w;i<=n*n;++i)
	{
		scanf("%d",&w);
		if(w>1) {if(find(1)) continue;find(5-w);}
		else {if(find(2)) continue;find(3);}
	}return 0;
}