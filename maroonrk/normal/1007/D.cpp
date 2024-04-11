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

const int Nmax=100010;
vi tr[Nmax];
int par[Nmax],dep[Nmax],sub[Nmax],grp[Nmax],pos[Nmax],gsz[Nmax],gpar[Nmax],gdep[Nmax],gord;
int dfs1(int v,int p,int d){
	par[v]=p;
	sub[v]=1;
	dep[v]=d;
	for(auto to:tr[v])if(to!=p)
		sub[v]+=dfs1(to,v,d+1);
	return sub[v];
}
void dfs2(int v,int p,int g,int d){
	grp[v]=g;
	if(gsz[g]==0){
		gpar[g]=p;
		gdep[g]=d;
	}
	pos[v]=gsz[g]++;
	pi si(0,-1);
	for(auto to:tr[v])if(to!=p)
		chmax(si,pi(sub[to],to));
	for(auto to:tr[v])if(to!=p){
		if(to==si.second)
			dfs2(to,v,g,d);
		else
			dfs2(to,v,gord++,d+1);
	}
}
int LCA(int a,int b){
	if(gdep[grp[a]]>gdep[grp[b]])
		swap(a,b);
	while(gdep[grp[a]]<gdep[grp[b]])
		b=gpar[grp[b]];
	while(grp[a]!=grp[b]){
		a=gpar[grp[a]];
		b=gpar[grp[b]];
	}
	if(dep[a]>dep[b])swap(a,b);
	return a;
}
struct Path{
	int u,v,lca;
};
struct SegTree{
	vector<pi> buf;
	int s;
	void Init(int n){
		s=1;
		while(s<n)s*=2;
		buf.assign(s*2,pi(-inf,-1));
	}
	void Update(int i,pi x){
		i+=s;
		buf[i]=x;
		while(i>>=1)
			buf[i]=max(buf[i*2],buf[i*2+1]);
	}
	pi Get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return pi(-inf,-1);
		if(b<=l&&r<=e)return buf[i];
		return max(Get(b,e,l,(l+r)/2,i*2),Get(b,e,(l+r)/2,r,i*2+1));
	}
	pi Get(int b,int e){
		if(e<=b)return pi(-inf,-1);
		return Get(b,e,0,s,1);
	}
};
struct Waf{
	vector<pi> left,right;
	vi cnt;
	vector<pair<pi,int>> raw;
	SegTree seg;
	void Add(pi p,int i){
		raw.PB(MP(p,i));
	}
	void SetUp(){
		sort(ALL(raw));
		seg.Init(raw.size());
		Clear();
	}
	//path -> pi
	int NextVertex(pi p,int i){
		int e1=lower_bound(ALL(raw),MP(p,i))-raw.begin();
		assert(e1<int(raw.size())&&raw[e1]==MP(p,i));
		int e2=lower_bound(ALL(raw),MP(pi(p.second+1,-inf),-inf))-raw.begin();
		pi g=seg.Get(0,e1);
		if(p.first<=g.first){
			int j=g.second;
			seg.Update(j,pi(-inf,-1));
			return raw[j].second;
		}else{
			g=seg.Get(e1+1,e2);
			if(p.first<=g.first){
				int j=g.second;
				seg.Update(j,pi(-inf,-1));
				return raw[j].second;
			}
		}
		return -1;
	}
	void Clear(){
		REP(i,raw.size())
			seg.Update(i,pi(raw[i].first.second,i));
	}
};
int ord[Nmax],head;
Waf wafs[Nmax];
void Add(int p,int v,int i){
	while(p!=v){
		cerr<<p<<" "<<v<<" "<<i<<endl;
		if(grp[p]==grp[v]){
			wafs[grp[v]].Add(pi(pos[p]+1,pos[v]),i);
			break;
		}else{
			wafs[grp[v]].Add(pi(0,pos[v]),i);
			v=gpar[grp[v]];
		}
	}
}
void dfs(int v,bool rev,vi&vis,const vector<Path>&ps){
	int a=ps[v^rev].u,b=ps[v^rev].v,lca=ps[v^rev].lca;
	
	cerr<<v<<endl;
	ord[v]=0;
	
	REP(_,2){
		while(lca!=a){
			int to;
			if(grp[lca]==grp[a]){
				to=wafs[grp[a]].NextVertex(pi(pos[lca]+1,pos[a]),v^rev);
				if(to==-1)
					break;
			}else{
				to=wafs[grp[a]].NextVertex(pi(0,pos[a]),v^rev);
				if(to==-1){
					a=gpar[grp[a]];
					continue;
				}
			}
			cerr<<v<<" "<<to<<endl;
			to^=1^rev;
			if(ord[to]==-1&&v/2!=to/2){
				cerr<<v<<" "<<to<<endl;
				dfs(to,rev,vis,ps);
			}
		}
		a=b;
	}
	
	vis.PB(v);
	ord[v]=head++;
}

signed main(){
	int n=read();
	REP(i,n-1){
		int u=read()-1,v=read()-1;
		tr[u].PB(v);
		tr[v].PB(u);
	}
	dfs1(0,-1,0);
	dfs2(0,-1,gord++,0);
	int m=read();
	vector<Path> ps(m*2);
	REP(i,m){
		int a=read()-1,b=read()-1,c=read()-1,d=read()-1;
		ps[i*2]=Path{a,b,LCA(a,b)};
		ps[i*2+1]=Path{c,d,LCA(c,d)};
	}
	cerr<<endl;
	REP(i,m*2){
		Add(ps[i].lca,ps[i].u,i);
		Add(ps[i].lca,ps[i].v,i);
	}
	cerr<<endl;
	REP(i,gord)
		wafs[i].SetUp();
	ONE(ord);
	cerr<<endl;
	REP(i,m*2)if(ord[i]==-1){
		vi tmp;
		dfs(i,true,tmp,ps);
	}
	cerr<<endl;
	REP(i,gord)
		wafs[i].Clear();
	vector<pi> oi(m*2);
	REP(i,m*2)
		oi[i]=pi(ord[i],i);
	sort(ALL(oi),greater<pi>());
	vi used(m,0),ans(m,-1);
	ONE(ord);
	REP(_i,m*2){
		int i=oi[_i].second;
		if(ord[i]==-1){
			vi vis;
			cerr<<endl;
			dfs(i,false,vis,ps);
			for(auto v:vis){
				if(used[v/2]){
					No();
				}
				used[v/2]=1;
			}
			for(auto v:vis){
				used[v/2]=0;
				if(ans[v/2]==-1)
					ans[v/2]=v%2;
			}
		}
	}
	Yes(false);
	REP(i,m)
		print(ans[i]+1);
}