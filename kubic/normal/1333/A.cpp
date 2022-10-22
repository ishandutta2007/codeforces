#include <bits/stdc++.h>
using namespace std;
int T,n,m;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=m;++j)
			if(i==1 && j==1) putchar('W');else putchar('B');
	}return 0;
}