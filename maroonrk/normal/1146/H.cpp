#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) FOR(i,0,b)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
auto& errStream=cerr;
#ifdef LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))

template<class T> using V=vector<T>;
template<class T> using VV=V<V<T>>;

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	rep(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

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
	os<<"(";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<")";
}

ll read(){
	ll i;
	scanf("%"  SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

template<class T>
void print(const vector<T>&v){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?1:2);
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

constexpr ll TEN(int n){
	return n==0?1:TEN(n-1)*10;
}

template<class T>
vector<T> Uniqued(const vector<T>&vv){
	auto v(vv);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	return v;
}
template<class T>
void MakeUniqued(vector<T>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.end());
}
template<class D>
struct Vec2{
	D x,y;
	Vec2(D xx=0,D yy=0):x(xx),y(yy){
	}
	bool operator<(const Vec2&rhs)const{
		return (x!=rhs.x)?(x<rhs.x):(y<rhs.y);
	}
	Vec2& operator +=(const Vec2&rhs){
		x+=rhs.x;
		y+=rhs.y;
		return *this;
	}
	Vec2 operator +(const Vec2&rhs)const{
		return Vec2(*this)+=rhs;
	}
	Vec2& operator -=(const Vec2&rhs){
		x-=rhs.x;
		y-=rhs.y;
		return *this;
	}
	Vec2 operator -(const Vec2&rhs)const{
		return Vec2(*this)-=rhs;
	}
	Vec2& operator *=(D d){
		x*=d;
		y*=d;
		return *this;
	}
	Vec2 operator *(D d)const{
		return Vec2(*this)*=d;
	}
	Vec2& operator /=(D d){
		x/=d;
		y/=d;
		return *this;
	}
	Vec2 operator /(D d)const{
		return Vec2(*this)/=d;
	}
	D norm()const{
		return Sq(x)+Sq(y);
	}
	double lengthImpl(true_type)const{
		return sqrt(norm());
	}
	D lengthImpl(false_type)const{
		return sqrt(norm());
	}
	auto length()const{
		return lengthImpl(is_same<D,int>());
	}
	double arg()const{
		return atan2(y,x);
	}
};
template<class D>
Vec2<D> operator*(D d,const Vec2<D>& v){
	return v*d;
}
template<class D>
ostream& operator<<(ostream&os,const Vec2<D>& p){
	return os<<"{"<<p.x<<","<<p.y<<"}";
}
template<class D>
D dot(Vec2<D> a,Vec2<D> b){
	return a.x*b.x+a.y*b.y;
}
template<class D>
D cross(Vec2<D> a,Vec2<D> b){
	return a.x*b.y-a.y*b.x;
}
template<class D>
int sgn(D x){
	if(x>0)return 1;
	else if(x<0)return -1;
	else return 0;
}
//ccw 1, line 0, cw -1
template<class D>
int ccw(Vec2<D> a,Vec2<D> b,Vec2<D> c){
	return sgn(cross(b-a,c-a));
}
template<class D>
complex<double> toC(Vec2<D> v){
	return complex<double>(v.x,v.y);
}
//a->b->c 
// 0
template<class D>
double turnArg(Vec2<D> a,Vec2<D> b,Vec2<D> c){
	auto p=toC(b-a);
	auto q=toC(c-b);
	return arg(q/p);
}

//assume a,b,c lie on the same line
//returns if the order is a-b-c
//not verified
template<class D>
bool between(Vec2<D> a,Vec2<D> b,Vec2<D> c,bool inc=true){
	return sgn(dot(a-b,c-b))<=(inc?0:-1);
}

template<class D>
bool parallelVV(Vec2<D> a,Vec2<D> b){
	return !sgn(cross(a,b));
}

/*
using P=Vec2<double>;
const double PI=acos(-1);
const double eps=1e-9;

template <>
int sgn(double d){
	if(d>eps) return 1;
	else if(d<-eps) return -1;
	else return 0;
}
int sgn(double a,double b){
	return sgn(a-b);
}
P polar(double len,double a){
	return P(len*cos(a),len*sin(a));
}
*/

using P=Vec2<int>;

const int Nmax=310;
const int S=5;
int res_buf[2][Nmax][Nmax][S],dp_buf[2][Nmax][Nmax][S];

signed main(){
	int n=read();
	V<P> ps(n);
	rep(i,n){
		ps[i].x=read();
		ps[i].y=read();
	}
	sort(all(ps));
	
	rep($,2){
		auto&res=res_buf[$];
		auto&dp=dp_buf[$];
		
		vector<vi> left(n),right(n);
		rep(i,n){
			rep(j,i)
				left[i].pb(j);
			FOR(j,i+1,n)
				right[i].pb(j);
			const auto cmp=[&](int a,int b){
				return ccw(ps[a],ps[i],ps[b])==1;
			};
			sort(all(left[i]),cmp);
			sort(all(right[i]),cmp);
		}
		
		rep(i,n){
			FOR(j,i,n)FOR(k,j,n)rep(s,S)
				dp[j][k][s]=0;
			FOR(j,i+1,n){
				int l=0,cur[S]{};
				const auto AddL=[&](){
					if(i==left[j][l]){
						cur[1]++;
					}
					if(i<left[j][l]){
						rep(s,S)
							cur[s]+=dp[left[j][l]][j][s];
					}
					l++;
				};
				for(auto y:right[j]){
					while(l<int(left[j].size())){
						int c=ccw(ps[left[j][l]],ps[j],ps[y]);
						if(c==-1){
							AddL();
						}else{
							break;
						}
					}
					rep(s,S-1)
						dp[j][y][s+1]+=cur[s];
				}
				while(l<int(left[j].size())){
					AddL();
				}
				rep(s,S)
					res[i][j][s]=cur[s];
			}
		}
		for(auto&p:ps)
			p.y=-p.y;
	}
	
	int ans=0;
	rep(i,n)FOR(j,i+1,n){
		FOR(s,1,S)
			ans+=res_buf[0][i][j][s]*res_buf[1][i][j][S-s];
	}
	print(ans);
}