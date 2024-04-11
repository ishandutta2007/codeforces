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

const int MAXH=3000;
const int MAXW=3000;

int h,w;
char g[MAXH][MAXW+1];

int l[MAXH][MAXW];
int d[MAXH][MAXW];
int r[MAXH][MAXW];

int f[MAXW+1];
void fmod(int idx,int by) { /*printf("\t\tmod(%d,%d)\n",idx,by);*/ ++idx; while(idx<=w) { f[idx]+=by; idx+=idx&-idx; } }
int fget(int idx) { /*int oidx=idx;*/ ++idx; int ret=0; while(idx>0) { ret+=f[idx]; idx-=idx&-idx; } /*printf("\t\tget(%d)=%d\n",oidx,ret);*/ return ret; }

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	REP(x,h) REP(y,w) l[x][y]=g[x][y]!='z'?0:y-1<0?1:1+l[x][y-1];
	REP(x,h) for(int y=w-1;y>=0;--y) r[x][y]=g[x][y]!='z'?0:y+1>=w?1:1+r[x][y+1];
	for(int x=h-1;x>=0;--x) REP(y,w) d[x][y]=g[x][y]!='z'?0:x+1>=h||y-1<0?1:1+d[x+1][y-1];

	ll ret=0;
	REP(xy,h+w-1) {
		priority_queue<pair<int,int> > pq;
		//printf("processing %d\n",xy);
		memset(f,0,sizeof(f));
		for(int x=min(xy,h-1),y=xy-x;x>=0&&y<w;--x,++y) {
			//printf("\t(%d,%d) -> %d/%d/%d\n",x,y,l[x][y],d[x][y],r[x][y]);
			if(r[x][y]>0) fmod(y,+1),pq.push(MP(-y-r[x][y],y));
			while(SZ(pq)>0&&-pq.top().first<=y) fmod(pq.top().second,-1),pq.pop();
			int mx=min(l[x][y],d[x][y]);
			if(mx>0) ret+=fget(y)-fget(y-mx);
		}
		//printf("at %I64d\n",ret);
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}