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
		cout<<endl;
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
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

using ld=long double;
using cm=complex<ld>;
#define x real()
#define y imag()
const ld eps=1e-8;
const ld PI=acos(ld(-1));
int sgn(ld a){return a<-eps?-1:(a>eps?1:0);}
ld dot(cm a,cm b){return a.x*b.x+a.y*b.y;}
ld crs(cm a,cm b){return a.x*b.y-a.y*b.x;}
ld crs(cm a,cm b,cm c){return crs(b-a,c-a);}
int ccw(cm a,cm b){return sgn(crs(a,b));}
int ccw(cm a,cm b,cm c){return ccw(b-a,c-a);}
auto cmcmp=[](cm a,cm b){
	int s=sgn(a.x-b.x);
	if(s)return s<0;
	else return sgn(a.y-b.y)<0;
};
bool cmeq(cm a,cm b){
	return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;
};
//(-pi,0](0,pi]
int argtype(cm a){
	if(sgn(a.y)==0)return a.x<0?1:0;
	return a.y<0?0:1;
}
int argcmp(cm a,cm b){
	int at=argtype(a),bt=argtype(b);
	if(at!=bt)return at<bt?-1:1;
	return -ccw(a,b);
};
bool argless(cm a,cm b){return argcmp(a,b)<0;}
//(-2)[a,-1](0)[b,1](2)
int bet(cm a,cm b,cm c){
	cm d=b-a;
	ld e=dot(d,c-a);
	if(sgn(e)<=0)return sgn(e)-1;
	return sgn(e-norm(d))+1;
}
//AOJ1183
int qeq(ld a,ld b,ld c,ld&d,ld&e){
	ld f=b*b-4*a*c;
	if(sgn(f)<0)return 0;
	ld g=sqrt(max(f,ld(0)));
	d=(-b+g)/(2*a);
	e=(-b-g)/(2*a);
	return sgn(f)+1;
}
//AOJ0153
//0-no,1-edge,2-in
int cont(cm a,cm b,cm c,cm d){
	if(ccw(a,b,c)==-1)
		swap(b,c);
	return min({ccw(a,b,d),ccw(b,c,d),ccw(c,a,d)})+1;
}
//AOJ1183
//arg between ab
//assume given lengths are valid
ld arg(ld a,ld b,ld c){
	return acos(min(max((a*a+b*b-c*c)/(2*a*b),ld(-1)),ld(1)));
}
//AOJ2233
//a->b->c 
//a-b-c0
ld turn(cm a,cm b,cm c){
	return arg((c-b)/(b-a));
}
using ln=pair<cm,cm>;
cm dir(ln a){return a.b-a.a;}
cm eval(ln a,ld b){return a.a+dir(a)*b;}
int bet(ln a,cm b){return bet(a.a,a.b,b);}
int ccw(ln a,cm b){return ccw(a.a,a.b,b);}
cm proj(ln a,cm b){
	cm c=dir(a);
	return a.a+c*dot(c,b-a.a)/norm(c);
}
cm refl(ln a,cm b){
	return ld(2)*proj(a,b)-b;
}
//AOJ0153
ld dsp(ln a,cm b){
	cm c=proj(a,b);
	if(abs(bet(a.a,a.b,c))<=1)return abs(b-c);
	return min(abs(b-a.a),abs(b-a.b));
}
//AOJ1157
//0-no,1-yes(endpoint),2-yes(innner),3-overelap
int iss(ln a,ln b){
	int c1=ccw(a.a,a.b,b.a),c2=ccw(a.a,a.b,b.b);
	int d1=ccw(b.a,b.b,a.a),d2=ccw(b.a,b.b,a.b);
	if(c1||c2||d1||d2)return 1-max(c1*c2,d1*d2);
	int f=bet(a.a,a.b,b.a),g=bet(a.a,a.b,b.b);
	if(max(f,g)==-2||min(f,g)==2)return 0;
	return 3;
}
//AOJ1033
cm cll(ln a,ln b){
	return eval(a,crs(b.a,b.b,a.a)/crs(dir(a),dir(b)));
}
//AOJ1157
ld dss(ln a,ln b){
	if(iss(a,b))return 0;
	return min({dsp(a,b.a),dsp(a,b.b),dsp(b,a.a),dsp(b,a.b)});
}
//AOJ2160
//
ln vbis(cm a,cm b){
	cm c=(a+b)*ld(0.5),d=b-a;
	return ln(c,cm(c.x-d.y,c.y+d.x));
}
//AOJ1183
bool ips(const vc<cm>&a,ln b){
	int n=a.size();
	rep(i,n){
		cm c=a[(i+n-1)%n],d=a[i],e=a[(i+1)%n];
		if(iss(ln(c,d),b)==2)return 1;
		if(ccw(b,d)==0&&bet(b.a,b.b,d)==0){
			if(ccw(c,d,e)==1)return 1;
			if(ccw(b,c)*ccw(b,e)<0)return 1;
		}
	}
	return 0;
}

//GCJ2019R3D
//0-out,1-edge,2-in
int cont(const vc<cm>&a,cm b){
	int n=a.size();
	int res=0;
	rep(i,n){
		cm c=a[i],d=a[(i+1)%n];
		if(ccw(c,d,b)==0&&abs(bet(c,d,b))<=1)
			return 1;
		if(c.y>d.y)swap(c,d);
		if(sgn(b.y-c.y)>0&&sgn(d.y-b.y)>=0&&ccw(c,d,b)==1)
			res^=1;
	}
	return res*2;
}

