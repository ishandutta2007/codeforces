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


//f(a,b)  true  a 
template<class t,class u>
struct slide{
	vc<t> x;
	vi y;
	u f;
	int b,e,c,d;
	slide(int n,u ff=u()):x(n),y(n),f(ff){init();}
	void init(){b=e=c=d=0;}
	void push(t a){
		while(b<e&&f(x[e-1],a))e--;
		x[e]=a;
		y[e++]=c++;
	}
	void pop(){if(y[b]==d)b++;d++;}
	t get(){return x[b];}
};


using ld=long double;
using cm=complex<ld>;
#define x real()
#define y imag()
const ld eps=0;//1e-12;
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


using cr=pair<cm,ld>;
//AOJ0153
//0-no,1-edge,2-in
int cont(cr a,cm b){
	return sgn(a.b-abs(b-a.a))+1;
}
//AOJ0153
//0-no,1-touch,2-cross
int ids(cr a,ln b){
	return sgn(a.b-dsp(b,a.a))+1;
}
//AOJ0129 (touch)
//0-no(in),1-touch(in),2-cross,3-touch(out),4-no(out)
int ics(cr a,ln b){
	int c=ids(a,b);
	if(c<=1)return 4-c;
	return sgn(max(abs(b.a-a.a),abs(b.b-a.a))-a.b)+1;
}
//AOJ1183
int ccl(cr a,ln b,ld&c,ld&d){
	cm e=dir(b);
	cm f=b.a-a.a;
	return qeq(norm(e),2*dot(e,f),norm(f)-a.b*a.b,c,d);
}
//AOJ0023
//0-apart,1-coinside,2-a<b,3-a<=b,4-a>b,5-a>=b,6-a touch b,7-a cross b
int icc(cr a,cr b){
	ld c=abs(a.a-b.a);
	if(sgn(c)==0&&sgn(a.b-b.b)==0)return 1;
	int d=sgn(c+a.b-b.b);
	if(d<=0)return d+3;
	int e=sgn(c+b.b-a.b);
	if(e<=0)return e+5;
	int f=sgn(a.b+b.b-c);
	if(f>=0)return f+6;
	return 0;
}
//AOJ2572
//args of two intersections r,l seen be a.a
//assume two circles cross
pair<ld,ld> ccc(cr a,cr b){
	ld c=arg(b.a-a.a);
	ld d=arg(a.b,abs(b.a-a.a),b.b);
	return make_pair(c-d,c+d);
}
//AOJ2572
//area of circular segment
ld cseg(ld a,ld b){
	return a*a*(b-sin(b))/2;
}
//AOJ2423
cr circumc(cm a,cm b,cm c){
	b-=a;
	c-=a;
	cm r=norm(b)*c-norm(c)*b;
	r=cm(r.y,-r.x)/(2*crs(b,c));
	return cr(a+r,abs(r));
}
//AOJ2423
cr mindisc(const vc<cm>& p,array<cm,3> q,int i,int j){
	if(i==int(p.size())){
		if(j==0)
			return {{0,0},-1};
		else if(j==1)
			return {q[0],0};
		else if(j==2)
			return {(q[0]+q[1])*ld(0.5),abs(q[0]-q[1])/2};
		else if(j==3)
			return circumc(q[0],q[1],q[2]);
		else
			assert(false);
	}
	cr c=mindisc(p,q,i+1,j);
	if(sgn(abs(c.a-p[i])-c.b)==1){
		assert(j<3);
		q[j]=p[i];
		return mindisc(p,q,i+1,j+1);
	}else
		return c;
}
cr mindisc(vc<cm> p){
	shuffle(all(p),mt19937());
	return mindisc(p,array<cm,3>(),0,0);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,canuse;cin>>n>>canuse;
	vc<cm> z;
	ld mn=0,mx=1e9;
	rep(i,n){
		int a,b;cin>>a>>b;
		if(a==0&&b==0){
			cout<<0<<endl;
			return 0;
		}
		z.eb(a,b);
		chmin(mx,abs(z.back()));
	}
	vc<ld> ag(n);
	rep(i,n)ag[i]=arg(z[i]);
	
	auto rel=[](ld a){
		while(sgn(a)<0)a+=2*PI;
		while(sgn(a-2*PI)>1)a-=2*PI;
		return a;
	};
	
	slide<pi,greater<pi>> sld(n*4);
	
	rep(_,50){
		const ld mid=(mn+mx)/2;
		
		vc<pair<ld,ld>> lr;
		rep(i,n){
			ld t=acos(min(ld(1),mid/abs(z[i])));
			lr.eb(rel(ag[i]-t),rel(ag[i]+t));
		}
		vc<ld> pos;
		for(auto w:lr){
			pos.pb(w.a);
			pos.pb(w.b);
		}
		sort(all(pos));
		pos.erase(unique(all(pos),[](ld a,ld b){return sgn(a-b)==0;}),pos.ed);
		
		int m=pos.size()*2;
		vi lf(m,-1);
		
		for(auto w:lr){
			int a=lower_bound(all(pos),w.a-eps)-pos.bg;
			int b=lower_bound(all(pos),w.b-eps)-pos.bg;
			if(b<a)b+=m/2;
			assert(b+1<m);
			chmax(lf[b+1],a);
		}
		rep(i,m-1)
			chmax(lf[i+1],lf[i]);
		
		int ans=inf;
		sld.init();
		int j=0;
		rep(i,m){
			while(j<lf[i]){sld.pop();j++;}
			pi cur;
			if(lf[i]==-1)cur=pi(0,i);
			else cur=sld.get();
			if(i>=m/2)
				chmin(ans,cur.a+(i-m/2<cur.b));
			cur.a++;
			sld.push(cur);
		}
		dmp(lf);
		
		//dmp(mid);
		//dmp(ans);
		if(ans<=canuse)
			mn=mid;
		else
			mx=mid;
	}
	
	cout<<mn<<endl;
}