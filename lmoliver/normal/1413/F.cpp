#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=5.1e5;
V es[N];

int dis[N];
int dfn[N];
int dfe[N];
void dfs(int x,int fa){
	static int dft;
	if(fa==-1)dft=0;
	dfn[x]=++dft;
	dis[x]=fa==-1?0:dis[fa]+1;
	D(i,es[x].size()){
		int v=es[x][i];
		if(v==fa)continue;
		dfs(v,x);
	}
	dfe[x]=dft;
}

struct SegTree{
	int dis[4*N][2];
	bool flag[4*N];
	void build(const int *a,int ll,int rr,int id){
		if(ll==rr){
			dis[id][0]=a[ll];
			dis[id][1]=INT_MIN;
			flag[id]=false;
			return;
		}
		int mid=(ll+rr)>>1;
		build(a,ll,mid,id*2);
		build(a,mid+1,rr,id*2+1);
		D(i,2)dis[id][i]=max(dis[id*2][i^flag[id]],dis[id*2+1][i^flag[id]]);
	}
	void flip(int l,int r,int ll,int rr,int id){
		if(l<=ll&&r>=rr){
			flag[id]^=1;
			swap(dis[id][0],dis[id][1]);
			return;
		}
		if(r<ll||l>rr)return;
		int mid=(ll+rr)>>1;
		flip(l,r,ll,mid,id*2);
		flip(l,r,mid+1,rr,id*2+1);
		D(i,2)dis[id][i]=max(dis[id*2][i^flag[id]],dis[id*2+1][i^flag[id]]);
	}
};

int n;
int u[N],v[N],t[N];
struct Solver{
	int dis[N];
	int dfn[N];
	int dfe[N];
	SegTree tr;
	Solver(){
		// cerr<<::dis[1]<<endl;
		memcpy(dis,::dis,sizeof(dis));
		memcpy(dfn,::dfn,sizeof(dfn));
		memcpy(dfe,::dfe,sizeof(dfe));
		static int tmp[N];
		F(i,1,n)tmp[dfn[i]]=::dis[i];
		tr.build(tmp,1,n,1);
	}
	void edit(int u,int v){
		int c=dis[u]>dis[v]?u:v;
		tr.flip(dfn[c],dfe[c],1,n,1);
	}
	int query(){
		// cerr<<"f"<<tr.flag[1]<<endl;
		return tr.dis[1][tr.flag[1]];
	}
};

int main(){
	n=read();
	F(i,1,n-1){
		u[i]=read();
		v[i]=read();
		t[i]=read();
		es[u[i]].push_back(v[i]);
		es[v[i]].push_back(u[i]);
	}
	dfs(1,-1);
	int a=max_element(dis+1,dis+n+1)-dis;
	dfs(a,-1);
	int b=max_element(dis+1,dis+n+1)-dis;
	static Solver s1;
	dfs(b,-1);
	static Solver s2;
	// cerr<<a<<" "<<b<<endl;
	F(i,1,n-1)if(t[i]){
		s1.edit(u[i],v[i]);
		s2.edit(u[i],v[i]);
	};
	int m=read();
	D(_,m){
		int id=read();
		s1.edit(u[id],v[id]);
		s2.edit(u[id],v[id]);
		// cerr<<s1.query()<<" "<<s2.query()<<endl;
		int ans=max(s1.query(),s2.query());
		printf("%d\n",ans);
	}
	return 0;
}