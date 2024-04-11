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

const int MAXN=5000;
const int MINCOORD=-5000;
const int MAXCOORD=+5000;
const int MAXRANGE=MAXCOORD-MINCOORD+1;
struct Seg { int lx,hx,ly,hy; int x,y; };
struct E { int y,kind,idx; E() {} E(int y,int kind,int idx):y(y),kind(kind),idx(idx) {} };
bool operator<(const E &a,const E &b) { if(a.y!=b.y) return a.y>b.y; return a.kind>b.kind; }

int n;
Seg seg[MAXN];

vector<Seg> hor;
vector<Seg> ver;
vector<E> e;

int bit[MAXRANGE+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=MAXRANGE) { bit[idx]+=by; idx+=idx&-idx; } }

ll solve() {
	REP(i,n) seg[i].ly-=MINCOORD,seg[i].hy-=MINCOORD,seg[i].lx-=MINCOORD,seg[i].hx-=MINCOORD;
	hor.clear(); ver.clear();
	REP(i,n) { bool ishor=seg[i].ly==seg[i].hy,isver=seg[i].lx==seg[i].hx; assert(ishor&&!isver||!ishor&&isver); if(ishor) hor.PB(seg[i]); if(isver) ver.PB(seg[i]); }
	REPSZ(i,hor) { assert(hor[i].ly==hor[i].hy); hor[i].y=hor[i].ly; }
	REPSZ(i,ver) { assert(ver[i].lx==ver[i].hx); ver[i].x=ver[i].lx; }

	ll ret=0;
	REPSZ(i,hor) {
		e.clear();
		REPSZ(j,hor) if(hor[j].y>hor[i].y&&hor[j].lx<hor[i].hx&&hor[j].hx>hor[i].lx) e.PB(E(hor[j].y,0,j));
		REPSZ(j,ver) if(ver[j].ly<=hor[i].y&&ver[j].hy>hor[i].y&&ver[j].x>=hor[i].lx&&ver[j].x<=hor[i].hx) e.PB(E(ver[j].hy,1,j));
		sort(e.begin(),e.end());
		memset(bit,0,sizeof(bit));
		REPSZ(j,e) {
			int idx=e[j].idx;
			if(e[j].kind==0) {
				int cur=bget(hor[idx].hx)-bget(hor[idx].lx-1);
				//printf("%d (%d..%d) with %d (%d..%d): %d\n",hor[i].y+MINCOORD,hor[i].lx+MINCOORD,hor[i].hx+MINCOORD,hor[idx].y+MINCOORD,hor[idx].lx+MINCOORD,hor[idx].hx+MINCOORD,cur);
				ret+=(ll)cur*(cur-1)/2;
			}
			if(e[j].kind==1) {
				bmod(ver[idx].x,+1);
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) { scanf("%d%d%d%d",&seg[i].lx,&seg[i].ly,&seg[i].hx,&seg[i].hy); if(seg[i].lx>seg[i].hx) swap(seg[i].lx,seg[i].hx); if(seg[i].ly>seg[i].hy) swap(seg[i].ly,seg[i].hy); }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}