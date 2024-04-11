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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
int operator*(const P &a,const P &b) { return a.x*b.x+a.y*b.y; }
int operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }
int side(const P &a,const P &b,const P &c) { int res=(b-a)^(c-a); return res<0?-1:res>0?+1:0; }

// num/sqrt(den)
pair<int,int> pointlinedist(const P &p,const P &a,const P &b) {
	int num=abs((p^(b-a))+(b^a)),den=(b-a)*(b-a);
	return MP(num,den);
}

bool circleseg(const P &c,const int r2,const P &a,const P &b) {
	int da2=(a-c)*(a-c),db2=(b-c)*(b-c);
	if(da2==r2||db2==r2||(da2<r2)!=(db2<r2)) return true;
	if(da2<r2) return false;
	if(side(a,b,c)==0) {
		int dab2=(b-a)*(b-a);
		return da2<=dab2&&db2<=dab2;
	} else {
		pair<int,int> dab=pointlinedist(c,a,b);
		if((ll)dab.first*dab.first>(ll)r2*dab.second) return false;
		int num=(b-a)*(c-a),den=(b-a)*(b-a);
		return 0<=num&&num<=den;
	}
}


P p,q;
int na,nb;
P a[1001],b[1001];

bool calc() {
	REP(i,na) REP(j,nb) {
		// point a[i] hits b[j]-b[j+1];
		if(circleseg(q+(a[i]-p),(p-q)*(p-q),b[j],b[j+1])) return true;
		// point b[j] hits a[i]-b[i+1];
		if(circleseg(p+(b[j]-q),(q-p)*(q-p),a[i],a[i+1])) return true;
	}
	return false;
}

void run() {
	scanf("%d%d",&p.x,&p.y); scanf("%d",&na); REP(i,na) scanf("%d%d",&a[i].x,&a[i].y); a[na]=a[0];
	scanf("%d%d",&q.x,&q.y); scanf("%d",&nb); REP(i,nb) scanf("%d%d",&b[i].x,&b[i].y); b[nb]=b[0];

	printf("%s\n",calc()?"YES":"NO");
}

int main() {
	run();
	return 0;
}