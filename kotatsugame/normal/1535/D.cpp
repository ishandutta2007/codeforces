#include<cstdio>
#include<algorithm>
using namespace std;
int k;
char S[1<<19];
int L[1<<19],R[1<<19],C[1<<19];
main()
{
	scanf("%d%s",&k,S);
	for(int i=0;i<1<<k;i++)
	{
		C[(1<<k)-1+i]=1;
	}
	reverse(S,S+(1<<k)-1);
	for(int i=(1<<k)-1;i--;)
	{
		L[i]=C[i*2+1];
		R[i]=C[i*2+2];
		if(S[i]=='0')C[i]=R[i];
		else if(S[i]=='1')C[i]=L[i];
		else C[i]=L[i]+R[i];
	}
	int Q;scanf("%d",&Q);
	for(;Q--;)
	{
		int i;char c;
		scanf("%d %c",&i,&c);
		i--;
		i=(1<<k)-2-i;
		S[i]=c;
		while(true)
		{
			L[i]=C[i*2+1];
			R[i]=C[i*2+2];
			if(S[i]=='0')C[i]=R[i];
			else if(S[i]=='1')C[i]=L[i];
			else C[i]=L[i]+R[i];
			if(i==0)break;
			i=(i-1)/2;
		}
		printf("%d\n",C[0]);
	}
}