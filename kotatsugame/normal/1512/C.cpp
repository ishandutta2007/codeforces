#include<cstdio>
using namespace std;
int T,A,B;
char S[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%s",&A,&B,S);
		int N=A+B;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='0')A--;
			if(S[i]=='1')B--;
		}
		for(int i=0;i<N;i++)if(S[i]=='?')
		{
			int j=N-i-1;
			if(S[j]!='?')
			{
				if(S[j]=='0')A--;
				else B--;
				S[i]=S[j];
			}
		}
		if(N%2==1)
		{
			int mid=N/2;
			if(S[mid]=='?')
			{
				if(A%2==1)A--,S[mid]='0';
				else B--,S[mid]='1';
			}
		}
		for(int i=0;i<N;i++)if(S[i]=='?')
		{
			int j=N-i-1;
			if(A>=2)
			{
				A-=2;
				S[i]=S[j]='0';
			}
			else
			{
				B-=2;
				S[i]=S[j]='1';
			}
		}
		bool ok=A==0&&B==0;
		for(int i=0;i<N;i++)if(S[i]!=S[N-i-1])ok=false;
		puts(ok?S:"-1");
	}
}