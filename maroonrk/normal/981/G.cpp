#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#ifdef MAROON_LOCAL
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
	scanf("%" SCNd64,&i);
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

const int mod=998244353;

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
int fact[Vmax],factInv[Vmax];
void InitFact(){
	fact[0]=1;
	FOR(i,1,Vmax){
		fact[i]=fact[i-1];
		mult(fact[i],i);
	}
	factInv[Vmax-1]=modInv(fact[Vmax-1]);
	for(int i=Vmax-2;i>=0;i--){
		factInv[i]=factInv[i+1];
		mult(factInv[i],i+1);
	}
}
int Choose(int n,int k){
	return ll(fact[n])*factInv[n-k]%mod*factInv[k]%mod;
}
int Binom(int a,int b){
	return ll(fact[a+b])*factInv[a]%mod*factInv[b]%mod;
}

struct SegTree{
	vi buf,lm,ls;
	int s;
	SegTree(int n){
		s=1;
		while(s<n)s*=2;
		buf.resize(s*2,0);
		lm.resize(s*2,1);
		ls.resize(s*2,0);
	}
	void Propagate(int i,int l,int r){
		REP(k,2){
			mult(lm[i*2+k],lm[i]);
			mult(ls[i*2+k],lm[i]);
			add(ls[i*2+k],ls[i]);
		}
		mult(buf[i],lm[i]);
		lm[i]=1;
		mult(ls[i],r-l);
		add(buf[i],ls[i]);
		ls[i]=0;
	}
	int NodeSum(int i,int l,int r){
		int x=buf[i];
		mult(x,lm[i]);
		int y=ls[i];
		mult(y,r-l);
		add(x,y);
		return x;
	}
	void Update(int i,int l,int r){
		buf[i]=0;
		ls[i]=0;
		lm[i]=1;
		add(buf[i],NodeSum(i*2,l,(l+r)/2));
		add(buf[i],NodeSum(i*2+1,(l+r)/2,r));
	}
	void Add1(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			add(ls[i],1);
			return;
		}
		Propagate(i,l,r);
		Add1(b,e,l,(l+r)/2,i*2);
		Add1(b,e,(l+r)/2,r,i*2+1);
		Update(i,l,r);
	}
	void Add1(int b,int e){
		if(b>=e)return;
		cerr<<"A "<<b<<" "<<e<<endl;
		Add1(b,e,0,s,1);
	}
	void Mult2(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			mult(lm[i],2);
			mult(ls[i],2);
			return;
		}
		Propagate(i,l,r);
		Mult2(b,e,l,(l+r)/2,i*2);
		Mult2(b,e,(l+r)/2,r,i*2+1);
		Update(i,l,r);
	}
	void Mult2(int b,int e){
		if(b>=e)return;
		cerr<<"M "<<b<<" "<<e<<endl;
		Mult2(b,e,0,s,1);
	}
	int Get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return 0;
		if(b<=l&&r<=e)return NodeSum(i,l,r);
		Propagate(i,l,r);
		int x=Get(b,e,l,(l+r)/2,i*2);
		add(x,Get(b,e,(l+r)/2,r,i*2+1));
		return x;
	}
	int Get(int b,int e){
		cerr<<"G "<<b<<" "<<e<<endl;
		return Get(b,e,0,s,1);
	}
};

signed main(){
	int n=read(),q=read();
	SegTree seg(n);
	const auto Sub=[&](set<pi>&rng,int b,int e){
		auto itr=rng.lower_bound(pi(b,-1));
		if(itr!=rng.begin())itr--;
		int last=b,rngL=b,rngR=e;
		while(itr!=rng.end()&&itr->first<e){
			if(itr->second<=b){
				itr++;
				continue;
			}
			chmin(rngL,itr->first);
			chmax(rngR,itr->second);
			
			int x=max(last,itr->first);
			int y=min(itr->second,e);
			
			seg.Add1(last,x);
			seg.Mult2(x,y);
			
			itr=rng.erase(itr);
			
			last=y;
		}
		
		seg.Add1(last,e);
		
		rng.insert(pi(rngL,rngR));
	};
	vector<set<pi>> rngs(n);
	REP(_,q){
		int t=read();
		if(t==1){
			int l=read()-1,r=read(),x=read()-1;
			Sub(rngs[x],l,r);
		}else{
			int l=read()-1,r=read();
			print(seg.Get(l,r));
		}
	}
}