ld area2(const vc<cm>&a){
	int n=a.size();
	ld b=0;
	rep(i,n)
		b+=crs(a[i],a[(i+1)%n]);
	return b;
}

//AOJ0068
//no point in edges
vc<cm> convex(vc<cm> s){
	swap(s[0],*min_element(all(s),cmcmp));
	sort(s.bg+1,s.ed,[&](cm a,cm b){
		int c=ccw(s[0],a,b);
		if(c)return c==1;
		else return bet(s[0],a,b)==2;
	});
	vc<cm> t;
	rep(i,s.size()){
		int ss;
		while((ss=t.size())>=2){
			cm a=t[ss-2];
			cm b=t[ss-1];
			cm c=s[i];
			if(ccw(a,b,c)>0)
				break;
			t.pop_back();
		}
		t.pb(s[i]);
	}
	return t;
}

//JAGSUMMER2019 E
//assume the ansewer is bounded
vc<cm> halfpint(vc<ln> s){
	sort(all(s),[&](ln a,ln b){
		int c=argcmp(dir(a),dir(b));
		if(c)return c<0;
		return ccw(b,a.a)>0;
	});
	s.erase(unique(all(s),[&](ln a,ln b){
		return argcmp(dir(a),dir(b))==0;
	}),s.ed);
	int n=s.size();
	vi cur;
	rep(ii,n*2){
		int i=ii%n,m;
		while((m=cur.size())>=2){
			if(ccw(s[i],cll(s[cur[m-2]],s[cur[m-1]]))>0)
				break;
			cur.pop_back();
		}
		cur.pb(i);
	}
	vi cnt(n);
	for(auto i:cur)cnt[i]++;
	vc<ln> t;
	rep(i,n)if(cnt[i]==2)
		t.pb(s[i]);
	int m=t.size();
	vc<cm> res(m);
	rep(i,m)
		res[i]=(cll(t[i],t[(i+1)%m]));
	return res;
}

//AOJ1283
//convex cut
vc<cm> ccut(vc<cm> a,ln b){
	int n=a.size();
	vc<cm> c;
	rep(i,n){
		int j=(i+1)%n;
		int d=ccw(b,a[i]),e=ccw(b,a[j]);
		if(d>=0)c.pb(a[i]);
		if(d*e<0)c.pb(cll(b,ln(a[i],a[j])));
	}
	return c;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,w,h;cin>>n>>w>>h;
	map<int,vc<cm>> z;
	
	int e1,e2;cin>>e1>>e2;
	cm st(e1,e2);
	
	rep(i,n){
		int t,a,b;cin>>t>>a>>b;
		z[t].pb(cm(a,b));
	}
	
	
	auto ch=[&](ln&a,ln b){
		if(ccw(b,a.a)<0&&ccw(b,a.b)<0)return false;
		else{
			if(ccw(b,a.a)<0)a.a=cll(a,b);
			if(ccw(b,a.b)<0)a.b=cll(a,b);
			return true;
		}
	};
	
	vc<pair<int,ln>> ps;
	ln bd[4]{ln(cm(0,0),cm(w,0)),ln(cm(w,0),cm(w,w)),ln(cm(w,w),cm(0,w)),ln(cm(0,w),cm(0,0))};
	for(auto kv:z){
		vc<cm> a=kv.b;
		/*if(a.size()>2){
			for(auto b:a){
				if(ccw(a[0],a[1],b)){
					cout<<-1<<endl;
					return 0;
				}
			}
			a.resize(2);
		}*/
		for(auto b:a){
			ps.eb(kv.a,ln(cm(0,b.x/b.y*h),cm(b.x/(h-b.y)*h,0)));
			rep(k,4)
				ch(ps.back().b,bd[k]);
		}
	}
	
	auto chk=[&](ld m){
		ln cur(st,st);
		int last=0;
		rep(i,n){
			ln nx=ps[i].b;
			ld v=m*(ps[i].a-last);
			if(!cmeq(cur.a,cur.b)){
				if(!ch(nx,ln(cur.a+cm(-v,-v),cur.b+cm(-v,-v))))return false;
				if(!ch(nx,ln(cur.b+cm(v,v),cur.a+cm(v,v))))return false;
			}
			if(!ch(nx,ln(cm(cur.a.x-v,w),cm(cur.a.x-v,0))))return false;
			if(!ch(nx,ln(cm(cur.b.x+v,0),cm(cur.b.x+v,w))))return false;
			if(!ch(nx,ln(cm(w,cur.a.y+v),cm(0,cur.a.y+v))))return false;
			if(!ch(nx,ln(cm(0,cur.b.y-v),cm(w,cur.b.y-v))))return false;
			cur=nx;
			last=ps[i].a;
		}
		dmp(cur);
		return true;
	};
	
	ld mn=0,mx=1002;
	rep(_,30){
		ld mid=(mn+mx)/2;
		if(chk(mid))mx=mid;
		else mn=mid;
	}
	
	if(mx>1001)
		cout<<-1<<endl;
	else
		cout<<mn<<endl;
}