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

const int MAXH=2000;
const int MAXW=2000;
const int MAXN=2000;
const int MAXLEN=2000;
const int MAXSLEN=MAXN*MAXLEN;


int h,w,n;
int len[MAXN],slen[MAXN+1];
int x[MAXSLEN],y[MAXSLEN],z[MAXSLEN]; ll sz[MAXSLEN+1];
bool on[MAXN];

int gidx[MAXH][MAXW],gpos[MAXH][MAXW];

int nq; char command[10];


bool inside(int x,int y,int lx,int ly,int hx,int hy) { return lx<=x&&x<hx&&ly<=y&&y<hy; }

ll calcdelta(int x1,int y1,int x2,int y2) {
	//printf("\t(%d,%d)->(%d,%d)\n",x1,y1,x2,y2);
	int idx=gidx[x1][y1];
	if(idx==-1||!on[idx]||gidx[x2][y2]!=idx) return 0;
	int pos1=gpos[x1][y1],pos2=gpos[x2][y2];
	if(abs(pos1-pos2)!=1) return 0;
	ll ret=pos1<pos2?-(sz[slen[idx+1]]-sz[slen[idx]+pos2]):+(sz[slen[idx+1]]-sz[slen[idx]+pos1]);
	//printf("\t(%d,%d)->(%d,%d) = %lld [%d %d->%d]\n",x1,y1,x2,y2,ret,idx,pos1,pos2);
	return ret;
}
ll calc(int lx,int ly,int hx,int hy) {
	ll ret=0;
	REP(i,n) if(on[i]&&inside(x[slen[i]],y[slen[i]],lx,ly,hx,hy)) ret+=sz[slen[i+1]]-sz[slen[i]];
	if(lx-1>=0) FOR(y,ly,hy) ret+=calcdelta(lx,y,lx-1,y);
	if(hx+1<=h) FOR(y,ly,hy) ret+=calcdelta(hx-1,y,hx,y);
	if(ly-1>=0) FOR(x,lx,hx) ret+=calcdelta(x,ly,x,ly-1);
	if(hy+1<=w) FOR(x,lx,hx) ret+=calcdelta(x,hy-1,x,hy);
	return ret;
}

void run() {
	scanf("%d%d%d",&h,&w,&n);
	slen[0]=0;
	REP(i,n) { scanf("%d",&len[i]); slen[i+1]=slen[i]+len[i]; REP(j,len[i]) { int idx=slen[i]+j; scanf("%d%d%d",&x[idx],&y[idx],&z[idx]),--x[idx],--y[idx]; } }
	REP(i,n) on[i]=true;
	sz[0]=0; REP(i,slen[n]) sz[i+1]=sz[i]+z[i];
	memset(gidx,-1,sizeof(gidx)); memset(gpos,-1,sizeof(gpos)); REP(i,n) REP(j,len[i]) { int idx=slen[i]+j; gidx[x[idx]][y[idx]]=i; gpos[x[idx]][y[idx]]=j; }

	scanf("%d",&nq);
	REP(qi,nq) {
		scanf("%s",command);
		if(strcmp(command,"SWITCH")==0) {
			int idx; scanf("%d",&idx); --idx;
			on[idx]=!on[idx];
		}
		if(strcmp(command,"ASK")==0) {
			int lx,ly,hx,hy; scanf("%d%d%d%d",&lx,&ly,&hx,&hy); --lx,--ly;
			ll ret=calc(lx,ly,hx,hy);
			printf("%lld\n",ret);
		}
	}
}

int main() {
	run();
	return 0;
}