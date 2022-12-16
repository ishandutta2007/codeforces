#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=5.1e5;
struct P{int a,b;};
struct Rec{
	vector<pair<P*,P> > v;
	vector<size_t> s;
	void set(P &x,P a){
		v.push_back(make_pair(&x,x));
		x=a;
	}
	void mark(){
		s.push_back(v.size());
	}
	void undo(){
		while(v.size()!=s.back()){
			pair<P*,P> p=v.back();
			*p.first=p.second;
			v.pop_back();
		}
		s.pop_back();
	}
}rec;

const int K=55;
struct UFS{
	P fa[N];
	UFS(){memset(fa,-1,sizeof(fa));}
	P find(int x){
		int d=0;
		while(fa[x].a>0){
			d^=fa[x].b;
			x=fa[x].a;
		}
		return (P){x,d};
	}
	bool merge(int x,int y,int d){
		P fx=find(x),fy=find(y);
		if(fx.a==fy.a){
			return (fx.b^fy.b)==d;
		}
		else{
			if(-fa[fx.a].a<-fa[fy.a].a)swap(fx,fy);
			rec.set(fa[fx.a],(P){fa[fx.a].a+fa[fy.a].a,-1});
			rec.set(fa[fy.a],(P){fx.a,fx.b^fy.b^d});
			return true;
		}
	}
}ufs[K];

int u[N],v[N],curC[N];
int e[N],c[N],ed[N];

int globalQ;
struct SegTree{
	V qs[N*4];
	void add(int l,int r,int q,int ll,int rr,int id){
		// if(id==1)cerr<<"add "<<l<<" "<<r<<" "<<q<<endl;
		if(l<=ll&&rr<=r)qs[id].push_back(q);
		else if(l<=rr&&ll<=r){
			int mid=(ll+rr)>>1;
			add(l,r,q,ll,mid,id*2);
			add(l,r,q,mid+1,rr,id*2+1);
		}
	}
	void dfs(int ll,int rr,int id){
		// cerr<<"mark"<<endl;
		rec.mark();
		D(i,qs[id].size()){
			int q=qs[id][i];
			int qe=e[q];
			// cerr<<"+ "<<q<<endl;
			if(c[q]!=-1)ufs[c[q]].merge(u[qe],v[qe],1);
		}
		qs[id].clear();
		if(ll==rr){
			int qe=e[ll];
			// cerr<<"attempt #"<<ll<<" e="<<qe<<" "<<u[qe]<<" "<<v[qe]<<" c="<<c[ll]<<endl;
			if(ufs[c[ll]].merge(u[qe],v[qe],1)){
				curC[qe]=c[ll];
				puts("YES");
			}
			else{
				c[ll]=curC[qe];
				puts("NO");
			}
			add(ll+1,ed[ll],ll,1,globalQ,1);
		}
		else{
			int mid=(ll+rr)>>1;
			dfs(ll,mid,id*2);
			dfs(mid+1,rr,id*2+1);
		}
		rec.undo();
		// cerr<<"undo"<<endl;
	}
}tr;

int main(){
	read();// n
	int m=read();
	read();// k
	int q=read();
	globalQ=q;
	F(i,1,m){
		u[i]=read();
		v[i]=read();
	}
	map<int,int> cur;
	F(i,1,q){
		e[i]=read();
		c[i]=read();
		ed[i]=q;
		if(cur.count(e[i])){
			ed[cur[e[i]]]=i;
		}
		cur[e[i]]=i;
	}
	memset(curC,-1,sizeof(curC));
	tr.dfs(1,q,1);
	return 0;
}