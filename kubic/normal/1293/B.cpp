#include <bits/stdc++.h>
using namespace std;
#define db double
int n;db ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) ans+=1.0/i;
	printf("%.10lf\n",ans);
	return 0;
}