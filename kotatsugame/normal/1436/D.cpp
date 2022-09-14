#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int N;
vector<int>G[2<<17];
int A[2<<17];
map<long long,int>ret;
void dfs(int u)
{
	map<long long,int>now;
	for(int v:G[u])
	{
		dfs(v);
		if(now.size()<ret.size())now.swap(ret);
		for(pair<long long,int>p:ret)
		{
			now[p.first]+=p.second;
		}
	}
	if(now.empty())
	{
		now[A[u]]=1;
	}
	else
	{
		while(A[u]>0)
		{
			map<long long,int>::iterator it=now.begin();
			pair<long long,int>p=*it;
			it=now.erase(it);
			if(it==now.end())
			{
				p.first+=A[u]/p.second;
				A[u]%=p.second;
				if(A[u]==0)
				{
					now[p.first]=p.second;
				}
				else
				{
					now[p.first]=p.second-A[u];
					now[p.first+1]=A[u];
					A[u]=0;
				}
			}
			else
			{
				long long up=it->first;
				long long diff=up-p.first;
				if(diff*p.second<=A[u])
				{
					A[u]-=diff*p.second;
					now[up]+=p.second;
				}
				else
				{
					p.first+=A[u]/p.second;
					A[u]%=p.second;
					if(A[u]==0)
					{
						now[p.first]+=p.second;
					}
					else
					{
						now[p.first]+=p.second-A[u];
						now[p.first+1]+=A[u];
						A[u]=0;
					}
				}
			}
		}
	}
	ret.swap(now);
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int p;scanf("%d",&p);
		G[p-1].push_back(i);
	}
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	dfs(0);
	map<long long,int>::iterator it=ret.end();
	if(it==ret.begin())puts("0");
	else
	{
		--it;
		printf("%lld\n",it->first);
	}
}