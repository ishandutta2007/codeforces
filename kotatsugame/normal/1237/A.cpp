#include<cstdio>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	bool flag=false;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		int ans;
		if(A%2==0)ans=A/2;
		else
		{
			if(flag)A=(A+1)/2;
			else A=(A-1)/2;
			ans=A;
			flag=!flag;
		}
		printf("%d\n",ans);
	}
}