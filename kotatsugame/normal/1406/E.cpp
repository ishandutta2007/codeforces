#include<cstdio>
#include<vector>
using namespace std;
int ask(int k)
{
	printf("B %d\n",k);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int count(int k)
{
	printf("A %d\n",k);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int N;
bool isp[1<<17];
bool ex[1<<17];
vector<int>p;
const int X=90;
void check(int P,int id)
{
	int n=N/P;
	for(;p[id]<=n;)
	{
		if(count(p[id]*P))
		{
			check(p[id]*P,id);
			return;
		}
		id++;
	}
	printf("C %d\n",P);
}
main()
{
	scanf("%d",&N);
	for(int i=2;i<=N;i++)isp[i]=true;
	for(int i=1;i<=N;i++)ex[i]=true;
	for(int i=2;i<=N;i++)if(isp[i])
	{
		p.push_back(i);
		for(int j=i+i;j<=N;j+=i)isp[j]=false;
	}
	int id=0;
	while(id<p.size()&&p[id]*p[id]<=N)
	{
		ask(p[id]);
		if(count(p[id])==1)
		{
			check(p[id],id);
			return 0;
		}
		for(int j=p[id];j<=N;j+=p[id])ex[j]=false;
		id++;
	}
	int rest=0;
	for(int i=1;i<=N;i++)if(ex[i])rest++;
	while(id<p.size())
	{
		int from=id;
		int nowc=0;
		while(id<p.size()&&nowc<X)
		{
			ask(p[id]);
			id++;
			nowc++;
			rest--;
		}
		if(count(1)!=rest)
		{
			for(int j=from;j<id;j++)
			{
				if(count(p[j])==1)
				{
					printf("C %d\n",p[j]);
					fflush(stdout);
					return 0;
				}
			}
		}
	}
	printf("C 1\n");
	fflush(stdout);
}