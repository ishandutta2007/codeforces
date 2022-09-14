#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
char S[2020];
int N;
int comb[2020][2020];
int p2[2020];
main()
{
	scanf("%s",S);
	N=strlen(S);
	comb[0][0]=1;
	for(int i=1;i<=N;i++)
	{
		comb[i][0]=comb[i][i]=1;
		for(int j=1;j<i;j++)
		{
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
			if(comb[i][j]>=mod)comb[i][j]-=mod;
		}
	}
	p2[0]=1;
	for(int i=1;i<=N;i++)
	{
		p2[i]=p2[i-1]*2;
		if(p2[i]>=mod)p2[i]-=mod;
	}
	int cnt=0;
	for(int i=0;i<N;i++)if(S[i]=='?')cnt++;
	int ans=0;
	int p=0,a=0;
	for(int i=0;i<N;i++)if(S[i]=='('||S[i]=='?')
	{
		int q=p,b=0;
		int rest=cnt-a;
		if(S[i]=='?')rest--;
		for(int j=N-1;j>i;j--)if(S[j]==')'||S[j]=='?')
		{
			if(S[j]=='?')rest--;
			int L=0,R=a;
			if(L<-q)L=-q;
			if(R>b-q)R=b-q;
			int now=0;
			for(int k=L;k<=R;k++)
			{
				now+=(long long)comb[a][k]*comb[b][k+q]%mod;
				if(now>=mod)now-=mod;
			}
			ans+=(long long)now*p2[rest]%mod;
			if(ans>=mod)ans-=mod;
			if(S[j]==')')q--;
			else b++;
		}
		if(S[i]=='(')p++;
		else a++;
	}
	printf("%d\n",ans);
}