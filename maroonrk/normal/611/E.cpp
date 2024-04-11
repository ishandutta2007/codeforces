#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

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
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
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
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

const int inf=LLONG_MAX/3;

void No(){
	cout<<-1<<endl;
	exit(0);
}

signed main(){
	int n=read(),a=read(),b=read(),c=read();
	if(a>b)swap(a,b);
	if(a>c)swap(a,c);
	if(b>c)swap(b,c);
	vi t;
	REP(i,n)
		t.PB(read());
	sort(ALL(t));
	int ab=a+b,ac=a+c,bc=b+c,abc=a+b+c;
	if(ab>=c){
		int wab=0,wac=0,wbc=0,wabc=0,wa=0,wb=0,wc=0;
		for(auto v:t)
			if(v<=a)
				wa++;
			else if(v<=b)
				wb++;
			else if(v<=c)
				wc++;
			else if(v<=ab)
				wab++;
			else if(v<=ac)
				wac++;
			else if(v<=bc)
				wbc++;
			else if(v<=abc)
				wabc++;
			else
				No();
		int ans=wab+wac+wbc+wabc;
		{
			int g=min(wc,wab);
			wc-=g;
			wac+=wab-g;
		}
		{
			int g=min(wb,wac);
			wb-=g;
			wbc+=wac-g;
		}
		{
			int g=min(wa,wbc);
			wa-=g;
		}
		wb+=wa;
		wc+=wb;
		int k=min({wa,wb/2,wc/3});
		int p=(wc-3*k+1)/2;
		ans+=k;
		ans+=p;
		cout<<ans<<endl;
	}else{
		int wab=0,wac=0,wbc=0,wabc=0,wa=0,wb=0,wc=0;
		for(auto v:t)
			if(v<=a)
				wa++;
			else if(v<=b)
				wb++;
			else if(v<=ab)
				wab++;
			else if(v<=c)
				wc++;
			else if(v<=ac)
				wac++;
			else if(v<=bc)
				wbc++;
			else if(v<=abc)
				wabc++;
			else
				No();
		int ans=wc+wac+wbc+wabc;
		{
			int g=min(wb,wac);
			wb-=g;
			wbc+=wac-g;
		}
		{
			int g=min(wa,wbc);
			wa-=g;
		}
		int ad=inf;
		REP(i,wc+1){
			int p=wa,q=wb,r=wab;
			int s=wc-i,z=wc-i,u=i;
			{
				int g=min(r,u);
				r-=g;
				z+=u-g;
			}
			{
				int g=min(q,z);
				q-=g;
				s+=z-g;
			}
			{
				int g=min(p,s);
				p-=g;
			}
			q+=p;
			r+=q;
			int k=min({p,q/2,r/3});
			int x=(r-3*k+1)/2;
			chmin(ad,k+x);
		}
		cout<<ans+ad<<endl;
	}
}