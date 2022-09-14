#include<cstdio>
#include<cstring>
using namespace std;
char S[1010];
main()
{
	scanf("%s",S);
	int N=strlen(S);
	int a=0,b=0;
	for(int i=0;i<N;i++)
	{
		if(S[i]=='0')
		{
			if(a==0)
			{
				puts("1 4");
				a++;
			}
			else
			{
				puts("3 4");
				a=0;
			}
		}
		else
		{
			if(b==0)
			{
				puts("4 1");
				b++;
			}
			else
			{
				puts("4 3");
				b=0;
			}
		}
	}
}