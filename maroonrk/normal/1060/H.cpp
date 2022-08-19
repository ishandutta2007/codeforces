#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
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
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
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

//const int mod=1000000007;
int mod;
template<class T,class U>
void add(T& a,U b){
	//a=((ll)a+b)%mod;
	a+=b;
	if(a>=mod)a-=mod;
}

template<class T,class U>
void sub(T& a,U b){
	//a=((ll)a-b%mod+mod)%mod;
	a-=b;
	if(a<0)a+=mod;
}

template<class T,class U>
void mult(T& a,U b){
	a=((ll)a*b)%mod;
}

ll modPow(ll a,ll p){
	ll s=1;
	while(p){
		if(p&1)mult(s,a);
		mult(a,a);
		p>>=1;
	}
	return s;
}

ll modInv(ll a){
	return modPow(a,mod-2);
}

const int Vmax=1000010;
int fact[Vmax],factInv[Vmax],invs[Vmax];
void InitFact(){
	int vv=min(Vmax,mod);
	fact[0]=1;
	FOR(i,1,vv){
		fact[i]=fact[i-1];
		mult(fact[i],i);
	}
	factInv[vv-1]=modInv(fact[vv-1]);
	for(int i=vv-2;i>=0;i--){
		factInv[i]=factInv[i+1];
		mult(factInv[i],i+1);
	}
	for(int i=vv-1;i>=1;i--){
		invs[i]=factInv[i];
		mult(invs[i],fact[i-1]);
	}
}
int Choose(int n,int k){
	return ll(fact[n])*factInv[n-k]%mod*factInv[k]%mod;
}
int Binom(int a,int b){
	return ll(fact[a+b])*factInv[a]%mod*factInv[b]%mod;
}

bool dbg;

const int Nmax=5000;
int d,p;

int realBuf[Nmax],realAns;
void Init(){
	mod=p;
	if(dbg){
		realBuf[0]=rand()%mod;
		realBuf[1]=rand()%mod;
		realAns=realBuf[0]*realBuf[1]%mod;
		FOR(i,2,Nmax)
			realBuf[i]=1;
	}
}

int lines=0;

void Add(int a,int b,int c){
	lines++;
	if(dbg){
		int x=realBuf[a],y=realBuf[b];
		add(x,y);
		realBuf[c]=x;
	}else{
		cout<<"+ "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
	}
}

void Exp(int a,int b){
	lines++;
	if(dbg){
		int x=realBuf[a];
		x=modPow(x,d);
		realBuf[b]=x;
	}else{
		cout<<"^ "<<a+1<<" "<<b+1<<endl;
	}	
}

void Answer(int f){
	lines++;
	if(dbg){
		cerr<<realAns<<" "<<realBuf[f]<<endl;
		if(realAns==realBuf[f])
			cerr<<"Correct"<<endl;
		else
			cerr<<"Incorrect"<<endl;
		cerr<<"Lines "<<lines<<endl;
	}else{
		cout<<"f "<<f+1<<endl;
	}
	exit(0);
}

template<int S>
struct Vector{
	int v[S];
	Vector(){
		ZERO(v);
	}
};

template<int S>
struct Matrix{
	int m[S][S];
	Matrix(int z=0){
		ZERO(m);
		REP(i,S)
			m[i][i]=z;
	}
	Matrix operator*(const Matrix&rhs)const{
		Matrix res;
		REP(i,S)REP(j,S){
			REP(k,S){
				int w=m[i][k];
				mult(w,rhs[k][j]);
				add(res[i][j],w);
			}
		}
		return res;
	}
	Vector<S> operator*(const Vector<S>&rhs)const{
		Vector<S> res;
		REP(i,S)REP(j,S){
			int w=m[i][j];
			mult(w,rhs.v[j]);
			add(res.v[i],w);
		}
		return res;
	}
	int (&operator[](int i))[S]{
		return m[i];
	}
	int const (& operator[](int i) const)[S]{
		return m[i];
	}
};

template<int S>
ostream&operator<<(ostream&os,const Matrix<S>&x){
	os<<"----------"<<endl;
	REP(i,S){
		REP(j,S){
			os<<x[i][j];
			if(j==S-1){
				os<<endl;
			}else{
				os<<" ";
			}
		}
	}
	return os<<"----------";
}

template<int S>
Matrix<S> Inverse(Matrix<S> a){
	Matrix<S> b(1);
	REP(i,S){
		FOR(j,i,S)if(a[j][i]){
			swap(a[j],a[i]);
			swap(b[j],b[i]);
		}
		int w=modInv(a[i][i]);
		REP(j,S){
			mult(a[i][j],w);
			mult(b[i][j],w);
		}
		FOR(j,i+1,S){
			int z=a[j][i];
			REP(k,S){
				{
					int zz=z;
					mult(zz,a[i][k]);
					sub(a[j][k],zz);
				}
				{
					int zz=z;
					mult(zz,b[i][k]);
					sub(b[j][k],zz);
				}
			}
		}
	}
	for(int i=S-1;i>=0;i--){
		REP(j,i){
			int z=a[j][i];
			REP(k,S){
				{
					int zz=z;
					mult(zz,a[i][k]);
					sub(a[j][k],zz);
				}
				{
					int zz=z;
					mult(zz,b[i][k]);
					sub(b[j][k],zz);
				}
			}
		}
	}
	return b;
}

signed main(){
	//dbg=true;
	d=read(),p=read();
	Init();
	InitFact();
	
	int tail=Nmax;
	const auto GetVar=[&](){
		return --tail;
	};
	
	int work=GetVar();
	int one=GetVar();
	const auto mult_add=[&](int src,int num,int tar){
		REP(i,30){
			if((num>>i)&1){
				Add(src,tar,tar);
			}
			Add(src,src,work);
			src=work;
		}
	};
	const auto mult_sub=[&](int src,int num,int tar){
		mult_add(src,p-num,tar);
	};
	const auto Get0=[&](){
		int pos=GetVar();
		mult_add(one,p-1,pos);
		return pos;
	};
	const auto Multiply=[&](int src,int num){
		int pos=Get0();
		mult_add(src,num,pos);
		return pos;
	};
	
	using M=Matrix<11>;
	M g(1);
	REP(i,d+1)
		REP(j,d+1)
			g[i][j]=modPow((i+1),d-j)*Choose(d,j)%mod;
	cerr<<g<<endl;
	M h=Inverse(g);
	cerr<<h<<endl;
	{
		M x(1);
		M y=g*h;
		cerr<<y<<endl;
		REP(i,11)REP(j,11)
			assert(x[i][j]==y[i][j]);
	}
	
	int res_pos[2];
	REP(k,2){
		int num=k==0?1:p-1;
		vi pos(d+1);
		REP(i,d+1){
			pos[i]=GetVar();
			if(i==0){
				mult_add(0,1,pos[i]);
				mult_add(1,num,pos[i]);
			}else{
				Add(pos[i-1],pos[i],pos[i]);
			}
		}
		REP(i,d+1)
			Exp(pos[i],pos[i]);
		res_pos[k]=Get0();
		REP(i,d+1){
			int w=h[2][i];
			mult_add(pos[i],w,res_pos[k]);
		}
	}
	
	cerr<<realBuf[0]<<" "<<realBuf[1]<<endl;
	cerr<<realBuf[res_pos[0]]<<" "<<realBuf[res_pos[1]]<<endl;
	
	mult_sub(res_pos[1],1,res_pos[0]);
	int f=Multiply(res_pos[0],modInv(4));
	
	Answer(f);
}