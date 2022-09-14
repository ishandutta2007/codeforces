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

const int MOD=1000000007;
typedef struct P { int x, y; P() {} P(int x,int y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }

ll darea(const P &a,const P &b,const P &c) { return (b-a)^(c-a); }
int side(const P &a,const P &b,const P &c) { ll ret=darea(a,b,c); return (ret>0?1:0)-(ret<0?1:0); }

int n;
P p[200];
int ways[200][200]; // ways[i][j] to triangulate i=i+1..j-1=j=i iff it is a simple ccw polygon

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	ll sumdarea=0; FOR(i,2,n) sumdarea+=darea(p[0],p[i-1],p[i]); if(sumdarea<0) reverse(p,p+n);

	REP(i,n-1) ways[i][i+1]=1;
	FOR(len,2,n) REPE(i,n-len) {
		int j=i+len;
		FORE(k,i+1,j-1) {
			if(side(p[i],p[j],p[k])>=0) continue;
			ways[i][j]=(ways[i][j]+(ll)ways[i][k]*ways[k][j])%MOD;
		}
	}
	printf("%d\n",ways[0][n-1]);
}

int main() {
	run();
	return 0;
}