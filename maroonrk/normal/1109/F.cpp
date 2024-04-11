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

struct Node{
	typedef Node* NP;
	NP l,r,p;
	bool rev;
	Node():l(NULL),r(NULL),p(NULL),rev(false){}
	void Propagate(){
		if(rev){
			swap(l,r);
			if(l) l->rev^=true;
			if(r) r->rev^=true;
			rev=false;
		}
	}
	void Update(){
	}
	int Pos(){
		if(p&&p->l==this) return -1;
		if(p&&p->r==this) return 1;
		return 0;
	}
	void Prepare(){
		if(Pos())
			p->Prepare();
		Propagate();
	}
	void Rotate(){
		NP q=p,c;
		if(Pos()==1){
			c=l;
			l=p;
			p->r=c;
		}else{
			c=r;
			r=p;
			p->l=c;
		}
		if(c) c->p=p;
		p=p->p;
		q->p=this;
		if(p&&p->l==q) p->l=this;
		if(p&&p->r==q) p->r=this;
		q->Update();
	}
	void Splay(){
		Prepare();
		while(Pos()){
			int a=Pos(),b=p->Pos();
			if(b&&a==b) p->Rotate();
			if(b&&a!=b) Rotate();
			Rotate();
		}
		Update();
	}
	void Expose(){
		for(NP x=this;x;x=x->p) x->Splay();
		for(NP x=this;x->p;x=x->p){
			x->p->r=x;
			x->p->Update();
		}
		Splay();
	}
	void Evert(){
		Expose();
		if(l){
			l->rev^=true;
			l=NULL;
			Update();
		}
	}
	void Link(NP x){
		Evert();
		p=x;
	}
	void Cut() {
		Expose();
		assert(l);
		l->p = NULL;
		l = NULL;
		Update();
	}
};

bool Same(Node* a, Node* b) {
	a->Expose();
	b->Expose();
	if(!a->p)
		return false;
	return true;
}

const int Nmax=200010;
Node buf[Nmax];
Node* NewNode(){
	static int bufUsed=0;
	return buf+bufUsed++;
}

struct SegTree{
	int s;
	vi lz,mn,cnt;
	SegTree(int n){
		s=1;
		while(s<n)s*=2;
		
		lz.resize(s*2,0);
		mn.resize(s*2,0);
		cnt.resize(s*2,1);
		for(int i=s-1;i>=1;i--)
			cnt[i]=cnt[i*2]+cnt[i*2+1];
	}
	int GetMin(int i){
		return mn[i]+lz[i];
	}
	void Propagate(int i){
		lz[i*2]+=lz[i];
		lz[i*2+1]+=lz[i];
		mn[i]+=lz[i];
		lz[i]=0;
	}
	void Update(int i){
		assert(lz[i]==0);
		int x=GetMin(i*2);
		int y=GetMin(i*2+1);
		mn[i]=min(x,y);
		cnt[i]=0;
		if(mn[i]==x)
			cnt[i]+=cnt[i*2];
		if(mn[i]==y)
			cnt[i]+=cnt[i*2+1];
	}
	void Add(int b,int e,int v,int l,int r,int i){
		if(e<=l||r<=b)return;
		if(b<=l&&r<=e){
			//cerr<<i<<" "<<l<<" "<<r<<" "<<v<<endl;
			lz[i]+=v;
			return;
		}
		Propagate(i);
		Add(b,e,v,l,(l+r)/2,i*2);
		Add(b,e,v,(l+r)/2,r,i*2+1);
		Update(i);
	}
	void Add(int b,int e,int v){
		if(e<=b)return;
		cerr<<b<<" "<<e<<" "<<v<<endl;
		Add(b,e,v,0,s,1);
	}
	int Calc(int b,int e,const int v,int l,int r,int i){
		if(e<=l||r<=b)return 0;
		if(b<=l&&r<=e){
			if(GetMin(i)==v)
				return cnt[i];
			else
				return 0;
		}
		Propagate(i);
		int ans=0;
		ans+=Calc(b,e,v,l,(l+r)/2,i*2);
		ans+=Calc(b,e,v,(l+r)/2,r,i*2+1);
		return ans;
	}
	int Calc(int b,int e,const int v){
		//cerr<<b<<" "<<e<<" "<<v<<endl;
		return Calc(b,e,v,0,s,1);
	}
};

signed main(){
	int n=read(),m=read();
	int s=n*m;
	vector<vi> f(n,vi(m));
	vector<pi> pos(s);
	REP(i,n)REP(j,m){
		f[i][j]=read()-1;
		pos[f[i][j]]=pi(i,j);
	}
	const auto get=[&](int x,int y){
		if(0<=x&&x<n&&0<=y&&y<m)
			return f[x][y];
		return s;
	};
	SegTree seg(s);
	int ans=0,lim=s;
	vector<vi> es(s);
	for(int i=s-1;i>=0;i--){
		int x=pos[i].first,y=pos[i].second;
		seg.Add(i,s,1);
		const int dxy[]={-1,0,1,0,-1};
		REP(k,4){
			int nx=x+dxy[k],ny=y+dxy[k+1];
			int w=get(nx,ny);
			if(i<w&&w<s){
				seg.Add(w,s,-1);
				while(w<lim){
					if(!Same(buf+i,buf+w))break;
					int z=lim-1;
					buf[z].Evert();
					for(auto j:es[z])
						buf[j].Cut();
					lim--;
				}
				if(w<lim){
					es[w].PB(i);
					buf[i].Evert();
					buf[i].Link(buf+w);
				}
			}
		}
		cerr<<lim<<endl;
		int r=seg.Calc(i,lim,1);
		cerr<<i<<" "<<r<<endl;
		ans+=r;
	}
	print(ans);
}