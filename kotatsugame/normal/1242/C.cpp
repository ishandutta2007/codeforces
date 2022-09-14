#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int K;
int N[15],A[15][5000];
long long S[15];
long long allsum;
map<int,int>M;
vector<vector<pair<int,int> > >Ys;
bool dp[1<<15];
int parent[1<<15];
int exs[1<<15];
vector<int>can[15];
int main()
{
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d",&N[i]);
		for(int j=0;j<N[i];j++)
		{
			scanf("%d",&A[i][j]);
			S[i]+=A[i][j];
			M[A[i][j]]=i;
		}
		allsum+=S[i];
	}
	if(allsum%K!=0)
	{
		puts("No");
		return 0;
	}
	allsum/=K;
	for(int i=0;i<1<<K;i++)exs[i]=-1;
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<N[i];j++)
		{
			int now=1<<i;
			long long want=allsum-S[i]+A[i][j];
			vector<pair<int,int> >Y;
			Y.push_back(make_pair(i,A[i][j]));
			while(want!=A[i][j])
			{
				if(want!=(long long)(int)want||M.find(want)==M.end())break;
				int id=M[want];
				if(now>>id&1)break;
				Y.push_back(make_pair(id,want));
				now|=1<<id;
				want=allsum-S[id]+want;
			}
			if(want==A[i][j]&&exs[now]<0)
			{
				exs[now]=Ys.size();
				Ys.push_back(Y);
				for(pair<int,int>p:Y)
				{
					can[p.first].push_back(now);
				}
			}
		}
	}
	dp[0]=true;
	parent[0]=-1;
	for(int i=0;i<1<<K;i++)
	{
		if(!dp[i])continue;
		for(int j=0;j<K;j++)
		{
			if(i>>j&1)continue;
			for(int x:can[j])
			{
				if(x&i)continue;
				dp[i|x]=true;
				parent[i|x]=i;
			}
		}
	}
	int pos=(1<<K)-1;
	if(!dp[pos])
	{
		puts("No");
		return 0;
	}
	vector<pair<int,int> >ans(K);
	while(pos>0)
	{
		int i=parent[pos];
		int id=exs[pos&~i];
		for(int j=0;j<Ys[id].size();j++)
		{
			ans[Ys[id][j].first]=make_pair(Ys[id][j].second,Ys[id][(j+Ys[id].size()-1)%Ys[id].size()].first);
		}
		pos=i;
	}
	puts("Yes");
	for(int i=0;i<K;i++)printf("%d %d\n",ans[i].first,ans[i].second+1);
}