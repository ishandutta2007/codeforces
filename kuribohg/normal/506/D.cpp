#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
#include<cmath>
#include<map>
using namespace std;
const int MAXN=200010;
map<pair<int,int>,int> M;
vector<pair<int,int> > E[MAXN];
vector<int> V;
int n,m,Q,K,fa[MAXN],X[MAXN],Y[MAXN];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void uni(int i,int j){fa[find(i)]=find(j);}
int main()
{
	scanf("%d%d",&n,&m);
	K=sqrt(n);
	for(int i=1,x,y,c;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		E[c].push_back(make_pair(x,y));
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		if(X[i]>Y[i]) swap(X[i],Y[i]);
		M.insert(make_pair(make_pair(X[i],Y[i]),0));
	}
	for(int col=1;col<=m;col++)
		if(E[col].size()!=0)
		{
			if(E[col].size()>K)
			{
				for(int i=1;i<=n;i++) fa[i]=i;
				for(int j=0;j<E[col].size();j++)
					uni(E[col][j].first,E[col][j].second);
				for(map<pair<int,int>,int>::iterator it=M.begin();it!=M.end();it++)
					if(find((it->first).first)==find((it->first).second)) it->second++;
			}
			else
			{
				V.clear();
				for(int j=0;j<E[col].size();j++)
					V.push_back(E[col][j].first),V.push_back(E[col][j].second);
				sort(V.begin(),V.end());
				V.resize(unique(V.begin(),V.end())-V.begin());
				for(int j=0;j<V.size();j++) fa[V[j]]=V[j];
				for(int j=0;j<E[col].size();j++)
					uni(E[col][j].first,E[col][j].second);
				for(int i=0;i<V.size();i++)
					for(int j=0;j<V.size();j++)
					{
						if(find(V[i])!=find(V[j])) continue;
						pair<int,int> tmp=make_pair(V[i],V[j]);
						map<pair<int,int>,int>::iterator it=M.find(tmp);
						if(it==M.end()) continue;
						it->second++;
					}
			}
		}
	for(int i=1;i<=Q;i++) printf("%d\n",M.find(make_pair(X[i],Y[i]))->second);
	return 0;
}