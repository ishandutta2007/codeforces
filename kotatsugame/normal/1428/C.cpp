#include<cstdio>
using namespace std;
int T,N;
char s[2<<17];
main()
{
	scanf("%d\n",&T);
	for(;T--;)
	{
		scanf("%s\n",s);
		N=0;
		while(s[N]!='\0')N++;
		int ans=0,Bc=0;
		for(int i=N;i--;)
		{
			if(s[i]=='B')Bc++;
			else
			{
				if(Bc>0)Bc--;
				else ans++;
			}
		}
		ans+=Bc%2;
		printf("%d\n",ans);
	}
}