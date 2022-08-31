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

//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n):p(n,-1),s(n,1),c(n){}
	int find(int a){
		return p[a]==-1?a:(p[a]=find(p[a]));
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
};

struct SA{
	int n;
	vi sa,as,lcp;
	template<class t> SA(t s):n(s.size()),sa(n),as(n),lcp(n-1){
		rep(i,n)sa[i]=n-1-i;
		stable_sort(all(sa),[&](int a,int b){return s[a]<s[b];});
		vi c(n);
		rep(i,n)c[i]=s[i];
		for(int w=1;w<n;w*=2){
			vi d(c);
			rep(i,n){
				if(i&&sa[i-1]+w<n&&d[sa[i-1]]==d[sa[i]]&&d[sa[i-1]+w/2]==d[sa[i]+w/2])
					c[sa[i]]=c[sa[i-1]];
				else
					c[sa[i]]=i;
			}
			vi e(sa),f(n);
			iota(all(f),0);
			rep(i,n){
				int j=e[i]-w;
				if(j>=0)sa[f[c[j]]++]=j;
			}
		}
		//as
		rep(i,n)as[sa[i]]=i;
		//lcp
		int w=0;
		for(auto i:as){
			if(w)w--;
			if(i<n-1){
				while(max(sa[i],sa[i+1])+w<n&&s[sa[i]+w]==s[sa[i+1]+w])w++;
				lcp[i]=w;
			}
		}
	}
};

//returns the suffix tree
//the first n elements correspond to the suffixes
struct ste{
	int to,l,r;
	operator int()const{return to;}
};
ostream&operator<<(ostream&os,const ste&a){
	return os<<"ste{"<<a.to<<","<<a.l<<" "<<a.r<<"}";
}
pair<vvc<ste>,int> stree(const SA&sa){
	int n=sa.n,s=n*2-1;
	vi len(s);
	rep(i,n)len[i]=n-sa.sa[i];
	rep(i,n-1)len[i+n]=sa.lcp[i];
	vi idx(n-1);
	iota(all(idx),n);
	stable_sort(all(idx),[&](int a,int b){return len[a]>len[b];});
	unionfind uf(s);
	vi par(s,-1),c(s,-1);
	rep(i,n)c[i]=sa.sa[i];
	for(auto i:idx){
		int a=uf.find(i-n),b=uf.find(i-n+1);
		uf.unite(i,a);
		uf.unite(i,b);
		par[a]=i;
		par[b]=i;
		c[i]=c[a];
	}
	par[n==1?0:idx.back()]=s++;
	len.pb(0);
	uf=unionfind(s);
	rep(i,s-1)if(len[i]==len[par[i]])
		uf.unite(i,par[i]);
	vi vs;
	rep(i,s)if(uf.find(i)==i)vs.pb(i);
	auto z=[&](int i){return lower_bound(all(vs),uf.find(i))-vs.bg;};
	vvc<ste> res(vs.size());
	rep(ii,s-1){
		int i=ii/2+ii%2*n;
		int a=z(i),b=z(par[i]);
		if(a==b)continue;
		res[b].pb(ste{a,c[i]+len[par[i]],c[i]+len[i]});
	}
	return make_pair(res,z(s-1));
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

const int maxq=200010;
int ans[maxq];

struct Q{
	signed a,b,c,d;
	bool operator<(const Q&r)const{return a<r.a;}
};

void sgm(int n,vc<Q> qs){
	sort(all(qs));
	BIT a(n),b(n);
	for(auto q:qs){
		if(q.d==-1){
			a.add(q.b,q.c);
			b.add(q.b,-int(q.a)*q.c);
		}else{
			ans[q.d]+=a.sum(q.b,q.c)*q.a+b.sum(q.b,q.c);
		}
	}
}

struct ysp{
	vi h;
	int find(int i){
		return lower_bound(all(h),i,greater<int>())-h.bg;
	}
	vc<Q> q1,q2;
	void add(int a,int b){
		int i=h.size();
		h.pb(a);
		q1.pb(Q{a,i,1,-1});
		q1.pb(Q{a+b,i,-1,-1});
		q2.pb(Q{0,i,1,-1});
		q2.pb(Q{b,i,-1,-1});
	}
	void query(int a,int b,int c){
		int i=find(a),j=find(a-b),k=h.size();
		q1.pb(Q{a,i,j,c});
		q2.pb(Q{b,j,k,c});
	}
	void calc(){
		sgm(h.size(),q1);
		sgm(h.size(),q2);
	}
};

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
	vi len;
	void dfs(int v,int d){
		len[v]=d;
		for(auto e:g[v])
			dfs(e,d+e.r-e.l);
	}
	void slv(SA sa){
		len.resize(n);
		dfs(r,0);
		
		int q;cin>>q;
		vvc<pi> w(sa.n);
		rep(i,q){
			int a,b;cin>>a>>b;
			a--;
			w[a].eb(b,i);
		}
		
		vc<ysp> m(n);
		per(i,sa.n){
			int x=sa.as[i];
			while(x!=-1){
				int h=head[x],nx=par[h];
				int b=nx==-1?0:len[nx];
				m[h].add(i+b,len[x]-b);
				for(auto z:w[i])
					m[h].query(z.a,len[x]-b,z.b);
				x=nx;
			}
		}
		rep(i,n)
			m[i].calc();
		
		rep(i,q)
			cout<<ans[i]<<"\n";
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	string s;cin>>s;
	auto sa=SA(s);
	auto t=stree(sa);
	
	auto hld=HLD<ste>(t.a,t.b);
	hld.slv(sa);
}