#include <bits/stdc++.h>
using namespace std;
#define N 32
#define clz __builtin_clz
int n,m,x,y;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0,t;i<n;++i,putchar('\n'))
		for(int j=1;j<n;++j)
			t=31-clz(j&-j),printf("%d ",1<<t*2+1);
	for(int i=1,t;i<n;++i,putchar('\n'))
		for(int j=0;j<n;++j)
			t=31-clz(i&-i),printf("%d ",1<<t*2);
	fflush(stdout);
	for(int i=1,w;i<=m;++i)
	{
		scanf("%d",&w);
		for(int j=4;j>=0;--j)
		{
			if(w>>j*2&1) x^=(1<<j+1)-1;
			if(w>>j*2+1&1) y^=(1<<j+1)-1;
		}printf("%d %d\n",x+1,y+1);fflush(stdout);
	}return 0;
}