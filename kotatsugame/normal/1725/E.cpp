#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#include<iostream>
#include<utility>
template<int m>
struct modint{
	unsigned int x;
	constexpr modint()noexcept:x(){}
	template<typename T>
	constexpr modint(T x_)noexcept:x((x_%=m)<0?x_+m:x_){}
	constexpr unsigned int val()const noexcept{return x;}
	constexpr modint&operator++()noexcept{if(++x==m)x=0;return*this;}
	constexpr modint&operator--()noexcept{if(x==0)x=m;--x;return*this;}
	constexpr modint operator++(int)noexcept{modint res=*this;++*this;return res;}
	constexpr modint operator--(int)noexcept{modint res=*this;--*this;return res;}
	constexpr modint&operator+=(const modint&a)noexcept{x+=a.x;if(x>=m)x-=m;return*this;}
	constexpr modint&operator-=(const modint&a)noexcept{if(x<a.x)x+=m;x-=a.x;return*this;}
	constexpr modint&operator*=(const modint&a)noexcept{x=(unsigned long long)x*a.x%m;return*this;}
	constexpr modint&operator/=(const modint&a)noexcept{return*this*=a.inv();}
	constexpr modint operator+()const noexcept{return*this;}
	constexpr modint operator-()const noexcept{return modint()-*this;}
	constexpr modint pow(long long n)const noexcept
	{
		if(n<0)return pow(-n).inv();
		modint x=*this,r=1;
		for(;n;x*=x,n>>=1)if(n&1)r*=x;
		return r;
	}
	constexpr modint inv()const noexcept
	{
		int s=x,t=m,x=1,u=0;
		while(t)
		{
			int k=s/t;
			s-=k*t;
			swap(s,t);
			x-=k*u;
			swap(x,u);
		}
		return modint(x);
	}
	friend constexpr modint operator+(const modint&a,const modint&b){return modint(a)+=b;}
	friend constexpr modint operator-(const modint&a,const modint&b){return modint(a)-=b;}
	friend constexpr modint operator*(const modint&a,const modint&b){return modint(a)*=b;}
	friend constexpr modint operator/(const modint&a,const modint&b){return modint(a)/=b;}
	friend constexpr bool operator==(const modint&a,const modint&b){return a.x==b.x;}
	friend constexpr bool operator!=(const modint&a,const modint&b){return a.x!=b.x;}
	friend ostream&operator<<(ostream&os,const modint&a){return os<<a.x;}
	friend istream&operator>>(istream&is,modint&a){long long v;is>>v;a=modint(v);return is;}
};
#include<vector>
struct LCA{
	int N;
	vector<vector<int> >G,parent;
	vector<int>depth;
	vector<int>dfsord;
	vector<int>ord;
	LCA(int N_=0):N(N_),G(N_),depth(N_),ord(N_)
	{
		int lg=0;
		while((1<<lg)+1<N_)lg++;
		parent.assign(lg+1,vector<int>(N_));
	}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void dfs(int u,int p,int d)
	{
		depth[u]=d;
		parent[0][u]=p;
		ord[u]=dfsord.size();
		dfsord.push_back(u);
		for(int v:G[u])if(v!=p)dfs(v,u,d+1);
	}
	void build(int root=0)
	{
		dfs(root,-1,0);
		for(int k=1;k<parent.size();k++)
		{
			for(int i=0;i<N;i++)
			{
				if(parent[k-1][i]==-1)parent[k][i]=-1;
				else parent[k][i]=parent[k-1][parent[k-1][i]];
			}
		}
	}
	int lca(int u,int v)
	{
		if(depth[u]>depth[v])swap(u,v);
		for(int k=0;k<parent.size();k++)if(depth[v]-depth[u]>>k&1)v=parent[k][v];
		if(u==v)return u;
		for(int k=parent.size();k--;)if(parent[k][u]!=parent[k][v])
		{
			u=parent[k][u];
			v=parent[k][v];
		}
		return parent[0][u];
	}
	int dist(int u,int v)
	{
		int w=lca(u,v);
		return depth[u]+depth[v]-2*depth[w];
	}
};
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
using mint=modint<998244353>;
int N;
int isp[2<<17];
vector<int>vs[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=2;i<2<<17;i++)if(isp[i]==0)
	{
		for(int j=i;j<2<<17;j+=i)isp[j]=i;
	}
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		while(a>1)
		{
			int p=isp[a];
			vs[p].push_back(i);
			while(a%p==0)a/=p;
		}
	}
	LCA P(N);
	for(int i=1;i<N;i++)
	{
		int u,v;cin>>u>>v;u--,v--;
		P.add_edge(u,v);
	}
	P.build();
	mint ans=0;
	const mint inv2=mint(1)/2;
	for(int p=1;p<2<<17;p++)if(vs[p].size()>=3)
	{
		sort(vs[p].begin(),vs[p].end(),[&P](int u,int v){return P.ord[u]<P.ord[v];});
		int n=vs[p].size();
		UF uf(n);
		vector<int>L(n,-1),R(n,n);
		vector<pair<int,pair<int,int> > >Q;
		for(int i=0;i+1<n;i++)
		{
			L[i+1]=i;
			R[i]=i+1;
			int w=P.lca(vs[p][i],vs[p][i+1]);
			Q.push_back(make_pair(-P.depth[w],make_pair(i,w)));
		}
		sort(Q.begin(),Q.end());
		for(pair<int,pair<int,int> >q:Q)
		{
			int l=uf.find(q.second.first);
			int r=R[l];
			int w=q.second.second;
			{
				mint c=uf.size(l);
				mint d=vs[p].size()-c;
				ans+=(c*d*(d-1)+c*(c-1)*d)*inv2*(P.depth[vs[p][l]]-P.depth[w]);
			}
			{
				mint c=uf.size(r);
				mint d=vs[p].size()-c;
				ans+=(c*d*(d-1)+c*(c-1)*d)*inv2*(P.depth[vs[p][r]]-P.depth[w]);
			}
			//merge(l,r)
			uf.unite(l,r);
			int u=uf.find(l);
			vs[p][u]=w;
			L[u]=L[l];R[u]=R[r];
			if(L[u]>=0)R[L[u]]=u;
			if(R[u]<n)L[R[u]]=u;
		}
	}
	cout<<ans<<endl;
}