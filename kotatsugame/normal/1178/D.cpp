#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool isp[1<<20];
int N;
vector<int>G[1000];
int cnt;
void add_edge(int u,int v)
{
	cnt++;
	G[u].push_back(v);
	G[v].push_back(u);
}
main()
{
	scanf("%d",&N);
	if(N==7)
	{
		puts("7");
		puts("1 2");
		puts("2 3");
		puts("3 4");
		puts("4 5");
		puts("5 6");
		puts("6 7");
		puts("7 1");
		return 0;
	}
	for(int i=2;i<1<<20;i++)isp[i]=1;
	for(int i=2;i<1<<20;i++)
	{
		if(isp[i])
		{
			for(int j=i+i;j<1<<20;j+=i)isp[j]=0;
		}
	}
	for(int i=0;i+5<N;i+=3)
	{
		add_edge(i,i+1);
		add_edge(i+1,i+2);
		add_edge(i+2,i);
	}
	if(N%3==0)
	{
		add_edge(N-3,N-2);
		add_edge(N-2,N-1);
		add_edge(N-1,N-3);
	}
	else if(N%3==1)
	{
		add_edge(N-4,N-3);
		add_edge(N-3,N-2);
		add_edge(N-2,N-1);
		add_edge(N-1,N-4);
		add_edge(N-4,N-2);
	}
	else
	{
		add_edge(N-5,N-4);
		add_edge(N-4,N-3);
		add_edge(N-3,N-2);
		add_edge(N-2,N-1);
		add_edge(N-1,N-5);
	}
	int id=0;
	while(!isp[cnt])
	{
		add_edge(id,id+3);
		id++;
		if(id%3==0)id+=3;
	}
	printf("%d\n",cnt);
	for(int i=0;i<N;i++)
	{
		for(int v:G[i])if(i<v)printf("%d %d\n",i+1,v+1);
	}
}