#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

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
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
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
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

const int inf=LLONG_MAX/3;

struct Tozan{
	mutable int l,r,ovl,ovr,v;
	bool operator<(const Tozan& rhs)const{
		return l<rhs.l;
	}
};

struct Waf{
	int h,l,r;
	bool operator<(const Waf& rhs)const{
		return h<rhs.h;
	}
};

signed main(){
	int n=read(),t=read();
	set<Tozan> s;
	s.insert(Tozan{-inf,inf,-inf,inf,inf});
	vector<Waf> w;
	REP(i,n){
		int h=read(),l=read(),r=read();
		w.PB(Waf{h,l,r});
	}
	w.PB(Waf{t,-inf+1,inf-1});
	sort(ALL(w));
	int last;
	for(auto& p:w){
		auto itr=s.lower_bound(Tozan{p.r});
		if(itr==s.end()||p.r<itr->l){
			itr--;
			Tozan k=*itr;
			itr->l=p.r;
			chmax(itr->ovl,p.r);
			k.r=p.r;
			s.insert(itr,k);
		}
		itr=s.lower_bound(Tozan{p.l});
		if(p.l<itr->l){
			itr--;
			Tozan k=*itr;
			itr->l=p.l;
			k.r=p.l;
			chmin(k.ovr,p.l);
			s.insert(itr,k);
		}
		int res=0;
		while(itr->r<=p.r){
			if(itr->ovl<=p.l&&p.r<=itr->ovr)
				chmax(res,min(min(itr->r,p.r)-max(itr->l,p.l),itr->v));
			itr=s.erase(itr);
		}
		last=res;
		s.insert(Tozan{p.l,p.r,-inf,inf,res});
	}
	cout<<last<<endl;
}