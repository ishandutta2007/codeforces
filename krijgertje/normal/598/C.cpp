#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
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
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
typedef struct P { int x,y,idx; P(int x,int y):x(x),y(y),idx(-1) {} P() {} } P;
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.x); }
const ll operator*(const P &a,const P &b) { return (ll)a.x*b.x+(ll)a.y*b.y; }
const ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }

bool operator<(const P &a,const P &b) {
	bool apos=a.y>0||a.y==0&&a.x>0,bpos=b.y>0||b.y==0&&b.x>0;
	if(apos!=bpos) return apos;
	ll cross=a^b;
	if(cross!=0) return cross>0;
	return a.idx<b.idx;
}

int n; P p[MAXN];
bool better(ll a,ll b,ll c,ll d) {
	if((a>=0)!=(c>=0)) return a>=0;
	bool inv=a<0; a*=a; c*=c;
	while(true) {
		ll aa=a/b,cc=c/d;
		if(aa!=cc) return !inv?aa>cc:aa<cc;
		a%=b,c%=d;
		if(a==0||c==0) break;
		inv=!inv; swap(a,b); swap(c,d);
	}
	if(a!=0||c!=0) return !inv?a!=0:c!=0;
	return false;
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y),p[i].idx=i; sort(p,p+n);
	//REP(i,n) printf("(%d,%d)",p[i].x,p[i].y); puts("");

	//cos(a)=(A*B)/(len(A)*len(B))
	ll rnum=-2,rdensqr=1; int ret[2];
	REP(i,n) {
		const P &a=p[i],&b=p[i+1==n?0:i+1];
		if((a^b)<0) continue;
		ll cnum=a*b,cdensqr=(a*a)*(b*b);
		//printf("%lld/sqrt(%lld) = %lf\n",cnum,cdensqr,1.0*cnum/sqrt(cdensqr));
		if(better(cnum,cdensqr,rnum,rdensqr)) rnum=cnum,rdensqr=cdensqr,ret[0]=a.idx,ret[1]=b.idx;
		//printf("->%lld/sqrt(%lld) = %lf\n",rnum,rdensqr,1.0*rnum/sqrt(rdensqr));
	}
	printf("%d %d\n",ret[0]+1,ret[1]+1);

}

int main() {
	run();
	return 0;
}