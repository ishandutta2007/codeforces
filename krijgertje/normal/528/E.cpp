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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

typedef struct L { int a,b,c; } L;
bool operator<(const L &p,const L &q) { return p.b*q.a<q.b*p.a; }
typedef struct P { ld x,y; P(ld x,ld y):x(x),y(y) {} } P;
const P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
const ld operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }

int n;
L l[3000];

P intersect(const L &u,const L &v) {
	ld a=u.a,b=u.b,c=u.c,A=v.a,B=v.b,C=v.c;
	ld den=a*B-b*A;
	P ret((c*B-b*C)/den,(a*C-c*A)/den);
	//printf("\t%.9llf %.9llf\n",ret.x,ret.y);
	return ret;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].c);
	REP(i,n) if(l[i].a<0) l[i].a=-l[i].a,l[i].b=-l[i].b,l[i].c=-l[i].c;
	sort(l,l+n);

	ld ret=0;
	//REP(i,n) { REP(j,n) printf("%c",l[i]<l[j]?'V':'.'); puts(""); }
	REP(i,n) {
		//printf("%d*x+%d*y=%d\n",l[i].a,l[i].b,l[i].c);
		P cur(0,0);
		FOR(jj,1,n) {
			int j=i+jj; if(j>=n) j-=n;
			P now=intersect(l[i],l[j]);
			ret+=cur^now;
			cur=cur+now;
		}
	}
	cout<<ret/2/((ll)n*(n-1)*(n-2)/6)<<endl;
}

int main() {
	run();
	return 0;
}