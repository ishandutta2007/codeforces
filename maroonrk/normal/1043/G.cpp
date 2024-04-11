#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

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

//TKPPC G
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

//CF530F
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

//ARC 055 C
//res[0]=n,res[n]=0
template<class S>
vi zalgo(const S&s){
	int n=s.size();
	vi res(n+1,0);
	int j=0;
	rng(i,1,n)
		if(j+res[j]>i+res[i-j])
			res[i]=res[i-j];
		else{
			res[i]=max(int(0),j+res[j]-i);
			while(i+res[i]<n&&s[res[i]]==s[i+res[i]])
				res[i]++;
			j=i;
		}
	res[0]=n;
	return res;
}

//MW 2019 Day2 J
template<class S>
struct EnumRun{
	const S&s;
	int n;
	vvc<pi> run;
	vc<tuple<int,int,int>> sub(const S&x,const S&y){
		S p=x;reverse(all(p));
		S q=y;
		q.insert(q.end(),all(x));
		q.insert(q.end(),all(y));
		vi zp=zalgo(p),zq=zalgo(q);
		vc<tuple<int,int,int>> res;
		rep(i,x.size()){
			int a=x.size()-i;
			int b=i-zp[a];
			int c=max(int(0),int(y.size())-zq[y.size()+i]);
			if(int(x.size()+y.size())-b-c>=2*a)
				res.eb(a,b,c);
		}
		return res;
	}
	void rec(int l,int r){
		if(r-l<=1)return;
		int m=(l+r)/2;
		S x(s.bg+l,s.bg+m),y(s.bg+m,s.bg+r);
		{
			auto z=sub(x,y);
			for(auto w:z){
				int a,b,c;
				tie(a,b,c)=w;
				run[a].eb(l+b,r-c);
			}
		}
		reverse(all(x));
		reverse(all(y));
		{
			auto z=sub(y,x);
			for(auto w:z){
				int a,b,c;
				tie(a,b,c)=w;
				run[a].eb(l+c,r-b);
			}
		}
		rec(l,m);
		rec(m,r);
	}
	EnumRun(const S&ss):s(ss),n(s.size()),run(n+1){
		rec(0,n);
		rng(i,1,n+1){
			sort(all(run[i]),[&](pi a,pi b){
				return pi(a.a,-a.b)<pi(b.a,-b.b);
			});
			int mx=-1;
			vc<pi> tmp;
			for(auto p:run[i])
				if(mx<p.b){
					tmp.pb(p);
					mx=p.b;
				}
			run[i]=tmp;
		}
	}
};

template<class S>
vvc<pi> enum_run(const S&s){
	return EnumRun<S>(s).run;
}

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}

//AOJGRL5C
template<class t,class u>
struct sparsetable{
	vvc<t> a;
	u f;
	//d must not be empty
	sparsetable(const vc<t>& d,u ff):f(ff){
		int n=d.size(),h=topbit(n);
		a.resize(h+1);
		a[0]=d;
		rng(j,1,h+1){
			a[j].resize(n-(1<<j)+1);
			rep(i,n-(1<<j)+1)
				a[j][i]=f(a[j-1][i],a[j-1][i+(1<<(j-1))]);
		}
	}
	t get(int b,int e){
		assert(b<e);
		int d=topbit(e-b);
		return f(a[d][b],a[d][e-(1<<d)]);
	}
};

struct ysp{
	vi h,buf;
	using t=tuple<int,int,int,int*>;
	vc<t> qs;
	int idx(int x){
		return lower_bound(all(h),x,greater<int>())-h.bg;
	}
	void ap(int a,int b){
		if(b<0)return;
		h.pb(a);
		buf.pb(a+b);
	}
	void qr(int a,int b,int*d){
		if(b<0)return;
		int i=idx(a),j=idx(a-b-1);
		if(i==j)return;
		qs.eb(i,j,a,d);
	}
	void calc(){
		if(buf.empty())return;
		auto im=[&](int a,int b){return max(a,b);};
		auto s=sparsetable<int,decltype(im)>(buf,im);
		for(auto w:qs){
			int l,r,m,*d;
			tie(l,r,m,d)=w;
			if(s.get(l,r)>=m)*d=1;
		}
	}
};

