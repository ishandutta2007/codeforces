#line 1 "a.cpp"
#include<cstdio>
using namespace std;
#line 1 "/home/kotatsugame/library/datastructure/UF.cpp"
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
#line 4 "a.cpp"
int N,M;
char S[1010][1010];
int d[5]={0,1,0,-1};
int usd[1010*1010];
main()
{
	scanf("%d%d\n",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)S[i][j]=getchar();
		getchar();
	}
	UF uf(N*M);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(S[i][j]=='.')
	{
		for(int r=0;r<4;r++)
		{
			int tx=i+d[r],ty=j+d[r+1];
			if(tx<0||ty<0||tx>=N||ty>=M||S[tx][ty]=='*')continue;
			uf.unite(i*M+j,tx*M+ty);
		}
	}
	int tm=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(S[i][j]=='.')putchar('.');
			else
			{
				tm++;
				int cnt=1;
				for(int r=0;r<4;r++)
				{
					int tx=i+d[r],ty=j+d[r+1];
					if(tx<0||ty<0||tx>=N||ty>=M||S[tx][ty]=='*')continue;
					int id=uf.find(tx*M+ty);
					if(usd[id]==tm)continue;
					usd[id]=tm;
					cnt+=uf.size(tx*M+ty);
				}
				putchar('0'+cnt%10);
			}
		}
		putchar(10);
	}
}