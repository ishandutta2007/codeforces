#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
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

struct Pos{
	int y,x;
};

vector<pair<Pos,Pos>> Waf(int n,int m,vector<vector<string>> w){
	vector<pair<Pos,Pos>> res;
	int gy=0,gx=0;
	const auto Trans=[&](int y,int x){
		int c=w[y][x].back()-'0';
		w[y][x].pop_back();
		int ty=gy,tx=gx+c;
		if(y!=ty){
			res.PB(MP(Pos{y,x},Pos{ty,x}));
		}
		y=ty;
		if(x!=tx){
			res.PB(MP(Pos{y,x},Pos{ty,tx}));
		}
	};
	REP(i,n)FOR(j,2,m){
		while(!w[i][j].empty())
			Trans(i,j);
	}
	FOR(i,1,n){
		int cnt[2]{};
		while(!w[i][0].empty()){
			int c=w[i][0].back()-'0';
			if(c==0)
				res.emplace_back(Pos{i,0},Pos{0,0});
			else{
				res.emplace_back(Pos{i,0},Pos{i,1});
				cnt[1]++;
			}
			w[i][0].pop_back();
		}
		while(!w[i][1].empty()){
			int c=w[i][1].back()-'0';
			if(c==0){
				res.emplace_back(Pos{i,1},Pos{i,0});
				cnt[0]++;
			}else{
				res.emplace_back(Pos{i,1},Pos{0,1});
			}
			w[i][1].pop_back();
		}
		REP(j,2)
			REP(_,cnt[j])
				res.emplace_back(Pos{i,j},Pos{0,j});
	}
	
	/*gy=1;
	int cnt[2]{};
	REP(j,2){
		while(!w[0][j].empty()){
			cnt[w[0][j].back()-'0']++;
			Trans(0,j);
		}
	}
	
	REP(j,2){
		REP(_,cnt[j])
			res.PB(MP(Pos{1,j},Pos{0,j}));
	}
	*/
	REP(j,2){
		while(!w[0][j].empty()){
			int c=w[0][j].back()-'0';
			if(c==j){
				res.emplace_back(Pos{0,j},Pos{1,j});
				res.emplace_back(Pos{1,j},Pos{0,j});
			}else
				res.emplace_back(Pos{0,j},Pos{0,j^1});
			w[0][j].pop_back();
		}
	}
	
	return res;
}

void TestResult(int n,int m,vector<vector<string>> from,vector<vector<string>> to,vector<pair<Pos,Pos>> res){
	for(auto p:res){
		int y1=p.first.y,x1=p.first.x;
		int y2=p.second.y,x2=p.second.x;
		assert(pi(y1,x1)!=pi(y2,x2));
		assert(!from[y1][x1].empty());
		char c=from[y1][x1].back();
		from[y1][x1].pop_back();
		from[y2][x2].insert(from[y2][x2].begin(),c);
	}
	REP(i,n)REP(j,m){
		cerr<<i<<" "<<j<<" "<<from[i][j]<<" "<<to[i][j]<<endl;
		assert(from[i][j]==to[i][j]);
	}
}

signed main(){
	int n=read(),m=read();
	
	vector<vector<string>> from(n,vector<string>(m));
	REP(i,n)REP(j,m)
		from[i][j]=readString();
	vector<vector<string>> to(n,vector<string>(m));
	REP(i,n)REP(j,m)
		to[i][j]=readString();
	
	vector<vector<string>> tar(n,vector<string>(m));
	REP(i,n)REP(j,m){
		tar[i][j]=to[i][j];
		reverse(ALL(tar[i][j]));
	}
	
	auto res=Waf(n,m,from);
	
	auto res2=Waf(n,m,tar);
	reverse(ALL(res2));
	for(auto&p:res2)
		swap(p.first,p.second);
	
	res.insert(res.end(),ALL(res2));
	
	print(res.size());
	for(auto p:res){
		int y1=p.first.y,x1=p.first.x;
		int y2=p.second.y,x2=p.second.x;
		print(y1+1,2);
		print(x1+1,2);
		print(y2+1,2);
		print(x2+1);
	}
	
	#ifdef LOCAL
	TestResult(n,m,from,to,res);
	#endif
}