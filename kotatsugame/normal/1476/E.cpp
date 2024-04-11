#include<cstdio>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int N,M,K;
const int off=28*28*28*28;
int pt[off];
char Pt[1<<17][6];
int T[1<<17];
char S[6];
int P[1<<17];
vector<int>G[1<<17];
int deg[1<<17];
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%s",Pt[i]);
		int t=0;
		for(int j=0;j<K;j++)
		{
			if(Pt[i][j]=='_')t=t*28+27;
			else t=t*28+Pt[i][j]-'a'+1;
		}
		T[i]=t;
		pt[t]=i+1;
	}
	for(int i=0;i<M;i++)
	{
		int mt;
		scanf("%s%d",S,&mt);
		mt--;
		for(int j=0;j<K;j++)
		{
			if(Pt[mt][j]!='_'&&Pt[mt][j]!=S[j])
			{
				puts("NO");
				return 0;
			}
		}
		for(int j=0;j<1<<K;j++)
		{
			int now=0;
			for(int k=0;k<K;k++)
			{
				if(j>>k&1)now=now*28+27;
				else now=now*28+S[k]-'a'+1;
			}
			if(pt[now]>0&&now!=T[mt])
			{
				G[mt].push_back(pt[now]-1);
				deg[pt[now]-1]++;
			}
		}
	}
	queue<int>Q;
	for(int i=0;i<N;i++)if(!deg[i])Q.push(i);
	int sz=0;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		P[sz++]=u;
		for(int v:G[u])if(!--deg[v])Q.push(v);
	}
	if(sz<N)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=0;i<N;i++)printf("%d%c",P[i]+1,i+1==N?10:32);
}