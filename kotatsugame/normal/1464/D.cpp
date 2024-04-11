#line 1 "a.cpp"
#include<cstdio>
#include<algorithm>
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
#line 5 "a.cpp"
int T,N;
bool vis[1<<20];
int cnt[5];
const long long mod=1e9+7;
long long power(long long a,long long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
int add;
void calc(int x,int y,int z,int off=0)
{
	int now=off;
	now+=z;
	x+=z;
	if(x>=y)
	{
		now+=y;
		x-=y;
		now+=x/3*2;
	}
	else
	{
		now+=x;
		y-=x;
		now+=y;
	}
	if(add>now)add=now;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<5;i++)cnt[i]=0;
		{
			long long t;
			if(N%3==0)t=power(3,N/3);
			else if(N%3==1)t=power(3,N/3-1)*4%mod;
			else t=power(3,N/3)*2%mod;
			printf("%lld ",t);
		}
		UF uf(N);
		for(int i=0;i<N;i++)
		{
			vis[i]=false;
			int P;
			scanf("%d",&P);
			P--;
			uf.unite(i,P);
		}
		int ans=0;
		for(int i=0;i<N;i++)if(!vis[uf.find(i)])
		{
			vis[uf.find(i)]=true;
			int t=uf.size(i);
			while(t>4)
			{
				t-=3;
				ans++;
			}
			cnt[t]++;
		}
		add=1e9;
		if(N%3==0)
		{
			calc(cnt[1],cnt[2],cnt[4]);
		}
		else if(N%3==1)
		{
			if(cnt[2]>=2)
			{
				calc(cnt[1],cnt[2]-2,cnt[4]);
			}
			if(cnt[4]>=1)
			{
				calc(cnt[1],cnt[2],cnt[4]-1);
			}
			if(cnt[2]>=1&&cnt[1]>=2)
			{
				calc(cnt[1]-2,cnt[2]-1,cnt[4],1);
			}
			if(cnt[1]>=4)
			{
				calc(cnt[1]-4,cnt[2],cnt[4],2);
			}
			if(cnt[1]>=1)
			{
				calc(cnt[1]-1,cnt[2],cnt[4],1);
			}
		}
		else
		{
			if(cnt[2]>=1)
			{
				calc(cnt[1],cnt[2]-1,cnt[4]);
			}
			if(cnt[4]>=1)
			{
				calc(cnt[1],cnt[2]+1,cnt[4]-1,1);
			}
			if(cnt[1]>=2)
			{
				calc(cnt[1]-2,cnt[2],cnt[4],1);
			}
		}
		printf("%d\n",ans+add);
	}
}