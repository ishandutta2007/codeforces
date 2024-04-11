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

const int MAXH=1000000;
const int MAXW=1000000;
const int MAXN=100000;
const int MOD=1000000007;
typedef struct R { int x1,y1,x2,y2; } R;

int h,w,n;
int shead[MAXH],snxt[MAXN];
int thead[MAXH],tnxt[MAXN];
R r[MAXN];
int cur[MAXN],ncur;

int sval[4*MAXW]; // -1 == no val
int slazy[4*MAXW];

inline void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void spush(int x) {
	if(sval[x]!=-1) { sval[2*x+1]=sval[2*x+2]=sval[x]; slazy[2*x+1]=slazy[2*x+2]=0; sval[x]=-1; }
	if(slazy[x]!=0) { inc(slazy[2*x+1],slazy[x]),inc(slazy[2*x+2],slazy[x]); slazy[x]=0; }
}
void sset(int x,int l,int h,int L,int H,int VAL) {
	if(h<L||l>H) return;
	//printf("sset(%d,%d,%d,%d,%d,%d)\n",x,l,h,L,H,VAL);
	if(L<=l&&h<=H) { sval[x]=VAL,slazy[x]=0; return; }
	spush(x);
	int m=l+(h-l)/2;
	sset(2*x+1,l,m,L,H,VAL); sset(2*x+2,m+1,h,L,H,VAL);
}
void sinc(int x,int l,int h,int L,int H,int BY) {
	if(h<L||l>H) return;
	//printf("sinc(%d,%d,%d,%d,%d,%d)\n",x,l,h,L,H,BY);
	if(L<=l&&h<=H) { inc(slazy[x],BY); return; }
	spush(x);
	int m=l+(h-l)/2;
	sinc(2*x+1,l,m,L,H,BY); sinc(2*x+2,m+1,h,L,H,BY);
}
int sget(int x,int l,int h,int IDX) {
	if(sval[x]!=-1) return sval[x]+slazy[x];
	spush(x);
	int m=l+(h-l)/2;
	return IDX<=m?sget(2*x+1,l,m,IDX):sget(2*x+2,m+1,h,IDX);
}

void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(x,h) shead[x]=thead[x]=-1;
	REP(i,n) {
		scanf("%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2); --r[i].x1,--r[i].y1,--r[i].x2,--r[i].y2;
		snxt[i]=shead[r[i].x1],shead[r[i].x1]=i;
		tnxt[i]=thead[r[i].x2],thead[r[i].x2]=i;
	}

	multiset<int> have; have.insert(w); sval[0]=slazy[0]=0; sset(0,0,w-1,0,0,1);
	REP(x,h) {
		//printf("processing x=%d\n",x);
		// clear all intervals of blocks starting at this x
		for(int z=shead[x];z!=-1;z=snxt[z]) sset(0,0,w-1,r[z].y1,r[z].y2,0),have.insert(r[z].y1);
		// for each y1 of one or more blocks ending at previous x (decreasing), promote y1-1 until next block
		ncur=0; if(x==0) cur[ncur++]=0; else for(int z=thead[x-1];z!=-1;z=tnxt[z]) { if(r[z].y1!=0) cur[ncur++]=r[z].y1-1; multiset<int>::iterator it=have.lower_bound(r[z].y1); have.erase(it); } sort(cur,cur+ncur); ncur=unique(cur,cur+ncur)-cur;
		for(int i=ncur-1;i>=0;--i) {
			int y=cur[i];
			int val=sget(0,0,w-1,y); if(val==0) continue;
			multiset<int>::iterator it=have.lower_bound(y); int ny=*it-1;
			if(y+1<=ny) sinc(0,0,w-1,y+1,ny,val);
		}
	}
	int ret=sget(0,0,w-1,w-1);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}