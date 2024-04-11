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

const int MAXH=20;
const int MAXW=100000;
const int MAXR=2100000;
typedef struct R { int x,ones,cnt; } R;

int h,w;
char g[MAXH][MAXW+1];
int x[MAXW];

int ret;
R* r[MAXH+1]; int n[MAXH+1];
R allr[MAXR]; int nallr;

void go(int d) {
	if(d>=h) {
		int cur=0; REP(i,n[d]) cur+=r[d][i].cnt*min(r[d][i].ones,h-r[d][i].ones); if(cur<ret) ret=cur;
		return;
	}
	REP(i,2) {
		r[d+1]=allr+nallr; n[d+1]=0;
		int bit=1<<(h-d-1),a=0,b=0; while(b<n[d]&&(r[d][b].x&bit)==0) ++b; int A=b,B=n[d];
		while(a<A||b<B) {
			int x=min(a<A?r[d][a].x:INT_MAX,b<B?(r[d][b].x^bit):INT_MAX);
			int ones=min(a<A&&r[d][a].x==x?r[d][a].ones+i:INT_MAX,b<B&&(r[d][b].x^bit)==x?r[d][b].ones+1-i:INT_MAX);
			r[d+1][n[d+1]].x=x,r[d+1][n[d+1]].ones=ones,r[d+1][n[d+1]].cnt=0,++n[d+1];
			if(a<A&&r[d][a].x==x&&r[d][a].ones+i==ones) r[d+1][n[d+1]-1].cnt+=r[d][a].cnt,++a;
			if(b<B&&(r[d][b].x^bit)==x&&r[d][b].ones+1-i==ones) r[d+1][n[d+1]-1].cnt+=r[d][b].cnt,++b;
		}
		nallr+=n[d+1]; go(d+1); nallr-=n[d+1];
	}
}

void run() {
	scanf("%d%d",&h,&w); REP(j,h) scanf("%s",g[j]);
	//h=MAXH,w=MAXW; REP(j,h) REP(i,w) g[j][i]=rand()%2+'0';
	REP(i,w) { x[i]=0; REP(j,h) if(g[j][i]=='1') x[i]|=1<<(h-j-1); }
	
	sort(x,x+w);
	nallr=0;
	r[0]=allr+nallr; n[0]=0; REP(i,w) if(n[0]!=0&&r[0][n[0]-1].x==x[i]) ++r[0][n[0]-1].cnt; else r[0][n[0]].x=x[i],r[0][n[0]].ones=0,r[0][n[0]].cnt=1,++n[0]; nallr+=n[0];
	ret=INT_MAX;
	go(0);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}