#include<iostream>
#include<cstdio>
using namespace std;
long long mod=1e6+3;
long long power(long long a,long long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
long long inv[1<<20];
long long A[11][11],Ai[11][11];
long long X[11],Y[11];
main()
{
	inv[1]=1;
	for(long long i=2;i<mod;i++)inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	for(long long i=0;i<11;i++)
	{
		printf("? %lld\n",i);
		fflush(stdout);
		scanf("%lld",&Y[i]);
		Ai[i][i]=1;
		long long P=1;
		for(long long j=0;j<11;j++)
		{
			A[i][j]=P;
			P=P*i%mod;
		}
	}
	for(int i=0;i<11;i++)
	{
		int id=i;
		while(A[id][i]==0)id++;
		if(i!=id)
		{
			for(int j=0;j<11;j++)
			{
				swap(A[i][j],A[id][j]);
				swap(Ai[i][j],Ai[id][j]);
			}
		}
		if(A[i][i]!=1)
		{
			long long p=inv[A[i][i]];
			for(int j=0;j<11;j++)
			{
				A[i][j]=A[i][j]*p%mod;
				Ai[i][j]=Ai[i][j]*p%mod;
			}
		}
		for(int j=0;j<11;j++)
		{
			if(j==i||A[j][i]==0)continue;
			long long p=A[j][i];
			for(int k=0;k<11;k++)
			{
				A[j][k]=(A[j][k]-A[i][k]*p%mod+mod)%mod;
				Ai[j][k]=(Ai[j][k]-Ai[i][k]*p%mod+mod)%mod;
			}
		}
	}
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)X[i]=(X[i]+Ai[i][j]*Y[j]%mod)%mod;
	}
	for(long long i=0;i<mod;i++)
	{
		long long now=0;
		long long p=1;
		for(int j=0;j<11;j++)
		{
			now=(now+p*X[j]%mod)%mod;
			p=p*i%mod;
		}
		if(now==0)
		{
			printf("! %lld\n",i);
			fflush(stdout);
			return 0;
		}
	}
	puts("! -1");
	fflush(stdout);
}