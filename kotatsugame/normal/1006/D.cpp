#include<cstdio>
#include<algorithm>
using namespace std;
int N;
char S[1<<17],T[1<<17];
main()
{
	scanf("%d%s%s",&N,S,T);
	int ans=0;
	if(N%2==1)
	{
		ans+=S[N/2]!=T[N/2];
	}
	for(int i=0;i<N/2;i++)
	{
		char a=S[i],b=S[N-i-1],c=T[i],d=T[N-i-1];
		if(c==d)
		{
			ans+=a!=b;
		}
		else
		{
			ans+=min((a!=c)+(b!=d),(a!=d)+(b!=c));
		}
	}
	printf("%d\n",ans);
}