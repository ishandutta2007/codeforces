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

signed main(){
	int n=read();
	vi a(n);
	REP(i,n)
		a[i]=read();
	sort(ALL(a),greater<int>());
	vi s=a;
	REP(i,n-1)
		s[i+1]+=s[i];
	const auto rng=[&](int l,int r){
		if(r<=l)return int(0);
		r--,l--;
		int res=s[r];
		if(l>=0)res-=s[l];
		return res;
	};
	const auto get=[&](int head,int k){
		int pos=lower_bound(a.begin()+head,a.end(),k,[&](int x,int y){
			return x>y;
		})-a.begin();
		return (pos-head)*k+rng(pos,n);
	};
	vi bot(n+1,0),top(n+1,n);
	{
		int dsum=0;
		REP(i,n){
			dsum+=a[i];
			{
				const int k=i+1;
				int w=dsum;
				w-=k*(k-1);
				w-=get(i+1,k);
				if(w>k)
					bot[i+1]=inf;
				else
					bot[i+1]=w;
			}
			{
				const int k=i+2;
				int w=k*(k-1);
				w+=get(i+1,k);
				w-=dsum;
				top[i]=w;
			}
		}
		REP(i,n)
			chmax(bot[i+1],bot[i]);
		for(int i=n;i>=1;i--)
			chmin(top[i-1],top[i]);
	}
	cerr<<bot<<endl;
	cerr<<top<<endl;
	int allSum=accumulate(ALL(a),int(0));
	int dsum=0;
	vi ans;
	REP(i,n+1){
		int b=bot[i],t=top[i];
		if(i<n)chmax(b,a[i]);
		if(i>0)chmin(t,a[i-1]);
		{
			const int k=i+1;
			int w=k*(k-1);
			w+=get(i,k);
			w-=dsum;
			chmin(t,w);
		}
		for(int j=b;j<=t;j++){
			if((j+allSum)%2==0){
				ans.PB(j);
			}
		}
		if(i<n)
			dsum+=a[i];
	}
	sort(ALL(ans));
	ans.erase(unique(ALL(ans)),ans.end());
	if(ans.empty())
		print(-1);
	else{
		REP(i,ans.size())
			print(ans[i],i==int(ans.size())-1?1:2);
	}
}