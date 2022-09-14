#include<cstdio>
using namespace std;
int t,N;
int a[50050],b[50050];
char s[50050];
main()
{
	scanf("%d\n",&t);
	for(;t--;)
	{
		scanf("%d\n%s\n",&N,s);
		bool neq=false;
		for(int i=0;i<N;i++)
		{
			if(s[i]=='2')
			{
				if(neq)
				{
					a[i]=0;
					b[i]=2;
				}
				else
				{
					a[i]=b[i]=1;
				}
			}
			else if(s[i]=='1')
			{
				if(neq)
				{
					a[i]=0;
					b[i]=1;
				}
				else
				{
					a[i]=1;
					b[i]=0;
					neq=true;
				}
			}
			else a[i]=b[i]=0;
		}
		for(int i=0;i<N;i++)printf("%c",'0'+a[i]);
		printf("\n");
		for(int i=0;i<N;i++)printf("%c",'0'+b[i]);
		printf("\n");
	}
}