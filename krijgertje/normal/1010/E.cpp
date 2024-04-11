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

const int MAXA=100000;
const int MAXB=100000;
const int MAXQ=100000;
const int MAXE=MAXB+MAXQ;
const int ANSOPEN=0;
const int ANSCLOSED=1;
const int ANSUNKNOWN=2;
const int MAXVAL=100000;
struct P { int x,y,z; };
struct E { int x,y,z,id; E() {} E(const P &p,int id):x(p.x),y(p.y),z(p.z),id(id) {} };
bool operator<(const E &a,const E &b) { if(a.z!=b.z) return a.z<b.z; return a.id<b.id; }

int xmax,ymax,zmax,na,nb,nq;
P a[MAXA];
P b[MAXB];
P q[MAXQ];
int ans[MAXQ];

int lx,ly,lz,hx,hy,hz;

E e[MAXE]; int ne;
int bit[MAXVAL+1];
void bmod(int idx,int val) { while(idx>0) { bit[idx]=min(bit[idx],val); idx-=idx&-idx; } }
int bget(int idx) { int ret=INT_MAX; while(idx<=xmax) { ret=min(ret,bit[idx]); idx+=idx&-idx; } return ret; }

void solvequadrant(bool doxoverlap,bool doyoverlap,bool dozoverlap) {
	ne=0;
	REP(i,nb) {
		if(b[i].z<lz||b[i].y<ly||b[i].x<lx) continue;
		e[ne]=E(b[i],-1);
		if(e[ne].z<=hz) e[ne].z=lz;
		if(e[ne].y<=hy) e[ne].y=ly;
		if(e[ne].x<=hx) e[ne].x=lx;
		++ne;
	}
	REP(i,nq) {
		if(q[i].x<lx||!doxoverlap&&q[i].x<=hx) continue;
		if(q[i].y<ly||!doyoverlap&&q[i].y<=hy) continue;
		if(q[i].z<lz||!dozoverlap&&q[i].z<=hz) continue;
		e[ne++]=E(q[i],i);
	}
	sort(e,e+ne);

	REPE(i,xmax) bit[i]=INT_MAX;
	REP(i,ne) {
		int x=e[i].x,y=e[i].y,z=e[i].z,id=e[i].id;
		if(id==-1) {
			bmod(xmax-x,y);
		} else {
			assert(ans[id]==-1);
			if(lx<=x&&x<=hx&&ly<=y&&y<=hy&&lz<=z&&z<=hz) { ans[id]=ANSOPEN; continue; }
			int cur=bget(xmax-x);
			ans[id]=y>=cur?ANSCLOSED:ANSUNKNOWN;
		}
	}

}

void run() {
	scanf("%d%d%d%d%d%d",&xmax,&ymax,&zmax,&na,&nb,&nq);
	REP(i,na) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),--a[i].x,--a[i].y,--a[i].z;
	REP(i,nb) scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z),--b[i].x,--b[i].y,--b[i].z;
	REP(i,nq) scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].z),--q[i].x,--q[i].y,--q[i].z;

	lx=INT_MAX,ly=INT_MAX,lz=INT_MAX,hx=INT_MIN,hy=INT_MIN,hz=INT_MIN;
	REP(i,na) {
		lx=min(lx,a[i].x); hx=max(hx,a[i].x);
		ly=min(ly,a[i].y); hy=max(hy,a[i].y);
		lz=min(lz,a[i].z); hz=max(hz,a[i].z);
	}
	//printf("[%d..%d][%d..%d][%d..%d]\n",lx,hx,ly,hy,lz,hz);
	REP(i,nb) {
		if(b[i].x<lx||b[i].x>hx) continue;
		if(b[i].y<ly||b[i].y>hy) continue;
		if(b[i].z<lz||b[i].z>hz) continue;
		printf("INCORRECT\n"); return;
	}
	printf("CORRECT\n");

	memset(ans,-1,sizeof(ans));
	REP(zrep,2) {
		REP(yrep,2) {
			REP(xrep,2) {
				solvequadrant(xrep==0,yrep==0,zrep==0);

				lx=xmax-lx-1,hx=xmax-hx-1,swap(lx,hx);
				REP(i,na) a[i].x=xmax-a[i].x-1;
				REP(i,nb) b[i].x=xmax-b[i].x-1;
				REP(i,nq) q[i].x=xmax-q[i].x-1;
			}
			ly=ymax-ly-1,hy=ymax-hy-1,swap(ly,hy);
			REP(i,na) a[i].y=ymax-a[i].y-1;
			REP(i,nb) b[i].y=ymax-b[i].y-1;
			REP(i,nq) q[i].y=ymax-q[i].y-1;
		}
		lz=zmax-lz-1,hz=zmax-hz-1,swap(lz,hz);
		REP(i,na) a[i].z=zmax-a[i].z-1;
		REP(i,nb) b[i].z=zmax-b[i].z-1;
		REP(i,nq) q[i].z=zmax-q[i].z-1;
	}
	REP(i,nq) assert(ans[i]!=-1);
	REP(i,nq) printf("%s\n",ans[i]==ANSOPEN?"OPEN":ans[i]==ANSCLOSED?"CLOSED":"UNKNOWN");


}

int main() {
	run();
	return 0;
}