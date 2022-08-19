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
	using NP=Node*;
	NP l,r;
	bool rev;
	int key,val,lz;
	Node():l(NULL),r(NULL),rev(false){
		key=rand();
	}
	void Propagate(){
		if(rev){
			swap(l,r);
			if(l) l->rev^=true;
			if(r) r->rev^=true;
			rev=false;
		}
		val+=lz;
		if(l){
			l->lz+=lz;
		}
		if(r){
			r->lz+=lz;
		}
		lz=0;
	}
	int Get(){
		return val+lz;
	}
} ns[300010];

using NP=Node::NP;
NP NewNode(int val){
	static int used=0;
	NP ptr=ns+(used++);
	ptr->l=NULL;
	ptr->r=NULL;
	ptr->rev=false;
	ptr->val=val;
	ptr->lz=0;
	return ptr;
}

NP Merge(NP x,NP y){
	if(!x)return y;
	if(!y)return x;
	if(x->key>y->key){
		x->Propagate();
		x->r=Merge(x->r,y);
		return x;
	}else{
		y->Propagate();
		y->l=Merge(x,y->l);
		return y;
	}
}

pair<NP,NP> Split(NP x,int v){
	if(!x)return MP(NP(NULL),NP(NULL));
	x->Propagate();
	if(x->Get()<v){
		auto r=Split(x->r,v);
		x->r=r.first;
		return MP(x,r.second);
	}else{
		auto l=Split(x->l,v);
		x->l=l.second;
		return MP(l.first,x);
	}
}

NP MLN(NP x){
	while(1){
		x->Propagate();
		if(x->l)
			x=x->l;
		else
			break;
	}
	return x;
}

NP MRN(NP x){
	while(1){
		x->Propagate();
		if(x->r)
			x=x->r;
		else
			break;
	}
	return x;
}

pair<NP,NP> SplitMLN(NP x){
	assert(x);
	x->Propagate();
	if(x->l){
		auto l=SplitMLN(x->l);
		x->l=l.second;
		return MP(l.first,x);
	}else{
		auto r=x->r;
		x->r=NULL;
		return MP(x,r);
	}
}

int ans;
void Calc(NP x){
	if(!x)return;
	x->Propagate();
	if(x->val<inf)ans++;
	Calc(x->l);
	Calc(x->r);
}

signed main(){
	int n=read();
	NP root=NULL;
	REP(i,n+1)
		root=Merge(root,NewNode(inf));
	
	cerr<<endl;
	REP(i,n){
		int l=read(),r=read();
		cerr<<endl;
		auto s1=Split(root,r);
		cerr<<endl;
		auto s2=Split(s1.first,l);
		cerr<<endl;
		auto s3=SplitMLN(s1.second);
		cerr<<endl;
		NP x=s3.first;
		assert(x->lz==0);
		x->val=l;
		NP y=s2.second;
		if(y)y->lz++;
		root=Merge(Merge(s2.first,x),Merge(y,s3.second));
	}
	
	Calc(root);
	print(ans);
}