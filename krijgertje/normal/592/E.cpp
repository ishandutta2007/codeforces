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

const int MAXN=345678;

typedef struct P { int x,y; } P;
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
bool operator<(const P &a,const P &b) {
	bool apos=a.y>0||a.y==0&&a.x>0;
	bool bpos=b.y>0||b.y==0&&b.x>0;
	if(apos!=bpos) return apos;
	ll side=a^b;
	if(side!=0) return side>0;
	return false;
}

int n,X0,Y0;
P p[2*MAXN];

void run() {
	scanf("%d%d%d",&n,&X0,&Y0);
	REP(i,n) {
		scanf("%d%d",&p[i].x,&p[i].y),p[i].x-=X0,p[i].y-=Y0;
		if(p[i].x==0&&p[i].y==0) --i,--n;
	}
	sort(p,p+n);
	REP(i,n) p[n+i]=p[i];
	ll ret=(ll)n*(n-1)*(n-2)/6;
	//REP(i,n) printf("(%d,%d)",p[i].x,p[i].y); puts("");
	for(int at=0,to=0,rat=0,rto=0;at<n;at=to) {
		while(to<n&&!(p[at]<p[to])&&!(p[to]<p[at])) ++to;
		if(rat<to) rat=to; while(rat<at+n&&(p[at]^p[rat])>0) ++rat;
		rto=rat; while(rto<at+n&&(p[at]^p[rto])>=0) ++rto;
		ll a=to-at,b=rat-to,c=rto-rat;
		//FOR(i,at,to) printf("(%d,%d)",p[i].x,p[i].y); printf(" -> before on line: %I64d, on side: %I64d, after on line: %I64d\n",a,b,c);
		ret-=a*(a-1)*(a-2)/6; // aaa
		ret-=a*(a-1)/2*b; // aab
		ret-=a*(a-1)/2*c; // aac
		ret-=a*b*(b-1)/2; // abb
		ret-=a*b*c; // abc
	}
	printf("%I64d\n",ret);


}

int main() {
	run();
	return 0;
}