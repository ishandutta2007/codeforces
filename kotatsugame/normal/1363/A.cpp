#include<cstdio>
using namespace std;
int T,N,X;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&X);
		int od=0,ev=0;
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			if(A%2==0)ev++;
			else od++;
		}
		if(od==0)puts("No");
		else
		{
			od--;
			X--;
			if(X%2==0)
			{
				puts(ev+od/2*2<X?"No":"Yes");
			}
			else
			{
				puts(ev==0||ev+od/2*2<X?"No":"Yes");
			}
		}
	}
}