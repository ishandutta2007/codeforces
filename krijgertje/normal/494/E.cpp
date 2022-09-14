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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int sz,nrect,maxmove;
int sr[50000],sc[50000],tr[50000],tc[50000];

int g[1000][1000];
bool any[1000][1000];
void show() {
	memset(any,false,sizeof(any));
	REP(i,nrect) FORE(r,sr[i],tr[i]) FORE(c,sc[i],tc[i]) any[r][c]=true;
	REP(i,sz) REP(j,sz) {
		ll mask=0;
		FORE(k,1,maxmove) {
			if(i-k+1<0||j-k+1<0) continue;
			int cur=0;
			REP(ii,k) REP(jj,k) if(ii!=k-1||jj!=k-1) cur^=g[i-k+1+ii][j-k+1+jj];
			//if(i==j) printf("%d*%d, %d -> %d\n",i+1,i+1,k,cur);
			mask|=1LL<<cur;
		}
		g[i][j]=0; while(mask&(1LL<<g[i][j])) ++g[i][j];
	}
	int ret=0,cnt=0;
	REP(i,sz) { REP(j,sz) if(any[i+1][j+1]) printf("%d",g[i][j]),ret^=g[i][j],++cnt; else printf("-"); puts(""); }
	printf("%d %d\n",ret,cnt);
}

typedef struct E {
	int x,ly,hy,type; // +1==add, -1==rem
} E;
bool operator<(const E &a,const E &b) {
	if(a.x!=b.x) return a.x<b.x;
	return false;
}
int ne;
E e[100000];

const int MAXS=5000000;
int ns;
int lft[MAXS];
int rgt[MAXS];
int sval[MAXS];
int scnt[MAXS];

int create() {
//	printf("\t\t\t\tcreating %d\n",ns);
	int ret=ns++;
	assert(ret<MAXS);
	lft[ret]=rgt[ret]=-1;
	sval[ret]=scnt[ret]=0;
	return ret;
}

void update(int x,int l,int h) {
	if(sval[x]!=0) {
		scnt[x]=h-l+1;
	} else {
		scnt[x]=(lft[x]!=-1?scnt[lft[x]]:0)+(rgt[x]!=-1?scnt[rgt[x]]:0);
	}
}

int get(int x,int l,int h) {
	if(x==-1) return 0;
	return scnt[x];
}

void change(int &x,int l,int h,int L,int H,int BY) {
	if(x==-1) x=create();
	if(L<=l&&h<=H) {
		sval[x]+=BY;
		update(x,l,h);
	} else {
		int m=l+(h-l)/2;
		if(L<=m) change(lft[x],l,m,L,H,BY);
		if(m+1<=H) change(rgt[x],m+1,h,L,H,BY);
		update(x,l,h);
	}
//	printf("\t\t\tchanged(%d:%d..%d / %d..%d / %d)->%d/%d [%d,%d]\n",x,l,h,L,H,BY,sval[x],scnt[x],lft[x],rgt[x]);
}

// Counts number of points in rectangles for which x=y=0 (mod scale)
ll calc(int scale) {
	ne=0;
	ns=0; int root=-1,miny=0,maxy=sz/scale;
	REP(i,nrect) {
		int sy=(sr[i]+scale-1)/scale,ty=tr[i]/scale;
		int sx=(sc[i]+scale-1)/scale,tx=tc[i]/scale;
		if(sy>ty||sx>tx) continue;
		e[ne].x=sx; e[ne].ly=sy; e[ne].hy=ty; e[ne].type=+1; ++ne;
		e[ne].x=tx+1; e[ne].ly=sy; e[ne].hy=ty; e[ne].type=-1; ++ne;
	}
	sort(e,e+ne);
	ll ret=0;
	REP(ei,ne) {
		if(ei!=0&&e[ei].x!=e[ei-1].x) {
			int dx=e[ei].x-e[ei-1].x,dy=get(root,miny,maxy);
			//printf("\tadding %d*%d\n",dx,dy);
			ret+=(ll)dx*dy;
		}
		//printf("\t\tchanging %d..%d by %d\n",e[ei].ly,e[ei].hy,e[ei].type);
		change(root,miny,maxy,e[ei].ly,e[ei].hy,e[ei].type);
	}
	return ret;
}

ll pcnt[60];

void run() {
	scanf("%d%d%d",&sz,&nrect,&maxmove);
	REP(i,nrect) { scanf("%d%d%d%d",&sr[i],&sc[i],&tr[i],&tc[i]); }

	//show();

	memset(pcnt,0,sizeof(pcnt));
	for(int i=0;(1<<i)<=maxmove;++i) {
		pcnt[i]=calc(1<<i);
		if(i!=0) pcnt[i-1]-=pcnt[i];
	}
	//REP(i,60) if((1LL<<i)<=maxmove) printf("%d: %lld\n",1<<i,pcnt[i]);

	bool win=false;
	REP(i,60) if(pcnt[i]%2!=0) win=true;
	printf("%s\n",win?"Hamed":"Malek");
}

int main() {
	run();
	return 0;
}