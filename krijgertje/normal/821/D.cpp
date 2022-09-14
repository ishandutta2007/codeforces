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

const int MAXH=10000;
const int MAXW=10000;
const int MAXN=10000;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w,n;
int px[MAXN],py[MAXN];

int d[MAXN];
int dx[MAXH],dy[MAXW];
bool done[MAXN];
vector<int> onx[MAXH],ony[MAXW];

int qa[MAXN],qahead,qatail;
int qb[MAXN],qbhead,qbtail;
map<pair<int,int>,int> id;

void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(i,n) scanf("%d%d",&px[i],&py[i]),--px[i],--py[i];
	REP(x,h) onx[x].clear(); REP(y,w) ony[y].clear(); REP(i,n) onx[px[i]].PB(i),ony[py[i]].PB(i);
	id.clear(); REP(i,n) id[MP(px[i],py[i])]=i; bool dstlit=id.count(MP(h-1,w-1));
	REP(i,n) done[i]=false,d[i]=INT_MAX; REP(x,h) dx[x]=INT_MAX; REP(y,w) dy[y]=INT_MAX; qahead=qatail=qbhead=qbtail=0;
	REP(i,n) if(px[i]==0&&py[i]==0) d[i]=0,qa[qahead++]=i;
	int ret=INT_MAX;
	while(qatail<qahead) {
		while(qatail<qahead) {
			int at=qa[qatail++];
			if(done[at]) continue; else done[at]=true;
			int x=px[at],y=py[at];
			if(x==h-1&&y==w-1) ret=min(ret,d[at]);
			if(x==h-1||y==w-1) ret=min(ret,d[at]+1);
			if(d[at]<dx[x]) {
				dx[x]=d[at];
				FORE(xx,-2,+2) {
					int cx=x+xx; if(cx<0||cx>=h) continue;
					if(cx==h-1&&(abs(xx)<=1|dstlit)) ret=min(ret,d[at]+1);
					REPSZ(i,onx[cx]) { int to=onx[cx][i]; if(d[at]+1<d[to]) d[to]=d[at]+1,qb[qbhead++]=to; }
				}
			}
			if(d[at]<dy[y]) {
				dy[y]=d[at];
				FORE(yy,-2,+2) {
					int cy=y+yy; if(cy<0||cy>=w) continue;
					if(cy==w-1&&(abs(yy)<=1||dstlit)) ret=min(ret,d[at]+1);
					REPSZ(i,ony[cy]) { int to=ony[cy][i]; if(d[at]+1<d[to]) d[to]=d[at]+1,qb[qbhead++]=to; }
				}
			}
			REP(k,4) {
				int nx=x+DX[k],ny=y+DY[k];
				if(!id.count(MP(nx,ny))) continue;
				int to=id[MP(nx,ny)];
				if(d[at]<d[to]) d[to]=d[at],qa[qahead++]=to;
			}
		}
		qahead=qatail=0; while(qbtail<qbhead) qa[qahead++]=qb[qbtail++]; qbhead=qbtail=0;
	}
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}