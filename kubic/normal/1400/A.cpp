#include <bits/stdc++.h>
using namespace std;
#define N 10005
int T,n;char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %s",&n,a+1);
		for(int i=1;i<=n;++i) putchar(a[n]);puts("");
	}return 0;
}