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

const int NONE=0,ADD=1,SUB=2;
const int MAXN=5000;
const int MAXQ=100000;
const int XLIM=MAXN+1,YLIM=2*MAXN+1;

int n,nq;
int val[XLIM+1][YLIM+1];

int get(int x,int y) {
	//printf("get(%d,%d,%d)",g,x,y);
	int ret=0;
	while(x>0) {
		int cy=y;
		while(cy>0) {
			ret+=val[x][cy];
			cy-=cy&-cy;
		}
		x-=x&-x;
	}
	//printf("=%d\n",ret);
	return ret;
}
void mod(int x,int y,int by) {
	//printf("mod(%d,%d,%d,%d)\n",g,x,y,by);
	while(x<=XLIM) {
		int cy=y;
		while(cy<=YLIM) {
			val[x][cy]+=by;
			cy+=cy&-cy;
		}
		x+=x&-x;
	}
}
void modlane(int lx,int hx,int y,int by) {
	mod(lx,y,by); mod(hx+1,y,-by);
}

int qtype[MAXQ],qdir[MAXQ],qx[MAXQ],qy[MAXQ],qlen[MAXQ];
int ret[MAXQ];

void run() {
	scanf("%d%d",&n,&nq);

	REP(qi,nq) {
		scanf("%d",&qtype[qi]);
		if(qtype[qi]==1) scanf("%d%d%d%d",&qdir[qi],&qx[qi],&qy[qi],&qlen[qi]);
		if(qtype[qi]==2) scanf("%d%d",&qx[qi],&qy[qi]);
	}
	REP(g,3) {
		memset(val,0,sizeof(val));
		REP(qi,nq) {
			int dir=qdir[qi],x=qx[qi],y=qy[qi],len=qlen[qi];
			if(qtype[qi]==1) {
				if(dir==1&&g==NONE) modlane(x,x+len,y,+1);
				if(dir==2&&g==NONE) modlane(x,x+len,y+1,-1);
				if(dir==3&&g==NONE) modlane(x-len,x,y,+1);
				if(dir==4&&g==NONE) modlane(x-len,x,y+1,-1);
				if(dir==1&&g==ADD) modlane(x,x+len,x+y+len+1,-1);
				if(dir==2&&g==SUB) modlane(x,x+len,y+n-x-len,+1);
				if(dir==3&&g==SUB) modlane(x-len,x,y+n-x+1+len,-1);
				if(dir==4&&g==ADD) modlane(x-len,x,x+y-len,+1);
			}
			if(qtype[qi]==2) {
				if(g==NONE) ret[qi]+=get(x,y);
				if(g==ADD) ret[qi]+=get(x,y+x);
				if(g==SUB) ret[qi]+=get(x,y+n-x);
			}
		}
	}

	REP(qi,nq) if(qtype[qi]==2) printf("%d\n",ret[qi]);

}

int main() {
	run();
	return 0;
}