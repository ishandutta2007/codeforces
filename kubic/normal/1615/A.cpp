#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,s;
void slv()
{
	scanf("%d",&n);s=0;
	for(int i=1,x;i<=n;++i) scanf("%d",&x),s+=x; 
	printf("%d\n",s%n?1:0);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}