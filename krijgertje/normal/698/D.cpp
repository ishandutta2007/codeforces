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

const int MAXT=7;
const int MAXP=1000;
typedef struct P { int x,y,g,idx; } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; if(a.y!=b.y) return a.y<b.y; return a.g<b.g; }

int nt,np;
P t[MAXT];
P p[MAXP];
P d[MAXP];

int prv[MAXT][MAXP];

pair<int,int> stck[MAXP]; int nstck;
bool dead[MAXP];
bool can(int lft) {
	if(nstck==0) return true;
	int at=stck[nstck-1].first,to=stck[nstck-1].second;
	int cur=prv[at][to]; while(cur!=-1&&dead[cur]) cur=prv[at][cur];
	if(cur==-1) {
		--nstck; dead[to]=true;
		bool ret=can(lft);
		dead[to]=false; stck[nstck++]=MP(at,to);
		return ret;
	}
	REP(i,nt) if(lft&(1<<i)) {
		stck[nstck++]=MP(i,cur);
		bool ret=can(lft-(1<<i));
		--nstck;
		if(ret) return true;
	}
	return false;
}


void run() {
	scanf("%d%d",&nt,&np);
	REP(i,nt) scanf("%d%d",&t[i].x,&t[i].y);
	REP(j,np) scanf("%d%d",&p[j].x,&p[j].y);

	REP(i,nt) {
		REP(j,np) {
			int dx=p[j].x-t[i].x,dy=p[j].y-t[i].y,g=gcd(abs(dx),abs(dy)); dx/=g,dy/=g;
			d[j].x=dx,d[j].y=dy,d[j].g=g,d[j].idx=j;
		}
		sort(d,d+np);
		REP(j,np) prv[i][d[j].idx]=j==0||d[j-1].x!=d[j].x||d[j-1].y!=d[j].y?-1:d[j-1].idx;
	}
	//REP(i,nt) { printf("%d:",i); REP(j,np) printf(" %d",prv[i][j]); puts(""); }

	int ret=0;
	REP(j,np) {
		bool found=false;
		REP(i,nt) {
			nstck=0; REP(k,np) dead[k]=false; stck[nstck++]=MP(i,j);
			if(can((1<<nt)-(1<<i)-1)) { found=true; break; }
		}
		if(found) ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}