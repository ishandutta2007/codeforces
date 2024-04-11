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
const int MAXBIT=1<<18;
typedef struct S { int pos,l,h; } S;
bool operator<(const S &a,const S &b) { if(a.pos!=b.pos) return a.pos<b.pos; return a.l<b.l; }
typedef struct E { int type,x,ly,hy; } E;
bool operator<(const E &a,const E &b) { if(a.x!=b.x) return a.x<b.x; return a.type>b.type; }

int n;
S hor[MAXN]; int nhor;
S ver[MAXN]; int nver;
E e[2*MAXN]; int ne;

int yy[2*MAXN],ny;
int bit[MAXBIT];
void bitmod(int x,int by) { ++x; while(x<MAXBIT) { bit[x]+=by; x+=x&-x; } }
int bitget(int x) { ++x; int ret=0; while(x>0) { ret+=bit[x]; x-=x&-x; } return ret; }

void run() {
	scanf("%d",&n);
	nhor=nver=0;
	REP(i,n) {
		int lx,ly,hx,hy; scanf("%d%d%d%d",&lx,&ly,&hx,&hy); if(lx>hx) swap(lx,hx); if(ly>hy) swap(ly,hy);
		if(lx==hx) hor[nhor].pos=lx,hor[nhor].l=ly,hor[nhor].h=hy,++nhor;
		else if(ly==hy) ver[nver].pos=ly,ver[nver].l=lx,ver[nver].h=hx,++nver;
	}
	sort(hor,hor+nhor); { int tmp=0; REP(i,nhor) if(tmp==0||hor[tmp-1].pos!=hor[i].pos||hor[tmp-1].h<hor[i].l) hor[tmp++]=hor[i]; else hor[tmp-1].h=max(hor[tmp-1].h,hor[i].h); nhor=tmp; }
	sort(ver,ver+nver); { int tmp=0; REP(i,nver) if(tmp==0||ver[tmp-1].pos!=ver[i].pos||ver[tmp-1].h<ver[i].l) ver[tmp++]=ver[i]; else ver[tmp-1].h=max(ver[tmp-1].h,ver[i].h); nver=tmp; }
	//printf("%d hor, %d ver\n",nhor,nver);

	ll ret=0; REP(i,nhor) ret+=hor[i].h-hor[i].l+1; REP(i,nver) ret+=ver[i].h-ver[i].l+1;
	//printf("sum=%lld\n",ret);

	ne=0;
	REP(i,nhor) e[ne].type=0,e[ne].x=hor[i].pos,e[ne].ly=hor[i].l,e[ne].hy=hor[i].h,++ne;
	REP(i,nver) e[ne].type=+1,e[ne].x=ver[i].l,e[ne].ly=e[ne].hy=ver[i].pos,++ne;
	REP(i,nver) e[ne].type=-1,e[ne].x=ver[i].h,e[ne].ly=e[ne].hy=ver[i].pos,++ne;
	sort(e,e+ne);
	//printf("ne=%d\n",ne); REP(i,ne) printf("%d: %d %d..%d\n",e[i].x,e[i].type,e[i].ly,e[i].hy);
	ny=0;
	REP(i,nhor) yy[ny++]=hor[i].l,yy[ny++]=hor[i].h;
	REP(i,nver) yy[ny++]=ver[i].pos;
	sort(yy,yy+ny); ny=unique(yy,yy+ny)-yy;
	//printf("ny=%d\n",ny); REP(i,ny) printf("%d\n",yy[i]);
	REP(i,ne) e[i].ly=lower_bound(yy,yy+ny,e[i].ly)-yy,e[i].hy=lower_bound(yy,yy+ny,e[i].hy)-yy;
	//printf("ne=%d\n",ne); REP(i,ne) printf("%d: %d %d..%d\n",e[i].x,e[i].type,e[i].ly,e[i].hy);

	memset(bit,0,sizeof(bit));
	REP(i,ne) {
		//printf("%d: %d %d..%d\n",e[i].x,e[i].type,e[i].ly,e[i].hy);
		if(e[i].type!=0) bitmod(e[i].ly,e[i].type);
		else ret-=bitget(e[i].hy)-bitget(e[i].ly-1);
	}
	printf("%I64d\n",ret);

}

int main() {
	run();
	return 0;
}