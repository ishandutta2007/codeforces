#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
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
	REP(i,v.size())
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
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	return v;
}
template<class T>
void MakeUniqued(vector<T>&v){
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
}

const int unused=-inf;

struct Node{
	int mn,sum;
};

Node LazyNode(int lz,int len){
	Node res;
	if(lz>=0)
		res.mn=0;
	else
		res.mn=lz*len;
	res.sum=lz*len;
	return res;
};

Node Merge(const Node&x,const Node&y){
	return Node{min(x.mn,x.sum+y.mn),x.sum+y.sum};
}

struct SegTree{
	int s;
	vi pos,len;
	vi lz;
	vector<Node> ns;
	SegTree(vi pp){
		pos=pp;
		int n=pos.size();
		s=1;
		while(s<n)s*=2;
		pos.resize(s+1,pos.back());
		//cerr<<pos<<endl;
		
		ns.resize(s*2,Node{0,0});
		lz.resize(s*2,unused);
		len.resize(s*2);
		InitLen(0,s,1);
	}
	void InitLen(int l,int r,int i){
		if(i<s){
			InitLen(l,(l+r)/2,i*2);
			InitLen((l+r)/2,r,i*2+1);
		}
		len[i]=pos[r]-pos[l];
	}
	Node GetNode(int i){
		return lz[i]==unused?ns[i]:LazyNode(lz[i],len[i]);
	}
	void Propagate(int i){
		if(lz[i]==unused)return;
		lz[i*2]=lz[i*2+1]=lz[i];
		ns[i]=LazyNode(lz[i],len[i]);
		lz[i]=unused;
	}
	void Update(int i){
		assert(lz[i]==unused);
		ns[i]=Merge(GetNode(i*2),GetNode(i*2+1));
	}
	void Set(int b,int e,int v,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			cerr<<i<<" "<<l<<" "<<r<<" "<<v<<endl;
			lz[i]=v;
			return;
		}
		Propagate(i);
		Set(b,e,v,l,(l+r)/2,i*2);
		Set(b,e,v,(l+r)/2,r,i*2+1);
		Update(i);
	}
	void Set(int b,int e,int v){
		cerr<<b<<" "<<e<<" "<<v<<endl;
		Set(b,e,v,0,s,1);
	}
	bool Calc(int b,int e,int&v,double&ans,int l,int r,int i){
		if(e<=l||r<=b)return false;
		if(b<=l&&r<=e){
			Node x=GetNode(i);
			cerr<<i<<" "<<l<<" "<<r<<" "<<x.mn<<" "<<x.sum<<" "<<len[i]<<" "<<lz[i]<<endl;
			if(v+x.mn<=0){
				if(i>=s){
					assert(lz[i]<0);
					ans=pos[l]+double(v)/(-lz[i]);
				}else{
					Propagate(i);
					if(Calc(b,e,v,ans,l,(l+r)/2,i*2))
						return true;
					bool w=Calc(b,e,v,ans,(l+r)/2,r,i*2+1);
					assert(w);
				}
				return true;
			}else{
				v+=x.sum;
				return false;
			}
		}
		Propagate(i);
		if(Calc(b,e,v,ans,l,(l+r)/2,i*2))
			return true;
		if(Calc(b,e,v,ans,(l+r)/2,r,i*2+1))
			return true;
		return false;
	}
	double Calc(int b,int e,int v){
		cerr<<b<<" "<<e<<" "<<v<<endl;
		double ans=-1;
		Calc(b,e,v,ans,0,s,1);
		return ans;
	}
};

struct Query{
	int t,a,b,c;
};

signed main(){
	int n=read();
	vector<Query> qs(n);
	const int Vmin=-1,Vmax=TEN(9)+1;
	vi pos{Vmin,Vmax};
	REP(i,n){
		int t=read();
		qs[i].t=t;
		if(t==1){
			qs[i].a=read();
			qs[i].b=read();
			pos.PB(qs[i].a);
		}else if(t==2){
			qs[i].a=read();
			pos.PB(qs[i].a);
		}else if(t==3){
			qs[i].a=read();
			qs[i].b=read();
			qs[i].c=read();
			//pos.PB(qs[i].a);
			pos.PB(qs[i].b);
		}
	}
	
	MakeUniqued(pos);
	const auto idx=[&](int x){
		return lower_bound(ALL(pos),x)-pos.begin();
	};
	cerr<<pos<<endl;
	
	SegTree seg(pos);
	
	set<pi> waf;
	waf.insert(pi(idx(Vmin),0));
	waf.insert(pi(idx(Vmax),0));
	set<int> evs;
	
	REP(i,n){
		if(qs[i].t==1){
			int p=idx(qs[i].a),q=qs[i].b;
			auto itr=waf.insert(pi(p,q)).first;
			seg.Set(p,next(itr)->first,q);
			
			evs.insert(qs[i].a);
		}else if(qs[i].t==2){
			int p=idx(qs[i].a);
			auto itr=waf.lower_bound(pi(p,-inf));
			itr=waf.erase(itr);
			seg.Set(p,itr->first,prev(itr)->second);
			
			evs.erase(qs[i].a);
		}else{
			cerr<<qs[i].a<<" "<<qs[i].b<<" "<<qs[i].c<<endl;
			double ans=-1;
			if(qs[i].c==0){
				ans=qs[i].a;
			}else{
				auto itr=evs.lower_bound(qs[i].a);
				if(itr!=evs.end()&&*itr<qs[i].b){
					int p=idx(*itr),q=idx(qs[i].b);
					ans=seg.Calc(p,q,qs[i].c);
				}
			}
			if(ans<0){
				print(-1);
			}else{
				printf("%.10f\n",ans);
			}
		}
	}
}