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

struct Node{
	typedef Node* NP;
	NP l,r,p;
	bool rev;
	int v,mx,lz;
	Node():l(NULL),r(NULL),p(NULL),rev(false),v(-inf),mx(-inf),lz(-inf){}
	void Propagate(){
		if(rev){
			swap(l,r);
			if(l) l->rev^=true;
			if(r) r->rev^=true;
			rev=false;
		}
		if(l)chmax(l->lz,lz);
		if(r)chmax(r->lz,lz);
		chmax(v,lz);
		chmax(mx,lz);
		lz=-inf;
	}
	int GetMax(){
		return max(mx,lz);
	}
	int GetVert(){
		return max(v,lz);
	}
	void Update(){
		assert(lz==-inf);
		mx=v;
		if(l){
			chmax(mx,l->GetMax());
		}
		if(r){
			chmax(mx,r->GetMax());
		}
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
	void Set(int q){
		Expose();
		r=NULL;
		chmax(lz,q);
	}
	void Cut() {
		Expose();
		assert(l);
		l->p = NULL;
		l = NULL;
		Update();
	}
	int Get(){
		Expose();
		r=NULL;
		Update();
		return GetMax();
	}
};

Node* LCA(Node* a, Node* b) {
	a->Expose();
	b->Expose();
	if (!a->p) {
		return NULL;
	}
	
	Node* d = a;
	while (a->p != b) {
		if (a->Pos()==0) {
			d = a->p;
		}
		a = a->p;
	}
	if (a == b->l) {
		return d;
	}
	else {
		return b;
	}
}

const int Nmax=200010;
Node lc[Nmax];
vi ch[Nmax];
int dep[Nmax],par[Nmax][18];
int ordCnt,et[Nmax][2];
void dfs1(int v,int d){
	dep[v]=d;
	et[v][0]=ordCnt++;
	for(auto to:ch[v])
		dfs1(to,d+1);
	et[v][1]=ordCnt;
}
void UpdatePar0(int v,int x){
	if(dep[par[v][0]]>dep[x])
		par[v][0]=x;
}
void dfs2(int v){
	for(auto to:ch[v]){
		dfs2(to);
		UpdatePar0(v,par[to][0]);
	}
}

struct SegTree{
	int s;
	vector<vi> ys;
	SegTree(int n){
		s=1;
		while(s<n)s*=2;
		ys.resize(s*2);
	}
	void AddPoint(int x,int y){
		cerr<<"A "<<x<<" "<<y<<endl;
		int i=x+s;
		while(i){
			ys[i].PB(y);
			i>>=1;
		}
	}
	void Prepare(int i=1){
		sort(ALL(ys[i]));
		if(i<s){
			Prepare(i*2);
			Prepare(i*2+1);
		}
	}
	int Get(int xb,int xe,int yb,int ye,int l,int r,int i){
		if(xe<=l||r<=xb)return 0;
		if(xb<=l&&r<=xe)return lower_bound(ALL(ys[i]),ye)-lower_bound(ALL(ys[i]),yb);
		return Get(xb,xe,yb,ye,l,(l+r)/2,i*2)+Get(xb,xe,yb,ye,(l+r)/2,r,i*2+1);
	}
	int Get(int xb,int xe,int yb,int ye){
		cerr<<"Q "<<xb<<" "<<xe<<" "<<yb<<" "<<ye<<endl;
		return Get(xb,xe,yb,ye,0,s,1);
	}
};

signed main(){
	int n=read();
	FOR(i,1,n){
		int p=read()-1;
		lc[i].Link(&lc[p]);
		ch[p].PB(i);
	}
	dfs1(0,0);
	REP(i,n)par[i][0]=i;
	SegTree seg(n);
	int m=read();
	REP(_,m){
		int a=read()-1,b=read()-1;
		int l=LCA(&lc[a],&lc[b])-lc;
		UpdatePar0(a,l);
		UpdatePar0(b,l);
		if(et[a][0]>et[b][0])swap(a,b);
		seg.AddPoint(et[a][0],et[b][0]);
	}
	seg.Prepare();
	dfs2(0);
	REP(i,n)
		cerr<<i<<" "<<par[i][0]<<endl;
	FOR(h,1,18)
		REP(i,n)par[i][h]=par[par[i][h-1]][h-1];
	int q=read();
	REP(i,q){
		int a=read()-1,b=read()-1;
		int l=LCA(&lc[a],&lc[b])-lc;
		if(l==a)swap(a,b);
		int ans=0;
		for(int h=17;h>=0;h--){
			int to=par[a][h];
			if(dep[to]>dep[l]){
				ans+=(1<<h);
				a=to;
			}
		}
		if(l==b){
			if(dep[par[a][0]]>dep[l])
				print(-1);
			else{
				print(ans+1);
			}
		}else{
			if(dep[par[a][0]]>dep[l])
				print(-1);
			else{
				for(int h=17;h>=0;h--){
					int to=par[b][h];
					if(dep[to]>dep[l]){
						ans+=(1<<h);
						b=to;
					}
				}
				cerr<<i<<" "<<a<<" "<<b<<" "<<l<<endl;
				cerr<<par[b][0]<<endl;
				if(dep[par[b][0]]>dep[l]){
					print(-1);
				}else{
					cerr<<i<<" "<<ans<<endl;
					if(et[a][0]>et[b][0])swap(a,b);
					bool has=seg.Get(et[a][0],et[a][1],et[b][0],et[b][1]);
					cerr<<i<<" "<<has<<endl;
					if(has)ans+=1;
					else ans+=2;
					print(ans);
				}
			}
		}
	}
}