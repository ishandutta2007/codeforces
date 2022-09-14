#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int c=0;
		for(int i=0;i<2*N;i++)
		{
			int a;scanf("%d",&a);
			if(a%2==0)c++;
			else c--;
		}
		puts(c?"No":"Yes");
	}
}