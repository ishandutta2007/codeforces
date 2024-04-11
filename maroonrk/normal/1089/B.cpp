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

//NEERC2018B
//Petrozavodsk 2019w Day1 A
struct maxmatching{
	struct E{int a,b;};
	const vvc<int>&g;
	int n,sz;
	vi p,t,mt;
	vc<E> f;
	int non(int v){
		return t[v]!=sz||p[v]==-1?v:(p[v]=non(p[v]));
	}
	void R(int a,int b){
		int d=mt[a];
		mt[a]=b;
		if(d==-1||mt[d]!=a)return;
		if(f[a].b==-1){
			mt[d]=f[a].a;
			R(f[a].a,d);
		}else{
			R(f[a].a,f[a].b);
			R(f[a].b,f[a].a);
		}
	}
	bool arg(int rt){
		queue<int> q;
		t[rt]=sz;
		p[rt]=-1;
		f[rt]=E{-1,-1};
		q.push(rt);
		while(!q.empty()){
			int a=q.front();q.pop();
			for(auto b:g[a]){
				if(b==rt)continue;
				if(mt[b]==-1){
					mt[b]=a;
					R(a,b);
					return true;
				}
				if(t[b]==sz){
					int x=non(a),y=non(b);
					if(x==y)continue;
					int z=rt;
					while(x!=rt||y!=rt){
						if(y!=rt)swap(x,y);
						if(f[x].a==a&&f[x].b==b){
							z=x;
							break;
						}
						f[x]=E{a,b};
						x=non(f[mt[x]].a);
					}
					for(auto v:{non(a),non(b)}){
						while(v!=z){
							t[v]=sz;
							p[v]=z;
							q.push(v);
							v=non(f[mt[v]].a);
						}
					}
					continue;
				}
				if(t[mt[b]]==sz)continue;
				f[b]=E{-1,-1};
				t[mt[b]]=sz;
				p[mt[b]]=b;
				f[mt[b]]=E{a,-1};
				q.push(mt[b]);
			}
		}
		return false;
	}
	maxmatching(const vvc<int>&gg):g(gg),n(g.size()),sz(0),
		p(n),t(n,-1),mt(n,-1),f(n){
		rep(i,n)if(mt[i]==-1)
			sz+=arg(i);
	}
};

void S(){
	int n,m;cin>>n>>m;
	vvc<int> g(n*2+m);
	auto ae=[&](int a,int b){
		g[a].pb(b);
		g[b].pb(a);
	};
	rep(i,n){
		ae(i*2,i*2+1);
		string s;cin>>s;
		rep(j,m)if(s[j]=='1'){
			rep(k,2)
				ae(i*2+k,n*2+j);
		}
	}
	cout<<maxmatching(g).sz-n<<endl;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)S();
}