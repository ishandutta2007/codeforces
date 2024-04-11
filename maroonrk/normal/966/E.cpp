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

const int Nmax=100010;
const int Mmax=100010;
const int B=200;

int p[Nmax],t[Nmax],q[Mmax];
vi tr[Nmax];
int idx[Nmax],ord;
void dfs(int v){
	idx[v]=ord++;
	for(auto ch:tr[v])
		dfs(ch);
}
bool affect[Nmax],vac[Nmax];
int cnt[Nmax],up[Nmax],buf[Nmax],fi[Nmax],la[Nmax],lz[Nmax];

signed main(){
	int n=read(),m=read();
	p[0]=-1;
	FOR(i,1,n){
		p[i]=read()-1;
		tr[p[i]].PB(i);
	}
	REP(i,n)
		t[i]=read();
	REP(i,m)
		q[i]=abs(read())-1;
	dfs(0);
	{
		vi pTmp(n,-1);
		REP(i,n)
			pTmp[idx[i]]=p[i]==-1?-1:idx[p[i]];
		REP(i,n)
			p[i]=pTmp[i];
	}
	{
		vi tTmp(n);
		REP(i,n)
			tTmp[idx[i]]=t[i];
		REP(i,n)
			t[i]=tTmp[i];
	}
	REP(i,m)
		q[i]=idx[q[i]];
	
	cerr<<vi(p,p+n)<<endl;
	cerr<<vi(t,t+n)<<endl;
	cerr<<vi(q,q+m)<<endl;

	vi anses(m);
	int ans=0;
	for(int b=0;b<m;b+=B){
		int e=min(b+B,m);
		ZERO(affect);
		ZERO(up);
		ZERO(cnt);
		ZERO(lz);
		FOR(i,b,e){
			affect[q[i]]=true;
			cnt[q[i]]=1;
		}
		for(int i=n-1;i>=0;i--){
			if(cnt[i]>=1&&p[i]!=-1)
				cnt[p[i]]++;
			if(cnt[i]>=2)
				affect[i]=true;
		}
		int head=0;
		REP(i,n)if(affect[i]){
			fi[i]=head;
			int cur=p[i];
			while(cur!=-1&&!affect[cur]){
				if(!vac[cur])
					buf[head++]=t[cur];
				cur=p[cur];
			}
			la[i]=head;
			sort(buf+fi[i],buf+la[i]);
			up[i]=cur;
		}
		FOR(i,b,e){
			int cur=q[i];
			int ch=vac[cur]?1:-1;
			if(t[cur]+lz[cur]<0)
				ans+=ch;
			vac[cur]^=true;
			while(cur!=-1){
				if(!vac[cur]&&t[cur]+lz[cur]<0)
					ans--;
				ans-=lower_bound(buf+fi[cur],buf+la[cur],-lz[cur])-(buf+fi[cur]);
				lz[cur]+=ch;
				if(!vac[cur]&&t[cur]+lz[cur]<0)
					ans++;
				ans+=lower_bound(buf+fi[cur],buf+la[cur],-lz[cur])-(buf+fi[cur]);
				cur=up[cur];
			}
			anses[i]=ans;
		}
		for(int i=n-1;i>=0;i--)if(affect[i]){
			int cur=i;
			do{
				t[cur]+=lz[i];
				cur=p[cur];
			}while(cur!=-1&&!affect[cur]);
		}
	}
	REP(i,m)
		print(anses[i],i==m-1?1:2);
}