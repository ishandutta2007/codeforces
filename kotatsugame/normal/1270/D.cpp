#include<cstdio>
#include<cstdlib>
#include<utility>
using namespace std;
int N,K;
pair<int,int>ask(int out,int in)
{
	printf("?");
	for(int i=1;i<=K;i++)
	{
		if(i!=out)printf(" %d",i);
	}
	if(1<=out&&out<=K)printf(" %d",in);
	printf("\n");
	fflush(stdout);
	pair<int,int>ret;
	scanf("%d%d",&ret.first,&ret.second);
	return ret;
}
int w[555];
main()
{
	scanf("%d%d",&N,&K);
	pair<int,int>p=ask(0,0);
	w[p.first]=0;
	for(int i=K+1;i<=N;i++)
	{
		pair<int,int>q=ask(p.first,i);
		w[q.first]=q.second>p.second?1:-1;
		if(q.first!=i)
		{
			if(q.second>p.second)w[i]=1;
			else w[i]=-1;
		}
	}
	for(int i=1;i<=K;i++)
	{
		if(i==p.first)continue;
		pair<int,int>q=ask(i,N);
		if(w[N]==1)
		{
			if(q.second==p.second)w[i]=1;
			else if(q.second>p.second)w[i]=-1;
		}
		else
		{
			if(q.second==p.second)w[i]=-1;
			else if(q.second<p.second)w[i]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=K;i++)
	{
		if(i==p.first)continue;
		cnt+=w[i]==-1;
	}
	printf("! %d\n",cnt+1);
	fflush(stdout);
	return 0;
}