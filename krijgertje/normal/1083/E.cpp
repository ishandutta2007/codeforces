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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXN=1000000;
struct Rect { int x,y; ll cost; };
struct Opt { int a; ll b; Opt() {} Opt(int a,ll b):a(a),b(b) {} ll get(int x) { return b-(ll)a*x; } };
bool operator<(const Rect &a,const Rect &b) { return a.x<b.x; }

int n;
Rect rect[MAXN];

ll dp[MAXN];

Opt q[MAXN+1]; int qhead,qtail;

ll overtakes(const Opt &p,const Opt &q) {
	// p.a>q.a: p.b-p.a*x>=q.b-q.a*x -> x<=(p.b-q.b)/(p.a-q.a)
	ll num=p.b-q.b; int den=p.a-q.a;
	ll ret=num>=0?num/den:(num-den+1)/den;
	//printf("\tovertakes at %lld\n",ret);
	return ret;
}

ll solve() {
	sort(rect,rect+n);
	REP(i,n-1) assert(rect[i].x<rect[i+1].x&&rect[i].y>rect[i+1].y);
	//REP(i,n) printf("%d %d %lld\n",rect[i].x,rect[i].y,rect[i].cost);

	qhead=qtail=0; q[qhead++]=Opt(0,0);
	REP(i,n) {
		// dp[i]=max(b-a*y[i])+x[i]*y[i]-cost[i]
		// a is increasing, y[i] is decreasing
		while(qhead-qtail>=2&&rect[i].y<=overtakes(q[qtail+1],q[qtail])) ++qtail;
		dp[i]=q[qtail].get(rect[i].y)+(ll)rect[i].x*rect[i].y-rect[i].cost;
		//printf("%d: %lld [",i,dp[i]); FOR(j,qtail,qhead) { if(j!=qtail) printf(" <%lld> ",overtakes(q[j],q[j-1])); printf("%lld-%d*x",q[j].b,q[j].a); } printf("]\n");
		Opt cur(rect[i].x,dp[i]);
		while(qhead-qtail>=2&&overtakes(cur,q[qhead-1])>=overtakes(q[qhead-1],q[qhead-2])) --qhead;
		q[qhead++]=cur;
		//printf("%d: %lld [",i,dp[i]); FOR(j,qtail,qhead) { if(j!=qtail) printf(" <%lld> ",overtakes(q[j],q[j-1])); printf("%lld-%d*x",q[j].b,q[j].a); } printf("]\n");
	}
	ll ret=0; REP(i,n) ret=max(ret,dp[i]); return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%lld",&rect[i].x,&rect[i].y,&rect[i].cost);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}