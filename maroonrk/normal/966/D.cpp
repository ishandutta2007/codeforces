#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

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

const int Nmax=300010;
vi g[Nmax];
int dist[Nmax];
void BFS(){
	ONE(dist);
	queue<int> q;
	const auto Set=[&](int v,int d){
		if(dist[v]==-1){
			dist[v]=d;
			q.push(v);
		}
	};
	Set(0,0);
	while(!q.empty()){
		int v=q.front();q.pop();
		int d=dist[v];
		for(auto to:g[v])
			Set(to,d+1);
	}
}
vi Trace(int v){
	vi res{v};
	while(v!=0){
		for(auto to:g[v])
			if(dist[to]==dist[v]-1){
				res.PB(to);
				v=to;
				break;
			}
	}
	reverse(ALL(res));
	return res;
}
bool VecFind(const vi& a,int x){
	auto itr=lower_bound(ALL(a),x);
	if(itr!=a.end()&&*itr==x)return true;
	else return false;
}
bool vis[Nmax];
struct Res{
	int a,b,c;
};
Res dfs(int v,int p,vi&idx){
	if(vis[v])return Res{-1,-1,-1};
	vis[v]=true;
	if(int(idx.size())>=2)
		for(auto i:idx)
			if(!VecFind(g[v],i))
				return Res{v,p,i};
	idx.PB(v);
	vi tops;
	for(auto to:g[v]){
		auto r=dfs(to,v,idx);
		if(r.b!=-1)return r;
		if(r.a!=-1)tops.PB(r.a);
	}
	if(int(tops.size())>=2)
		return Res{tops[0],v,tops[1]};
	idx.pop_back();
	return Res{v,-1,-1};
}

signed main(){
	int n=read(),m=read();
	REP(i,m){
		int u=read()-1,v=read()-1;
		g[u].PB(v);
		g[v].PB(u);
	}
	REP(i,n)sort(ALL(g[i]));
	BFS();
	pair<int,vi> ans(inf,vi());
	if(dist[n-1]!=-1){
		chmin(ans,MP(dist[n-1],Trace(n-1)));
	}
	if(ans.first>4){
		REP(i,n)if(dist[i]==2){
			vi idx=Trace(i);
			idx.PB(0);
			idx.PB(n-1);
			chmin(ans,MP(int(4),idx));
			break;
		}
	}
	if(ans.first>5){
		REP(i,n)vis[i]=true;
		for(auto to:g[0])
			vis[to]=false;
		REP(i,n)if(!vis[i]){
			vi tmp;
			auto r=dfs(i,-1,tmp);
			if(r.b!=-1){
				vi idx{0,r.a,r.b,r.c,r.a,n-1};
				chmin(ans,MP(int(5),idx));
				break;
			}
		}
	}
	if(ans.first>1000000){
		print(-1);
	}else{
		print(ans.first);
		int s=ans.second.size();
		REP(i,s)
			print(ans.second[i]+1,i==s-1?1:2);
	}
}