//CF530F
//CodeChef Persistent Oak
//AOJ GRL5C
template<class E>
struct HLD{
	vvc<E> g;
	int n,rt,cnt;
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
	HLD(const vvc<E>&gg,int rr):g(gg),n(g.size()),rt(rr),cnt(0),
		sub(n,1),in(n),out(n),par(n,-1),head(n),dep(n){
		dfs1(rt,-1,0);
		dfs2(rt,rt);
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
	void dfs(int v,int l){
		len[v]=l;
		for(auto e:g[v])
			dfs(e,l+e.r-e.l);
	}
	void slv(string s,SA sa){
		len.resize(n);
		dfs(rt,0);
		
		vvc<int> num(26,vi(sa.n+1));
		rep(k,26){
			rep(i,sa.n)
				num[k][i+1]=num[k][i]+(s[i]-'a'==k);
		}
		
		int q;cin>>q;
		vvc<pi> q1(n);
		vc<pi> q2(q);
		rep(i,q){
			int l,r;cin>>l>>r;
			l--;
			q1[l].eb(r,i);
			q2[i]=pi(l,r);
		}
		
		vc<ysp> ys(n);
		vi has(q,0);
		per(i,sa.n){
			int x=sa.as[i];
			while(x!=-1){
				int h=head[x];
				int base=(h==rt?0:len[par[h]])+1;
				for(auto w:q1[i])
					ys[h].qr(w.a,len[x]-base,&has[w.b]);
				ys[h].ap(i+base,len[x]-base);
				x=par[h];
			}
		}
		
		rep(i,n)ys[i].calc();
		
		dmp(has);
		
		auto runs=enum_run(s);
		vi mnl(sa.n+1,sa.n+1),mnr(sa.n+1,sa.n+1);
		{
			const auto waf=[&](vi&x,set<int>&y,int l,int r,int v){
				auto itr=y.lower_bound(l);
				while(itr!=y.ed&&*itr<r){
					x[*itr]=v;
					itr=y.erase(itr);
				}
			};
			set<int> ls,rs;
			rep(i,sa.n+1){
				ls.insert(i);
				rs.insert(i);
			}
			rng(w,1,sa.n+1){
				for(auto lr:runs[w]){
					int l,r;tie(l,r)=lr;
					dmp(w);
					dmp(l);
					dmp(r);
					waf(mnl,ls,l,r-w*2+1,w*2);
					waf(mnr,rs,l+w*2,r+1,w*2);
				}
			}
		}
		dmp(mnl);
		dmp(mnr);
		
		vi rlim(sa.n);
		rep(i,sa.n)
			rlim[i]=i+mnl[i];
		auto im=[](int x,int y){return min(x,y);};
		auto st=sparsetable<int,decltype(im)>(rlim,im);
		
		rep(i,q){
			int l,r;tie(l,r)=q2[i];
			int c[26];
			rep(k,26)
				c[k]=num[k][r]-num[k][l];
			int ans;
			if(*max_element(c,c+26)==1){
				ans=-1;
			}else{
				ans=4;
				if(c[s[l]-'a']>1||c[s[r-1]-'a']>1||st.get(l+1,r)<=r-1){
					ans=3;
					int w=r-l;
					if(has[i]||mnl[l]<=w||mnr[r]<=w){
						ans=2;
						const auto check=[&](int z){
							if(w==z)return false;
							int j=lower_bound(all(runs[z]),pi(l,sa.n+1))-runs[z].bg;
							if(j==0)return false;
							j--;
							return runs[z][j].a<=l&&r<=runs[z][j].b;
						};
						for(int j=1;j*j<=w;j++)
							if(w%j==0){
								if(check(j)||check(w/j)){
									ans=1;
									break;
								}
							}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	string s;cin>>s;
	
	auto sa=SA(s);
	auto t=stree(sa);
	
	HLD<ste>(t.a,t.b).slv(s,sa);
}