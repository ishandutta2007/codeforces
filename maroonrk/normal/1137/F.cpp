#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(a>b)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}

struct BIT{
	vi buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
	void add(int i,int v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	int get(int i){
		int res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	int sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
};

//Caution: g is rooted!
//CF530F
//CodeChef Persistent Oak
//AOJ GRL5C
template<class E>
struct HLD{
	vvc<E> g;
	int n,r,cnt;
	vi sub,in,out,par,head,dep;
	int dfs1(int v,int p,int d){
		par[v]=p;
		dep[v]=d;
		g[v].erase(remove(all(g[v]),p),g[v].ed);
		for(auto&e:g[v]){
			sub[v]+=dfs1(e,v,d+1);
			if(sub[g[v][0]]<sub[e])
				swap(g[v][0],e);
		}
		return sub[v];
	}
	void dfs2(int v,int h){
		in[v]=cnt++;
		head[v]=h;
		for(int to:g[v])
			dfs2(to,to==g[v][0]?h:to);
		out[v]=cnt;
	}
	HLD(const vvc<E>&gg,int rr):g(gg),n(g.size()),r(rr),cnt(0),
		sub(n,1),in(n),out(n),par(n,-1),head(n),dep(n){
		dfs1(r,-1,0);
		dfs2(r,r);
	}
	int lca(int a,int b){
		while(head[a]!=head[b]){
			if(dep[head[a]]>dep[head[b]])
				swap(a,b);
			b=par[head[b]];
		}
		if(dep[a]>dep[b])
			swap(a,b);
		return a;
	}
	void slv(int q){
		set<int> ss;
		vi to(n),h(n),up(n);
		//et index
		const auto add=[&](int b,int e,int v,int x){
			to[b]=e;
			h[b]=v;
			up[b]=x;
			ss.insert(b);
		};
		{
			vi deg(n);
			priority_queue<int,vi,greater<int>> pq;
			rep(i,n){
				deg[i]=g[i].size();
				if(deg[i]==0)
					pq.push(i);
			}
			int c=0;
			vi idx(n,-1);
			while(pq.size()){
				int i=pq.top();pq.pop();
				idx[i]=c++;
				if(par[i]!=-1&&--deg[par[i]]==0)
						pq.push(par[i]);
			}
			rep(i,n)add(in[i],in[i]+1,idx[i],1);
		}
		ss.insert(n);
		//et index
		const auto getitr=[&](int i){
			return prev(ss.upper_bound(i));
		};
		const auto getval=[&](int i){
			auto itr=getitr(i);
			int j=*itr;
			int v=h[j]+(i-j)*up[j];
			return v;
		};
		const auto cut=[&](int i){
			auto itr=getitr(i);
			int j=*itr;
			if(j==i)return;
			int v=h[j]+(i-j)*up[j];
			add(i,to[j],v,up[j]);
			to[j]=i;
		};
		int nx=n;
		vc<pi> del;
		const auto repl=[&](int b,int e,int v){
			if(e<=b)return;
			cut(b);
			cut(e);
			auto itr=ss.find(b);
			while(*itr<e){
				int i=*itr,z=h[i];
				if(up[i]<0)z-=(to[i]-i-1);
				del.eb(z,i-to[i]);
				itr=ss.erase(itr);
			}
			add(b,e,v==1?nx:nx+(e-b)-1,v);
			nx+=e-b;
		};
		const auto getpath=[&](int a,int b){
			vc<pi> res;
			int c=lca(a,b);
			while(1){
				int x=head[a];
				if(dep[x]>dep[c]){
					res.eb(in[a],in[x]);
				}else{
					res.eb(in[a],in[c]);
					break;
				}
				a=par[x];
			}
			int m=res.size();
			while(1){
				int x=head[b];
				if(dep[x]>dep[c]){
					res.eb(in[x],in[b]);
				}else{
					if(in[c]<in[b])
						res.eb(in[c]+1,in[b]);
					break;
				}
				b=par[x];
			}
			reverse(res.bg+m,res.ed);
			return res;
		};
		int last=n-1;
		vi ans(q,-1);
		rep(i,q){
			string ty;cin>>ty;
			if(ty=="up"){
				int v;cin>>v;v--;
				if(last==v)continue;
				auto p=getpath(last,v);
				for(auto w:p){
					int a,b;tie(a,b)=w;
					if(a<b)
						repl(a,b+1,1);
					else
						repl(b,a+1,-1);
				}
				last=v;
			}else if(ty=="when"){
				int v;cin>>v;v--;
				int x=getval(in[v]);
				ans[i]=x;
				del.eb(x,i);
			}else{
				int u,v;cin>>u>>v;u--;v--;
				dmp(getval(u));
				dmp(getval(v));
				ans[i]=getval(in[u])<getval(in[v])?u:v;
			}
		}
		vi pos;
		for(auto d:del)
			pos.pb(d.a);
		sort(all(pos));
		pos.erase(unique(all(pos)),pos.ed);
		BIT bit(pos.size());
		for(auto d:del){
			int i=lower_bound(all(pos),d.a)-pos.bg;
			if(d.b<0){
				bit.add(i,d.b);
			}else{
				ans[d.b]+=bit.get(i);
			}
		}
		for(auto v:ans)if(v!=-1)
			cout<<v+1<<"\n";
	}
};


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,q;cin>>n>>q;
	
	vvc<int> t(n);
	rep(_,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		t[a].pb(b);
		t[b].pb(a);
	}
	
	HLD<int>(t,n-1).slv(q);
}