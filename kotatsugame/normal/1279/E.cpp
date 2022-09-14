#include<cstdio>
using namespace std;
int t;
long long A[55],dp[55],p[55];
int ans[55];
main()
{
	p[0]=1;
	for(long long i=1;i<=50;i++)
	{
		p[i]=i<=20?p[i-1]*i:-1;
	}
	A[0]=1;
	for(int i=0;i<50;i++)
	{
		for(int j=i+1;j<=50;j++)
		{
			long long P=j-i>=2?p[j-i-2]:1;
			if(A[i]==-1)
			{
				A[j]=-1;
			}
			else if(P==-1)
			{
				A[j]=-1;
			}
			else if(A[i]>1.5e18/P)
			{
				A[j]=-1;
			}
			else if(A[j]!=-1)
			{
				A[j]+=A[i]*P;
				if(A[j]>1.5e18)A[j]=-1;
			}
		}
	}
	scanf("%d",&t);
	for(;t--;)
	{
		int N;long long K;
		scanf("%d%lld",&N,&K);
		K--;
		bool used[55]={};
		bool out=false;
		for(int i=0;i<N;)
		{
			int j=i+1;
			long long x=0;
			while(K>=0)
			{
				if(N<j)
				{
					out=true;
					break;
				}
				long long sub=A[N-j];
				long long P=j-i>=2?p[j-i-2]:1;
				if(sub==-1||sub>=1.5e18/P)
				{
					if(sub==-1)x=0;
					else
					{
						x=K/sub;
						K%=sub;
					}
					break;
				}
				else if(sub*P>K)
				{
					x=K/sub;
					K%=sub;
					break;
				}
				K-=sub*P;
				j++;
			}
			if(out)break;
			ans[i]=j;
			used[j]=true;
			for(int k=i+2;k<j;k++)
			{
				int pos=k-1;
				for(int a=1;;a++)
				{
					if(a>N)
					{
						out=true;
						break;
					}
					if(used[a])continue;
					int now=a;
					while(now<k)now=ans[now-1];
					if(now==k)continue;
					long long rest=p[j-k-1];
					if(rest!=-1&&x>=rest)x-=rest;
					else
					{
						used[a]=true;
						ans[pos]=a;
						break;
					}
				}
				if(out)break;
			}
			if(out)break;
			if(i+2<=j)for(int a=1;;a++)if(!used[a])
			{
				used[a]=true;
				ans[j-1]=a;
				break;
			}
			i=j;
		}
		if(out)puts("-1");
		else
		{
			for(int i=0;i<N;i++)printf("%d%c",ans[i],i==N-1?'\n':' ');
		}
	}
}