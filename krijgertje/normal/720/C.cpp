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

int h,w,n,want;
bool haveret; char ret[MAXN+1],nret[MAXN+1];

void bf() {
	FOR(msk,1,1<<n) {
		int cur=0;
		REP(x,h-1) REP(y,w-1) {
			int cnt=0;
			REP(dx,2) REP(dy,2) if((msk>>((x+dx)*w+(y+dy)))&1) ++cnt;
			if(cnt==3) ++cur; if(cnt==4) cur+=4;
		}
		if(cur==want) { haveret=true; REP(j,n) ret[j]=(msk>>j)&1?'*':'.'; return; }
	}
}

void greedy() { // w>=5
	if(h==2&&want==(w-2)*4) { haveret=true; REP(x,h) REP(y,w) ret[x*w+y]=0<=y&&y<w-1?'*':'.'; return; }
	if(h==2&&want==(w-3)*4) { haveret=true; REP(x,h) REP(y,w) ret[x*w+y]=1<=y&&y<w-1?'*':'.'; return; }
	if(h==3&&want==(w-2)*8) { haveret=true; REP(x,h) REP(y,w) ret[x*w+y]=0<=y&&y<w-1?'*':'.'; return; }

	int left=want; REP(x,h) REP(y,w) ret[x*w+y]=x==0?'*':'.';
	int x,y;
	for(x=1;x<h;++x) {
		for(y=0;y<w;++y) {
			if(left<=3||x==h-1&&w-y==4) break;
			ret[x*w+y]='*'; left-=y==0?1:y==w-1?3:4;
		}
		if(left<=3||x==h-1&&w-y==4) break;
	}
	if(x==h-1&&w-y==4) {
		REP(msk,1<<4) {
			int cur=0;
			REP(yy,4) {
				int cnt=0;
				REP(dy,2) if(yy+dy==0||(msk>>(yy+dy-1)&1)) ++cnt;
				if(cnt==1) ++cur; if(cnt==2) cur+=4;
			}
			if(cur-1==left) { haveret=true; REP(j,4) ret[x*w+y+j]=(msk>>j)&1?'*':'.'; return; }
		}
	}
	if(left<=3) {
		int dy=w-y; //printf("left=%d dy=%d\n",left,dy);
		int y1=dy==2||dy>=4?w-1:0;
		int y2=dy==3?w-2:dy>=4?w-3:dy==2?1:2;
		if(left&1) ret[(x+(y1<y?1:0))*w+y1]='*';
		if(left&2) ret[(x+(y2<y?1:0))*w+y2]='*';
		haveret=true;
	}
}

void run() {
	scanf("%d%d%d",&h,&w,&want); n=h*w; haveret=false;
	if(h<=4&&w<=4) {
		bf();
	} else {
		bool swp=w<h;
		if(swp) swap(w,h);
		greedy();
		if(swp) { swap(w,h); REP(x,h) REP(y,w) nret[x*w+y]=ret[y*h+x]; REP(i,n) ret[i]=nret[i]; }
	}
	if(!haveret) printf("-1\n"); else REP(x,h) { REP(y,w) printf("%c",ret[x*w+y]); puts(""); }
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) { if(i!=1) puts(""); run(); }
	return 0;
}