#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	scanf("%d %d",&n,&m);printf("%d\n",(n*6-1)*m);
	for(int i=1,t;i<=n;++i)
	{
		t=(i-1)*6+1;
		printf("%d %d %d %d\n",t*m,(t+1)*m,(t+2)*m,(t+4)*m);
	}return 0;
}