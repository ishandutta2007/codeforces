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

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

int extgcd(int a,int b,int&x,int&y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		int g=extgcd(b,a%b,y,x);
		y-=a/b*x;
		return g;
	}
}

vector<pi> Cmp(vector<pi> x){
	vector<pi> y;
	for(auto v:x){
		if(y.empty()||y.back().first!=v.first)
			y.PB(pi(v.first,0));
		y.back().second+=v.second;
	}
	return y;
}

vector<pi> Waf(){
	int n=read();
	vi a(n);
	REP(i,n)
		a[i]=read();
	vector<pi> res;
	vector<pi> w;
	REP(i,n){
		for(auto&v:w)
			v.first=gcd(v.first,a[i]);
		w.PB(pi(a[i],1));
		w=Cmp(w);
		res.insert(res.end(),ALL(w));
	}
	sort(ALL(res));
	return Cmp(res);
}

//x_i=floor((a*i+b)/c), i=0,1,..n-1
//a,c>0, b>=0
int gauss_sum(int n,int a,int b,int c){
	if(n==0)return 0;
	//int origA=a,origB=b,origC=c;
	int res=0;
	{
		int p=a/c;
		res+=n*(n-1)/2*p;
		a%=c;
	}
	{
		int p=b/c;
		res+=n*p;
		b%=c;
	}
	if(a==0)return res;
	int top=(a*(n-1)+b)/c;
	res+=top*n;
	int h=(b+1+c-1)/c;
	//cerr<<res<<" "<<top<<" "<<h<<endl;
	if(h<=top)
		res-=gauss_sum(top-h+1,c,c*h-(b+1),a)+top-h+1;
	/*{
		int tmp=0;
		REP(i,n)
			tmp+=(origA*i+origB)/origC;
		cerr<<n<<" "<<origA<<" "<<origB<<" "<<origC<<endl;
		if(tmp!=res){
			cerr<<res<<endl;
			cerr<<tmp<<endl;
			assert(false);
		}
	}*/
	return res;
}

//1 to m inclusive
int Cnt(const vi&val,const vi&cnt,const int m){
	int len=accumulate(ALL(cnt),int(0));
	int n=val.size();
	int li=0,lj=0,lk=0,ri=0,rj=0,rk=0,cur=0,sum=0;
	while(lk<len){
		if(ri<n){
			int rem=cnt[ri]-rj;
			if(cur+rem*val[ri]<=m){
				cur+=rem*val[ri];
				ri++;
				rj=0;
				rk+=rem;
				continue;
			}else{
				{
					int num=(m-cur)/val[ri];
					cur+=num*val[ri];
					rj+=num;
					rk+=num;
					rem-=num;
				}
				int steps;
				if(cur-val[li]*(cnt[li]-1-lj)+rem*val[ri]<=m){
					int hoge=cur+rem*val[ri]-m;
					steps=(hoge+val[li]-1)/val[li];
				}else{
					steps=cnt[li]-lj;
				}
				//cerr<<lk<<" "<<rk<<" "<<steps<<endl;
				sum+=(rk-lk)*steps;
				sum-=steps*(steps-1)/2;
				sum+=gauss_sum(steps,val[li],m-cur,val[ri]);
				cur-=steps*val[li];
				lj+=steps;
				if(lj==cnt[li]){
					li++;
					lj=0;
				}
				lk+=steps;
			}
		}else{
			int rem=len-lk;
			sum+=rem*(rem+1)/2;
			li=n;
			lj=0;
			lk=len;
		}
	}
	return sum;
}

signed main(){
	auto w=Waf();
	cerr<<w<<endl;
	vi val,cnt;
	for(auto v:w){
		val.PB(v.first);
		cnt.PB(v.second);
	}
	int len=accumulate(ALL(cnt),int(0));
	len=len*(len+1)/2;
	int m=(len-1)/2;
	/*{
		vi tmp;
		for(auto v:w)
			REP(_,v.second)
				tmp.PB(v.first);
		cerr<<tmp<<endl;
		vi tmp2;
		int n=tmp.size();
		REP(i,n){
			int sum=0;
			FOR(j,i,n){
				sum+=tmp[j];
				tmp2.PB(sum);
			}
		}
		sort(ALL(tmp2));
		cerr<<tmp2<<endl;
		cerr<<tmp2[m]<<endl;
		cerr<<m<<endl;
		cerr<<Cnt(val,cnt,1)<<endl;
	}*/
	int l=1,r=1;
	REP(i,val.size())
		r+=val[i]*cnt[i];
	while(r-l>1){
		const int mid=(l+r)/2;
		if(Cnt(val,cnt,mid-1)<=m)
			l=mid;
		else
			r=mid;
	}
	print(l);
}