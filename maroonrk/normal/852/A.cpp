#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

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

bool waf(string s,bool show){
	int n=s.size();
	REP(bit,1<<(n-1)){
		int sum=0,cur=0;
		REP(i,n){
			if(i>0&&(bit>>(i-1))&1){
				sum+=cur;
				cur=0;
			}
			cur=cur*10+s[i]-'0';
		}
		sum+=cur;
		string tmp=to_string(sum);
		int d=0;
		for(auto c:tmp)
			d+=c-'0';
		if(d<10){
			if(show){
				{
					string t;
					REP(i,n){
						if(i>0&&(bit>>(i-1))&1){
							t+='+';
						}
						t+=s[i];
					}
					cout<<t<<endl;
				}
				{
					string t;
					REP(i,tmp.size()){
						if(i)t+='+';
						t+=tmp[i];
					}
					cout<<t<<endl;
				}
			}
			return true;
		}
	}
	return false;
}

signed main(){
	int n=read();
	string s;
	if(n>0){
		s=readString();
	}else{
		if(n==-1){
			n=23;
			s+='1';
			FOR(i,1,n)
				s+='9';
		}else{
			n=199999;
			REP(i,n)
				s+='9';
		}
	}
	cerr<<s<<endl;
	for(int b=100;b>=1;b--){
		string t;
		int sum=0,cur=0;
		REP(i,n){
			if(i&&rand()%b){
				sum+=cur;
				cur=0;
				t+='+';
			}
			t+=s[i];
			cur*=10;
			cur+=(s[i]-'0');
		}
		sum+=cur;
		if(!waf(to_string(sum),false))
			continue;
		cout<<t<<endl;
		waf(to_string(sum),true);
		break;
	}
}