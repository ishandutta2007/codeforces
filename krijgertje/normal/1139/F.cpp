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

const int MAXDISH=100000;
const int MAXPERSON=100000;
const int MAXP=MAXDISH+MAXPERSON;
const int MAXS=4*MAXP;
struct Dish { int price,standard,beauty,id; };
bool operator<(const Dish &a,const Dish &b) { return a.standard>b.standard; }
struct Person { int income,preference,id; };
bool operator<(const Person &a,const Person &b) { return a.income>b.income; }
struct P { int x,y; P () {} P(int x,int y):x(x),y(y) {} };
bool operator<(const P &a,const P &b) { return a.y<b.y; }

int ndish,nperson;
Dish dish[MAXDISH];
Person person[MAXPERSON];
int ans[MAXPERSON];

P pdish[MAXDISH];
P pperson[MAXPERSON];
int allx[MAXP],nallx;
int ally[MAXP],nally;

vector<P> have;
vector<int> sy[MAXS];
vector<int> sbit[MAXS];

void bmod(int z,int idx,int by) { ++idx; while(idx<=SZ(sy[z])) { sbit[z][idx]+=by; idx+=idx&-idx; } }
int bget(int z,int idx) { ++idx; int ret=0; while(idx>0) { ret+=sbit[z][idx]; idx-=idx&-idx; } return ret; }

void sinit(int z,int lx,int hx,vector<P> p) {
	sy[z].clear(); REPSZ(i,p) sy[z].PB(p[i].y); sy[z].erase(unique(sy[z].begin(),sy[z].end()),sy[z].end());
	sbit[z]=vector<int>(SZ(sy[z])+1,0);
	if(lx!=hx) {
		int mx=lx+(hx-lx)/2;
		vector<P> lp,rp; REPSZ(i,p) if(p[i].x<=mx) lp.PB(p[i]); else rp.PB(p[i]);
		sinit(2*z+1,lx,mx,lp);
		sinit(2*z+2,mx+1,hx,rp);
	}
}
void sadd(int z,int lx,int hx,int X,int Y) {
	int idx=lower_bound(sy[z].begin(),sy[z].end(),Y)-sy[z].begin(); assert(idx<SZ(sy[z])&&sy[z][idx]==Y);
	//printf("sadd(%d,%d..%d,%d,%d) [%d]\n",z,lx,hx,X,Y,idx);
	bmod(z,idx,+1);
	if(lx!=hx) {
		int mx=lx+(hx-lx)/2;
		if(X<=mx) sadd(2*z+1,lx,mx,X,Y); else sadd(2*z+2,mx+1,hx,X,Y);
	}
}
int sget(int z,int lx,int hx,int LX,int HX,int LY,int HY) {
	if(LX<=lx&&hx<=HX) {
		//printf("sget(%d,%d..%d,%d..%d,%d..%d)\n",z,lx,hx,LX,HX,LY,HY);
		int lidx=lower_bound(sy[z].begin(),sy[z].end(),LY)-sy[z].begin()-1;
		int ridx=lower_bound(sy[z].begin(),sy[z].end(),HY)-sy[z].begin(); if(ridx==SZ(sy[z])||sy[z][ridx]>HY) --ridx;
		int lval=bget(z,lidx),rval=bget(z,ridx);
		//printf("\t"); REPSZ(i,sy[z]) printf("%d ",sy[z][i]); printf("(%d..%d] -> %d-%d\n",lidx,ridx,rval,lval);
		return rval-lval;
	} else {
		int mx=lx+(hx-lx)/2,ret=0;
		if(LX<=mx) ret+=sget(2*z+1,lx,mx,LX,HX,LY,HY);
		if(mx+1<=HX) ret+=sget(2*z+2,mx+1,hx,LX,HX,LY,HY);
		return ret;
	}
}

void adddish(int idx) {
	//printf("adding (%d,%d)\n",pdish[idx].x,pdish[idx].y);
	sadd(0,0,nallx-1,pdish[idx].x,pdish[idx].y);
	//have.PB(pdish[idx]);
}
int queryperson(int idx) {
	//printf("querying (%d,%d)\n",pperson[idx].x,pperson[idx].y);
	return sget(0,0,nallx-1,0,pperson[idx].x,pperson[idx].y,nally-1);
	//int ret=0; REPSZ(i,have) if(have[i].x<=pperson[idx].x&&have[i].y>=pperson[idx].y) ++ret; return ret;
}

P transform(const P &a) { return P(a.x+a.y,a.y-a.x); }
void solve() {
	sort(dish,dish+ndish);
	sort(person,person+nperson);
	REP(i,ndish) pdish[i]=transform(P(dish[i].price,dish[i].beauty));
	REP(i,nperson) pperson[i]=transform(P(person[i].income,person[i].preference));
	nallx=0; REP(i,ndish) allx[nallx++]=pdish[i].x; REP(i,nperson) allx[nallx++]=pperson[i].x; sort(allx,allx+nallx); nallx=unique(allx,allx+nallx)-allx; REP(i,ndish) pdish[i].x=lower_bound(allx,allx+nallx,pdish[i].x)-allx; REP(i,nperson) pperson[i].x=lower_bound(allx,allx+nallx,pperson[i].x)-allx;
	nally=0; REP(i,ndish) ally[nally++]=pdish[i].y; REP(i,nperson) ally[nally++]=pperson[i].y; sort(ally,ally+nally); nally=unique(ally,ally+nally)-ally; REP(i,ndish) pdish[i].y=lower_bound(ally,ally+nally,pdish[i].y)-ally; REP(i,nperson) pperson[i].y=lower_bound(ally,ally+nally,pperson[i].y)-ally;

	//have.clear();
	vector<P> allp; REP(i,ndish) allp.PB(pdish[i]); REP(i,nperson) allp.PB(pperson[i]); sort(allp.begin(),allp.end()); sinit(0,0,nallx-1,allp);
	int atdish=0;
	REP(i,nperson) {
		while(atdish<ndish&&dish[atdish].standard>=person[i].income) adddish(atdish++);
		ans[person[i].id]=queryperson(i);
	}
}


void run() {
	scanf("%d%d",&ndish,&nperson);
	REP(i,ndish) dish[i].id=i;
	REP(i,ndish) scanf("%d",&dish[i].price);
	REP(i,ndish) scanf("%d",&dish[i].standard);
	REP(i,ndish) scanf("%d",&dish[i].beauty);
	REP(i,nperson) person[i].id=i;
	REP(i,nperson) scanf("%d",&person[i].income);
	REP(i,nperson) scanf("%d",&person[i].preference);
	solve();
	REP(i,nperson) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}