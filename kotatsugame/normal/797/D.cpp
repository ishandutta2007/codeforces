#include<iostream>
#include<set>
using namespace std;
int N;
int V[1<<17],L[1<<17],R[1<<17];
bool hsp[1<<17];
set<int>ret;
void mg(set<int>&A,set<int>&B)
{
	if(A.size()<B.size())A.swap(B);
	for(int p:B)A.insert(p);
}
void dfs(int u)
{
	set<int>tmp;
	tmp.insert(V[u]);
	if(L[u]>=0)
	{
		dfs(L[u]);
		while(!ret.empty()&&*ret.rbegin()>=V[u])ret.erase(prev(ret.end()));
		mg(tmp,ret);
	}
	if(R[u]>=0)
	{
		dfs(R[u]);
		while(!ret.empty()&&*ret.begin()<=V[u])ret.erase(ret.begin());
		mg(tmp,ret);
	}
	ret.swap(tmp);
}
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>V[i]>>L[i]>>R[i];
		if(L[i]>0)
		{
			L[i]--;
			hsp[L[i]]=true;
		}
		if(R[i]>0)
		{
			R[i]--;
			hsp[R[i]]=true;
		}
	}
	int root=0;
	while(hsp[root])root++;
	dfs(root);
	int ans=0;
	for(int i=0;i<N;i++)if(ret.find(V[i])==ret.end())ans++;
	cout<<ans<<endl;
}