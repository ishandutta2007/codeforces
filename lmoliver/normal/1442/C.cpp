#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int MOD=998244353;
typedef pair<int,int> P;
P operator+(P a,P b){
	return {a.first+b.first,a.second+b.second};
}
int mv(P p){
	int ans=p.second;
	int w=1;
	D(_,p.first){
		ans=(ans+w)%MOD;
		w=(w<<1)%MOD;
	}
	return ans;
}

const int N=200200;
struct E{
	int v;
	P w;
};
const int L=20;
const int NS=N*(L+2);
vector<E> es[NS];
void ae(int u,int v,P w){
	es[u].push_back({v,w});
}
int u[N],v[N];
int n=read(),m=read();
int id(int x,int l){
	return x+l*n;
}
P dis[NS];
bool vis[NS];
int main(){
	F(i,1,m){
		u[i]=read();
		v[i]=read();
	}
	F(i,0,L+1){
		if(i&1)F(j,1,m)ae(id(v[j],i),id(u[j],i),{0,1});
		else F(j,1,m)ae(id(u[j],i),id(v[j],i),{0,1});
	}
	F(i,0,L+1){
		if(i==L+1)F(j,1,n)ae(id(j,i),id(j,i-1),{1,0});
		else F(j,1,n)ae(id(j,i),id(j,i+1),{1,0});
	}
	typedef pair<P,int> X;
	priority_queue<X,vector<X>,greater<X>> pq;
	dis[id(1,0)]={0,0};
	pq.push({{0,0},1});
	vis[id(1,0)]=true;
	while(!pq.empty()){
		X p=pq.top();
		pq.pop();
		int x=p.second;
		// cerr<<x<<endl;
		P dx=p.first;
		if(dx!=dis[x])continue;
		for(E e:es[x]){
			P td=dx+e.w;
			if(!vis[e.v]||td<dis[e.v]){
				dis[e.v]=td;
				pq.push({td,e.v});
				vis[e.v]=true;
			}
		}
	}
	bool ol=false;
	D(i,L)if(vis[id(n,i)])ol=true;
	// F(i,0,L+1)if(vis[id(n,i)])cerr<<i<<" "<<dis[id(n,i)].first<<" "<<dis[id(n,i)].second<<endl;
	// cerr<<boolalpha<<ol<<endl;
	int ans=MOD-1;
	if(ol){
		D(i,L)if(vis[id(n,i)])ans=min(ans,mv(dis[id(n,i)]));
	}
	else{
		P pp{1e9,1e9};
		F(i,L,L+1)if(vis[id(n,i)])pp=min(pp,dis[id(n,i)]);
		ans=mv(pp);
	}
	printf("%d\n",ans);
	return 0;
}