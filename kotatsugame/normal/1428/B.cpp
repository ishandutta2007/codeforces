#include<cstdio>
using namespace std;
int T,N;
char s[3<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d\n%s",&N,s);
		bool a=false,b=false;
		for(int i=0;i<N;i++)
		{
			if(s[i]=='<')a=true;
			if(s[i]=='>')b=true;
		}
		if(!a||!b)printf("%d\n",N);
		else
		{
			int cnt=0;
			for(int i=0;i<N;i++)
			{
				if(s[i]=='-'||s[(i+N-1)%N]=='-')cnt++;
			}
			printf("%d\n",cnt);
		}
	}
}