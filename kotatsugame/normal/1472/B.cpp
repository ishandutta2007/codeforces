#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int c1=0,c2=0;
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			if(a==1)c1++;
			else c2++;
		}
		if(c1%2==1)puts("NO");
		else if(c1==0&&c2%2==1)puts("NO");
		else puts("YES");
	}
}