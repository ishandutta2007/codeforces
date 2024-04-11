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

using ull=unsigned long long;
using bs=bitset<128>;
const int L=50;
bs conv(const char* s){
	bs res;
	int len=strlen(s);
	for(int i=0;i<L;i+=2){
		char c,d;
		if(i<len)
			c=s[i];
		else
			c='a';
		if(i+1<len)
			d=s[i+1];
		else
			d='a';
		bs x((c-'a')*5+(d-'a'));
		res|=(x<<(i/2*5));
	}
	return res;
}

signed main(){
	int n=read(),m=read();
	unordered_map<bs,int> cnt[60];
	char s[60],t[60];
	REP(i,n){
		scanf("%s",s);
		cnt[strlen(s)][conv(s)]++;
	}
	REP(_,m){
		scanf("%s",s);
		int len=strlen(s);
		int ss=1;
		REP(i,len)if(s[i]=='?')
			ss*=6;
		int ans=0;
		unordered_set<bs> waf[60];
		REP(bit,ss){
			int x=bit;
			int j=0;
			REP(i,len){
				if(s[i]=='?'){
					int y=x%6;x/=6;
					if(y==5)
						continue;
					t[j++]='a'+y;
				}else{
					t[j++]=s[i];
				}
			}
			t[j]=0;
			auto z=conv(t);
			waf[j].insert(z);
		}
		REP(j,60){
			for(const auto&z:waf[j])
				ans+=cnt[j][z];
		}
		print(ans);
	}
}