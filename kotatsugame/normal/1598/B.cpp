#include<cstdio>
using namespace std;
int T,N;
int A[1000];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			A[i]=0;
			for(int j=0;j<5;j++)
			{
				int c;scanf("%d",&c);
				A[i]=A[i]*2|c;
			}
		}
		bool fn=false;
		for(int i=0;i<5;i++)for(int j=i+1;j<5;j++)
		{
			int a=0,b=0,c=0;
			bool out=false;
			for(int k=0;k<N;k++)
			{
				int x=A[k]>>i&1,y=A[k]>>j&1;
				if(x&&y)a++;
				else if(x)b++;
				else if(y)c++;
				else out=true;
			}
			if(out)continue;
			if(N%2==0&&b<=N/2&&c<=N/2)fn=true;
		}
		puts(fn?"YES":"NO");
	}
}