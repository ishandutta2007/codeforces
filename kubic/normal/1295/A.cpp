#include <bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf(n&1?"7":"1");for(int i=1;i<n>>1;++i) printf("1");puts("");
	}return 0;
}