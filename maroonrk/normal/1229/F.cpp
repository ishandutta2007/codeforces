#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
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
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

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

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))

using uint=unsigned;
using ull=unsigned long long;

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

void print(ll x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
int mask(int i){
	return (int(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

//push 
//clean  lazy 
//find 
//split  find  left 
// node rw 
// mg 
//ARC033 C
//AOJ DSL2G
template<class N,int S>
struct splaytree{
	struct N2{
		N rw,mg;
		using P=N2*;
		P l,r,p;
		N2():l(0),r(0),p(0){}
		void push(){
			mg.push(rw);
			if(l)mg.push(l->mg);
			if(r)mg.push(r->mg);
			mg.clean();
		}
		P upd(){
			mg=rw.parent();
			if(l)mg=N::merge(l->mg,mg);
			if(r)mg=N::merge(mg,r->mg);
			return this;
		}
		int pos(){
			if(p&&p->l==this)return -1;
			if(p&&p->r==this)return 1;
			return 0;
		}
		void prepare(){
			if(p)p->prepare();
			push();
		}
		void rotate(){
			P q=p,c;
			if(pos()==1){
				c=l;
				l=p;
				p->r=c;
			}else{
				c=r;
				r=p;
				p->l=c;
			}
			if(c)c->p=p;
			p=p->p;
			q->p=this;
			if(p&&p->l==q)p->l=this;
			if(p&&p->r==q)p->r=this;
			q->upd();
		}
		P splay(){
			prepare();
			while(p){
				int a=pos();
				if(p->p){
					if(a==p->pos())p->rotate();
					else rotate();
				}
				rotate();
			}
			return upd();
		}
		/*
		P right(){
			if(r)return r->right();
			else return splay();
		}*/
		P left(){
			if(l)return l->left();
			else return splay();
		}
		template<class F,class...Args>
		P find(F f,Args&&...args){
			if(!(mg.*f)(args...))return 0;
			push();
			P a=0;
			if(l)a=l->find(f,forward<Args>(args)...);
			if(a)return a;
			if((rw.*f)(args...))return splay();
			return r->find(f,forward<Args>(args)...);
		}
		P cutl(){
			if(l){
				l->p=0;
				l=0;
			}
			return upd();
		}
		P cutr(){
			if(r){
				r->p=0;
				r=0;
			}
			return upd();
		}
		P linkl(P x){
			assert(!l);
			l=x;
			if(x)x->p=this;
			return upd();
		}
		/*
		P linkr(){
			assert(!r);
			r=x;
			if(x)x->p=this;
			return upd();
		}*/
		void dfs(vc<N>&res){
			push();
			if(l)l->dfs(res);
			res.pb(rw);
			if(r)r->dfs(res);
		}
		vc<N> enumerate(){
			vc<N> res;
			dfs(res);
			return res;
		}
	} buf[S];
	using P=N2*;
	int head=0;
	template<class...Args>
	P nn(Args...args){
		P a=buf+head++;
		a->rw=N(args...);
		a->mg=a->rw.parent();
		return a;
	}
	template<class t>
	P build(vc<t> v){
		vc<P> cur;
		for(auto z:v)cur.pb(nn(z));
		while(cur.size()>1){
			int s=cur.size();
			vc<P> nx((s+1)/2);
			for(int i=0;i<s;i+=2){
				if(i+1<s)nx[i/2]=merge(cur[i],cur[i+1]);
				else nx[i/2]=cur[i];
			}
			swap(nx,cur);
		}
		return cur[0];
	}
	P merge(P a,P b){
		if(!a)return b;
		if(!b)return a;
		return b->splay()->left()->linkl(a->splay());
	}
	template<class F,class...Args>
	pair<P,P> split(P a,F f,Args&&...args){
		if(!a)return {0,0};
		P b=a->find(f,forward<Args>(args)...);
		if(b){
			P c=b->l;
			return {c,b->cutl()};
		}
		return {a,0};
	}
};

// add,sum
struct N{
	int v,p,lz;
	N(int vv=0,int pp=0):v(vv),p(pp),lz(0){}
	N parent(){
		return N(v,p);
	}
	static N merge(N a,N b){
		return N(a.v+b.v,b.p);
	}
	void add(int vv){
		lz+=vv;
		p+=vv;
	}
	void push(N&x){
		x.add(lz);
	}
	void clean(){
		lz=0;
	}
	bool findval(int&x){
		if(x<=v)return true;
		x-=v;
		return false;
	}
	bool findpos(int x){
		return x<=p;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi a(n),l(n),r(n);
	rep(i,n)cin>>a[i]>>l[i]>>r[i];
	
	const int v=2000000000;
	
	int ans=inf;
	auto calc=[&](int st){
		int val=st*(st<0?a[0]-r[0]:a[0]-l[0]);
		int left=-n;
		val+=(st-left)*v;
		left--;
		int cur=-v;
		
		using T=splaytree<N,100010>;
		using P=T::P;
		T t;
		P root=t.merge(t.nn(v,st-1),t.nn(v,st+1));
		
		rng(i,1,n){
			{
				val+=left*(a[i]-r[i]);
				cur+=a[i]-r[i];
				P x,y;tie(x,y)=t.split(root,&N::findpos,0);
				root=t.merge(x,t.merge(t.nn(r[i]-l[i],0),y));
			}
			{
				left--;
				int tmp=-cur;
				P x,y,z;
				y=root->find(&N::findval,tmp);
				assert(y);
				x=y->l,z=y->r;
				y->cutl(),y->cutr();
				
				int pos=y->rw.p;
				y->rw.v-=tmp;
				y->rw.p++;
				
				if(x)x->mg.add(-1);
				if(z)z->mg.add(1);
				root=t.merge(t.merge(x,t.nn(tmp,pos-1)),t.merge(y,z));
			}
		}
		
		auto res=root->enumerate();
		val+=(st-left)*cur;
		for(auto z:res){
			if(z.p<st){
				val+=(st-z.p)*z.v;
			}
		}
		
		chmin(ans,val);
		return val;
	};
	int lw=-n,up=n;
	while(up-lw>=3){
		int m1=(lw+lw+up)/3;
		int m2=(lw+up+up)/3;
		if(calc(m1)<calc(m2))
			up=m2;
		else
			lw=m1;
	}
	rng(i,lw,up+1)calc(i);
	
	cout<<-ans<<endl;
}