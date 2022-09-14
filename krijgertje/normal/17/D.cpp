#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
using namespace std; 

#define PB push_back 
#define MP make_pair 
#define SZ(v) ((int)(v).size()) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(i,a,b) for(int i=(a);i<=(b);++i) 
#define REPE(i,n) FORE(i,0,n) 
#define FORSZ(i,a,v) FOR(i,a,SZ(v)) 
#define REPSZ(i,v) REP(i,SZ(v))
typedef long long ll; 

char b[1000001];
char n[1000001];
char nsub1[1000001];
int c;

vector<pair<int,pair<int,int> > > getfactors(int x) {
	vector<pair<int,pair<int,int> > > ret;
	for(int i=2;i<=x/i;++i) if(x%i==0) {
		ret.PB(MP(i,MP(1,i))),x/=i;
		while(x%i==0) ret.back().second.first++,ret.back().second.second*=i,x/=i;
	}
	if(x>1) ret.PB(MP(x,MP(1,x))),x/=x;
	return ret;
}

void decr(char *s) {
	int n=strlen(s);
	for(int i=n-1;i>=0;--i) if(s[i]=='0') s[i]='9'; else { --s[i]; return; }
}

int getmod(char *s,int m) {
	ll ret=0;
	for(int i=0;s[i]!='\0';++i) ret=(ret*10+s[i]-'0')%m;
	return ret;
}

int mypow(int x,int n,int m) {
	if(n==0) return 1;
	if(n%2==1) return ((ll)mypow(x,n-1,m)*x)%m;
	return mypow(((ll)x*x)%m,n/2,m);
}

int calc(int b,char *n,int m,int p,int e) {
	int nval=0; bool nsmall=true;
	for(int i=0;n[i]!='\0';++i) { nval=nval*10+(n[i]-'0'); if(nval>e) { nsmall=false; break; } }
	if(nsmall) return mypow(b,nval,m);
	int x=mypow(b,e,m);
	if(x==0) return 0;
	int phi=m/p*(p-1);
	int nmodphi=getmod(n,phi);
//	printf("%d^%d mod %d (%d %d=%d^%d)\n",b,nmodphi,m,phi,m,p,e);
	return mypow(b,nmodphi,m);
}

// a*x+b*y==gcd(a,b)
pair<int,int> egcd(int a,int b) {
	if(b==0) return MP(1,0);
	pair<int,int> x=egcd(b,a%b);
	// x.first*b+x.second*(a-(a/b)*b)==1
	return MP(x.second,x.first-(a/b)*x.second);
}

int bf() {
	int bmodc=getmod(b,c);
	int nmodlarge=getmod(n,1000000000);
	int ret=mypow(bmodc,nmodlarge-1,c);
	ret=((ll)ret*((bmodc+c-1)%c))%c;
	if(ret==0) ret=c;
	return ret;
}

void run() {
	//(b-1)*b^(n-1) mod c
	scanf("%s%s%d",b,n,&c);
	strcpy(nsub1,n); decr(nsub1);
	vector<pair<int,pair<int,int> > > factors=getfactors(c);
	int bmodc=getmod(b,c);
	vector<int> a; REPSZ(i,factors) a.PB(calc(bmodc,nsub1,factors[i].second.second,factors[i].first,factors[i].second.first));
	vector<int> e;
	REPSZ(i,factors) {
		int m=factors[i].second.second;
		pair<int,int> cur=egcd(m,c/m);
		int s=cur.second;
		s%=c; if(s<0) s+=c;
		e.PB(((ll)s*(c/m))%c);
//		printf("%d*%d+%d*%d==1 -> %d\n",cur.first,m,cur.second,c/m,e[i]);
	}
//	REPSZ(i,factors) printf("%d^%s=%d mod %d (%d)\n",bmodc,nsub1,a[i],factors[i].second.second,e[i]);
	int ret=0; REPSZ(i,a) ret=(ret+(ll)a[i]*e[i])%c;
	ret=((ll)ret*((bmodc+c-1)%c))%c;
	if(ret==0) ret=c;
	printf("%d\n",ret);
//	int check=bf();
//	assert(ret==check);
}

int main() {
	run();
	return 0;
}