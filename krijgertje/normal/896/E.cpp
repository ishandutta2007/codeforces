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

//const int MAXN=50;
//const int BSZ=3;

const int MAXN=100000;
const int BSZ=400;
const int MAXB=(MAXN+BSZ-1)/BSZ;
const int MAXVAL=100000;
const int MAXQ=100000;

int n,nq;
int a[MAXN];
int qkind[MAXQ],ql[MAXQ],qr[MAXQ],qx[MAXQ];
int ans[MAXQ],nans;

int nb;
int bl[MAXB],br[MAXB];
int bmark[MAXB][MAXVAL+1],curbmark[MAXB];
int bpar[MAXB][MAXVAL+1]; // <0 -> root+size of group-1, >=0 -> parent
int boff[MAXB],bmx[MAXB],obmx[MAXB];

int find(int b,int x) { if(bmark[b][x]!=curbmark[b]) bmark[b][x]=curbmark[b],bpar[b][x]=-1; if(bpar[b][x]<0) return x; return bpar[b][x]=find(b,bpar[b][x]); }
void setpar(int b,int x,int y) {
	//printf("setpar(%d,%d,%d)\n",b,x,y);
	if(bmark[b][x]!=curbmark[b]) bmark[b][x]=curbmark[b],bpar[b][x]=-1;
	if(bmark[b][y]!=curbmark[b]) bmark[b][y]=curbmark[b],bpar[b][y]=-1;
	assert(bpar[b][x]<0&&bpar[b][y]<0);
	bpar[b][y]+=bpar[b][x]+1; bpar[b][x]=y;
}

void restore(int b) {
	FORE(i,bl[b],br[b]) a[i]=find(b,a[i])-boff[b];
}
void rebuild(int b) {
	++curbmark[b];
	boff[b]=0; bmx[b]=a[bl[b]];
	FORE(i,bl[b],br[b]) if(a[i]>bmx[b]) bmx[b]=a[i]; obmx[b]=bmx[b];
	FORE(i,bl[b],br[b]) { if(bmark[b][a[i]]!=curbmark[b]) bmark[b][a[i]]=curbmark[b],bpar[b][a[i]]=-1; --bpar[b][a[i]]; }
}
void bmod(int b,int x) {
	if(x>=bmx[b]) return;
	//printf("bmod(%d,%d)\n",b,x);
	//printf("bpar[%d]:",b); FORE(i,0,obmx[b]) printf(" %d",bpar[b][i]); puts("");
	int below=x,above=bmx[b]-x;
	if(below<=above) {
		FORE(i,1,x) {
			setpar(b,boff[b]+i,boff[b]+i+x);
		}
		boff[b]+=x;
		bmx[b]-=x;
	} else {
		FORE(i,x+1,bmx[b]) {
			setpar(b,boff[b]+i,boff[b]+i-x);
		}
		bmx[b]=x;
	}
	//printf("bpar[%d]:",b); FORE(i,0,obmx[b]) printf(" %d",bpar[b][i]); puts("");
}
int bget(int b,int x) {
	if(x>bmx[b]) return 0;
	if(bmark[b][boff[b]+x]!=curbmark[b]) bmark[b][boff[b]+x]=curbmark[b],bpar[b][boff[b]+x]=-1;
	assert(bpar[b][boff[b]+x]<0);
	return -(bpar[b][boff[b]+x]+1);
}

void solve() {
	nb=(n+BSZ-1)/BSZ;
	REP(i,nb) bl[i]=i*BSZ,br[i]=min(i*BSZ+BSZ,n)-1,curbmark[i]=0,memset(bpar[i],-1,sizeof(bpar[i]));
	REP(i,nb) rebuild(i);

	nans=0;
	REP(i,nq) {
		int kind=qkind[i],l=ql[i],r=qr[i],x=qx[i];
		if(kind==1) {
			if(l<=r&&l%BSZ!=0) {
				int bl=l/BSZ;
				restore(bl);
				while(l<=r&&l%BSZ!=0) { if(a[l]>x) a[l]-=x; ++l; }
				rebuild(bl);
			}
			if(l<=r&&r%BSZ!=BSZ-1) {
				int br=r/BSZ;
				restore(br);
				while(l<=r&&r%BSZ!=BSZ-1) { if(a[r]>x) a[r]-=x; --r; }
				rebuild(br);
			}
			while(l<=r) {
				int b=l/BSZ;
				bmod(b,x);
				l+=BSZ;
			}
			assert(l==r+1);
		}
		if(kind==2) {
			int ret=0;
			if(l<=r&&l%BSZ!=0) {
				int bl=l/BSZ;
				restore(bl);
				while(l<=r&&l%BSZ!=0) { if(a[l]==x) ++ret; ++l; }
				rebuild(bl);
			}
			if(l<=r&&r%BSZ!=BSZ-1) {
				int br=r/BSZ;
				restore(br);
				while(l<=r&&r%BSZ!=BSZ-1) { if(a[r]==x) ++ret; --r; }
				rebuild(br);
			}
			while(l<=r) {
				int b=l/BSZ;
				ret+=bget(b,x);
				l+=BSZ;
			}
			assert(l==r+1);
			ans[nans++]=ret;
		}
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) scanf("%d%d%d%d",&qkind[i],&ql[i],&qr[i],&qx[i]),--ql[i],--qr[i];
	solve();
	REP(i,nans) printf("%d\n",ans[i]);
}

void stress() {
	while(true) {
		n=MAXN,nq=MAXQ;
		REP(i,n) a[i]=(rand()%1000*1000+rand()%1000)%MAXVAL+1;
		REP(i,nq) {
			qkind[i]=1; //rand()%2+1;
			ql[i]=(rand()%1000*1000+rand()%1000)%n,qr[i]=(rand()%1000*1000+rand()%1000)%n; if(ql[i]>qr[i]) swap(ql[i],qr[i]);
			qx[i]=1; //(rand()%1000*1000+rand()%1000)%MAXVAL+1;
		}
		solve(); printf("."); break;
	}
}

int main() {
	//stress();
	run();
	return 0;
}