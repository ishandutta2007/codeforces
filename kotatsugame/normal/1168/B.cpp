#include<cstdio>
#include<cstring>
using namespace std;
char S[3<<17];
int N;
int R[3<<17];
const int LIM=20;
main()
{
	scanf("%s",S);
	N=strlen(S);
	for(int i=0;i<N;i++)
	{
		R[i]=N;
		for(int r=i+2;r<N&&r-i<LIM;r+=2)
		{
			if(S[i]==S[r]&&S[i]==S[(i+r)/2])
			{
				R[i]=r;
				break;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		int rm=R[i];
		for(int j=0;j<LIM&&i+j<N;j++)if(rm>R[i+j])rm=R[i+j];
		ans+=N-rm;
	}
	printf("%lld\n",ans);
}