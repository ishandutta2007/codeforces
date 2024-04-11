#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#include<vector>
struct UF{
	int n;
	vector<int>parent,rank;
	UF(int n_=0):n(n_),parent(n_),rank(n_,1)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a){return parent[a]!=a?parent[a]=find(parent[a]):a;}
	bool same(int a,int b){return find(a)==find(b);}
	bool unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(a==b)return false;
		if(rank[a]<rank[b])
		{
			parent[a]=b;
			rank[b]+=rank[a];
		}
		else
		{
			parent[b]=a;
			rank[a]+=rank[b];
		}
		return true;
	}
	int size(int a){return rank[find(a)];}
};
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<vector<int> >X(N);
		for(int i=0;i<N;i++)
		{
			int A;
			scanf("%d",&A);
			A--;
			X[A].push_back(i);
		}
		for(int i=0;i<N;i++)
		{
			int B;
			scanf("%d",&B);
			B--;
			X[B].push_back(N+i);
		}
		UF uf(N);
		bool out=false;
		vector<pair<int,int> >E;
		for(int i=0;i<N;i++)
		{
			if(X[i].size()!=2)
			{
				out=true;
				break;
			}
			int u=X[i][0],v=X[i][1];
			if(u/N==v/N)
			{
				E.push_back(make_pair(u%N,v%N));
			}
			else
			{
				uf.unite(u%N,v%N);
			}
		}
		vector<vector<int> >G(N);
		for(pair<int,int>e:E)
		{
			int u=uf.find(e.first),v=uf.find(e.second);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int>col(N,0);
		vector<int>ans;
		for(int i=0;i<N;i++)if(uf.find(i)==i&&col[i]==0)
		{
			queue<int>Q;
			Q.push(i);
			col[i]=2;
			vector<int>Xp,Yp;
			Xp.push_back(i);
			int Xc=uf.size(i),Yc=0;
			while(!Q.empty())
			{
				int u=Q.front();Q.pop();
				int nc=col[u]^1;
				for(int v:G[u])
				{
					if(col[v]!=0)
					{
						if(col[v]!=nc)
						{
							out=true;
						}
					}
					else
					{
						col[v]=nc;
						if(nc==2)
						{
							Xp.push_back(v);
							Xc+=uf.size(v);
						}
						else
						{
							Yp.push_back(v);
							Yc+=uf.size(v);
						}
						Q.push(v);
					}
				}
			}
			if(out)break;
			if(Xc<Yc)
			{
				for(int v:Xp)ans.push_back(v);
			}
			else
			{
				for(int v:Yp)ans.push_back(v);
			}
		}
		if(out)puts("-1");
		else
		{
			vector<int>asv;
			vector<bool>use(N,false);
			for(int v:ans)use[v]=true;
			for(int i=0;i<N;i++)if(use[uf.find(i)])asv.push_back(i);
			printf("%d\n",(int)asv.size());
			for(int i=0;i<asv.size();i++)
			{
				printf("%d",asv[i]+1);
				if(i+1<asv.size())printf(" ");
			}
			puts("");
		}
	}
}