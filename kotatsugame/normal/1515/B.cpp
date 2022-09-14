#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int T,N;
bool iss(int n)
{
	int s=sqrt(n)-1;
	if(s<0)s=0;
	while(s*s<n)s++;
	return s*s==n;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		if(N%2==1)
		{
			puts("NO");
			continue;
		}
		N/=2;
		puts(iss(N)||N%2==0&&iss(N/2)?"YES":"NO");
	}
}