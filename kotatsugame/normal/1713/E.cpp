#include<iostream>
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
int A[1000][1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>A[i][j];
		UF uf(2*N);
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
		{
			if(A[i][j]<A[j][i])
			{
				if(uf.same(j,i+N)||uf.same(i,j+N))continue;
				uf.unite(i,j);
				uf.unite(i+N,j+N);
			}
			else if(A[i][j]>A[j][i])
			{
				if(uf.same(i,j)||uf.same(i+N,j+N))continue;
				uf.unite(i,j+N);
				uf.unite(j,i+N);
			}
		}
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
		{
			if(uf.same(i,j)||uf.same(i+N,j+N));
			else swap(A[i][j],A[j][i]);
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)cout<<A[i][j]<<(j+1==N?"\n":" ");
		}
	}
}