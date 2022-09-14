#include<cstdio>
#include<algorithm>
using namespace std;
int N;
char S[1<<20];
int C[1<<20],M[1<<20];
main()
{
	scanf("%d%s",&N,S);
	if(N%2)
	{
		puts("0");
		return 0;
	}
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		if(S[i]=='(')cnt++;
		else cnt--;
		C[i+1]=cnt;
	}
	M[N]=C[N];
	for(int i=N;i--;)
	{
		M[i]=min(C[i],M[i+1]);
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(C[i]<0)break;
		if(S[i]=='(')
		{
			if(M[i+1]>=2&&cnt==2)ans++;
		}
		else
		{
			if(M[i+1]>=-2&&cnt==-2)ans++;
		}
	}
	printf("%d\n",ans);
}