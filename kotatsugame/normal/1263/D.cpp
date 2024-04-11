#include<cstdio>
#include<cstdlib>
#include<cstring>
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
int N;
char s[2<<17][55];
int pre[26];
main()
{
	scanf("%d\n",&N);
	UF uf(N);
	int ans=N;
	for(int i=0;i<26;i++)pre[i]=-1;
	for(int i=0;i<N;i++)
	{
		scanf("%s\n",s[i]);
		int L=strlen(s[i]);
		for(int j=0;j<L;j++)
		{
			int c=s[i][j]-'a';
			if(pre[c]>=0&&pre[c]<i)
			{
				ans-=uf.unite(pre[c],i);
			}
			pre[c]=i;
		}
	}
	printf("%d\n",ans);
}