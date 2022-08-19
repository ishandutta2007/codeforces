#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
//#define int ll

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


const int Nmax=100010;
const int Lmax=17;
vi tr[Nmax];
int par[Lmax][Nmax],dep[Nmax],ein[Nmax],eout[Nmax],ecur;
void dfs1(int v,int p,int d){
	ein[v]=ecur++;
	par[0][v]=p;
	dep[v]=d;
	for(auto to:tr[v])if(to!=p)
		dfs1(to,v,d+1);
	eout[v]=ecur;
}
void InitPars(int n){
	FOR(h,1,Lmax)
		REP(i,n){
			int a=par[h-1][i];
			if(a==-1)
				par[h][i]=-1;
			else
				par[h][i]=par[h-1][a];
		}
}
int LCA(int a,int b){
	if(dep[a]>dep[b])swap(a,b);
	for(int h=Lmax-1;h>=0;h--)
		if(dep[a]<=dep[b]-(1<<h))
			b=par[h][b];
	if(a==b)return a;
	for(int h=Lmax-1;h>=0;h--)
		if(par[h][a]!=par[h][b]){
			a=par[h][a];
			b=par[h][b];
		}
	return par[0][a];
}
int DistantPar(int a,int l){
	for(int h=Lmax-1;h>=0;h--)
		if((l>>h)&1)
			a=par[h][a];
	return a;
}
bool Ascend(int v,int p){
	return ein[p]<=ein[v]&&eout[v]<=eout[p];
}

struct BIT{
	vi buf;
	int s;
	BIT(int n){
		buf.resize(s=n,0);
	}
	void Add(int i,int v){
		cerr<<i<<" "<<v<<endl;
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	int Get(int i){
		cerr<<i<<endl;
		int res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		cerr<<res<<endl;
		return res;
	}
	int Range(int b,int e){
		b--,e--;
		int res=Get(e);
		if(b>=0)res-=Get(b);
		return res;
	}
	int Kth(int k){
		int res=0;
		for(int i=20;i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
};

struct Query{
	int a,b,c;
};

signed main(){
	int n=read();
	vi t(n);
	REP(i,n)
		t[i]=read();
	vi f(n);
	REP(i,n)
		f[i]=read();
	int kind=0;
	{
		vi tmp=f;
		sort(ALL(tmp));
		tmp.erase(unique(ALL(tmp)),tmp.end());
		for(auto&v:f)
			v=lower_bound(ALL(tmp),v)-tmp.begin();
		kind=tmp.size();
	}
	vector<vi> pos[2];
	REP(k,2){
		pos[k].resize(kind);
	}
	REP(i,n)
		pos[t[i]][f[i]].PB(i);
	REP(_,n-1){
		int a=read()-1,b=read()-1;
		tr[a].PB(b);
		tr[b].PB(a);
	}
	dfs1(0,-1,0);
	InitPars(n);
	vi idx(n);
	REP(i,n)
		idx[ein[i]]=i;
	
	int q=read();
	vector<Query> qs(q);
	vector<ll> ans(q,0);
	REP(i,q){
		int a=read()-1,b=read()-1;
		int c=LCA(a,b);
		qs[i]=Query{a,b,c};
	}
	
	const int B=200*200;
	//const int B=0;
	vi cnt[2];
	REP(k,2)
		cnt[k].resize(n,0);
	vi used(kind,0);
	REP(tt,kind)if(ll(pos[0][tt].size())*pos[1][tt].size()>B){
		used[tt]=1;
		REP(k,2){
			fill(ALL(cnt[k]),0);
			for(auto i:pos[k][tt])
				cnt[k][i]++;
			for(auto i:idx)if(par[0][i]!=-1)
				cnt[k][i]+=cnt[k][par[0][i]];
		}
		REP(i,q){
			int w[2]{};
			REP(k,2){
				w[k]+=cnt[k][qs[i].a];
				w[k]+=cnt[k][qs[i].b];
				w[k]-=cnt[k][qs[i].c];
				int d=par[0][qs[i].c];
				if(d!=-1){
					w[k]-=cnt[k][d];
				}
			}
			ans[i]+=ll(w[0])*w[1];
		}
	}
	
	vector<vector<pi>> qt(n);
	REP(i,q){
		qt[qs[i].a].EB(qs[i].b,i);
		qt[qs[i].b].EB(qs[i].a,i);
	}
	BIT bit(n);
	vi history;
	
	cerr<<pos[0]<<endl;
	cerr<<pos[1]<<endl;
	function<void(int,int)> dfs2;
	dfs2=[&](int v,int p){
		cerr<<v<<endl;
		history.PB(v);
		int x=t[v],y=f[v];
		if(!used[y]){
			for(auto w:pos[x^1][y])if(ein[w]<ein[v]){
				if(Ascend(v,w)){
					int g=history[dep[w]+1];
					cerr<<v<<" "<<w<<" "<<g<<endl;
					bit.Add(0,1);
					bit.Add(ein[g],-1);
					bit.Add(eout[g],1);
				}else{
					cerr<<v<<" "<<w<<endl;
					bit.Add(ein[w],1);
					bit.Add(eout[w],-1);
				}
			}
		}
		for(auto z:qt[v])
			ans[z.second]+=bit.Get(ein[z.first]);
		for(auto to:tr[v])if(to!=p)
			dfs2(to,v);
		if(!used[y]){
			for(auto w:pos[x^1][y])if(ein[w]<ein[v]){
				if(Ascend(v,w)){
					int g=history[dep[w]+1];
					cerr<<v<<" "<<w<<" "<<g<<endl;
					bit.Add(0,-1);
					bit.Add(ein[g],1);
					bit.Add(eout[g],-1);
				}else{
					cerr<<v<<" "<<w<<endl;
					bit.Add(ein[w],-1);
					bit.Add(eout[w],1);
				}
			}
		}
		history.pop_back();
	};
	dfs2(0,-1);
	
	REP(i,q)
		print(ans[i]);
}