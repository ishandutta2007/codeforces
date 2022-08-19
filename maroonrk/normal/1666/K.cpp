#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define pb push_back
#define eb emplace_back
#define si(x) int(x.size())
#define a first
#define b second
#define mp make_pair

template<class t>using vc=vector<t>;
template<class t>using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

void NO(){
	cout<<"NO"<<endl;
}

void YES(){
	cout<<"YES"<<endl;
}

template<class t>int lwb(const vc<t>&x,t v){
	return lower_bound(all(x),v)-x.bg;
}

const int inf=LLONG_MAX/3;

template<class d>
struct maxflow{
	struct E{
		int to,rev;
		d cap;
	};
	vvc<E> g;
	vi itr,lv,q;
	maxflow(int n):g(n),itr(n),lv(n),q(n){}
	int ae(int s,int t,d c){
		g[s].pb({t,si(g[t]),c});
		g[t].pb({s,si(g[s])-1,0});
		return si(g[s])-1;
	}
	void bfs(int s){
		fill(all(lv),-1);
		lv[s]=0;
		int l=0,r=0;
		q[r++]=s;
		while(l<r){
			int v=q[l++];
			for(auto e:g[v])if(e.cap>0&&lv[e.to]==-1){
				lv[e.to]=lv[v]+1;
				q[r++]=e.to;
			}
		}
	}
	d dfs(int v,int t,d f){
		if(v==t)return f;
		d res=0;
		for(int&i=itr[v];i<si(g[v]);i++){
			E&e=g[v][i];
			if(e.cap>0&&lv[e.to]==lv[v]+1){
				d a=dfs(e.to,t,min(f,e.cap));
				if(a>0){
					e.cap-=a;
					g[e.to][e.rev].cap+=a;
					res+=a;
					f-=a;
					if(f<=0)break;
				}
			}
		}
		return res;
	}
	d calc(int s,int t,d mx=inf){
		d f=0;
		while(f<mx){
			bfs(s);
			if(lv[t]==-1)return f;
			fill(all(itr),0);
			f+=dfs(s,t,mx-f);
		}
		return f;
	}
};

using ld=double;

void slv(){
	int n,m;cin>>n>>m;
	int a,b;cin>>a>>b;
	a--;b--;
	maxflow<int> mf(n*2+2);
	rep(_,m){
		int x,y,z;cin>>x>>y>>z;
		x--;y--;
		rep(k,2){
			int p=x*2+k,q=y*2+(k^1);
			mf.ae(p,q,z);
			mf.ae(q,p,z);
		}
	}
	mf.ae(n*2,a*2,inf);
	mf.ae(n*2,b*2+1,inf);
	mf.ae(a*2+1,n*2+1,inf);
	mf.ae(b*2,n*2+1,inf);
	int f=mf.calc(n*2,n*2+1);
	cout<<f<<endl;
	rep(i,n){
		bool x=mf.lv[i*2]!=-1;
		bool y=mf.lv[i*2+1]==-1;
		if(x==y){
			if(x){
				cout<<'A';
			}else{
				cout<<'B';
			}
		}else{
			cout<<'C';
		}
	}
	cout<<endl;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);
	
	//int t;cin>>t;
	int t=1;
	rep(_,t)slv();
}