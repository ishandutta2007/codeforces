#include<cstdio>
using namespace std;
int N,X,Y;
char S[2<<17];
main()
{
	scanf("%d%d%d%s",&N,&X,&Y,S);
	int cnt=0;
	for(int i=0;i<X;i++)
	{
		if(S[N-i-1]!=(i==Y?'1':'0'))cnt++;
	}
	printf("%d\n",cnt);
}