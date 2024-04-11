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

vector<string> flip(vector<string> x){
	int n=x.size(),m=x[0].size();
	vector<string> res(m,string(n,'.'));
	REP(i,m)REP(j,n)
		res[i][j]=x[j][i];
	return res;
}

pair<int,vector<string>> Solve(vector<string> x){
	int n=x.size(),m=x[0].size();
	string waf="ACGT";
	sort(ALL(waf));
	pair<int,string> ans(inf,"");
	do{
		if(waf[0]<waf[1]&&waf[2]<waf[3]){
			int sum=0;
			REP(i,n){
				int k=(i%2)*2;
				int mn=inf;
				REP(_,2){
					int cnt=0;
					REP(j,m)
						if(x[i][j]!=waf[k+j%2])
							cnt++;
					chmin(mn,cnt);
					swap(waf[k],waf[k+1]);
				}
				sum+=mn;
			}
			chmin(ans,make_pair(sum,waf));
		}
	}while(next_permutation(ALL(waf)));
	waf=ans.second;
	vector<string> res(n,string(m,'.'));
	REP(i,n){
		int k=(i%2)*2;
		pi mn(inf,-1);
		REP(_,2){
			int cnt=0;
			REP(j,m)
				if(x[i][j]!=waf[k+j%2])
					cnt++;
			chmin(mn,pi(cnt,_));
			swap(waf[k],waf[k+1]);
		}
		if(mn.second)
			swap(waf[k],waf[k+1]);
		REP(j,m)
			res[i][j]=waf[k+j%2];
	}
	return make_pair(ans.first,res);
}

signed main(){
	int n=read(),m=read();
	vector<string> x(n);
	REP(i,n){
		x[i]=readString();
	}
	auto ans1=Solve(x);
	auto ans2=Solve(flip(x));
	ans2.second=flip(ans2.second);
	auto ans=min(ans1,ans2);
	{
		int dif=0;
		REP(i,n)REP(j,m)
			if(x[i][j]!=ans.second[i][j])
				dif++;
		assert(dif==ans.first);
		cerr<<dif<<endl;
	}
	REP(i,n)
		printf("%s\n",ans.second[i].c_str());
}