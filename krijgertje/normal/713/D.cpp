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

const int MAXH=1000;
const int MAXW=1000;
const int MAXLOGH=9;
const int MAXLOGW=9;
const int MAXDIM=1000;

int h,w,nq;
int a[MAXH][MAXW];
int b[MAXH][MAXW];
int c[MAXH][MAXLOGH+1][MAXW][MAXLOGW+1];
int lg[MAXDIM+1]; // (1<<lg[i])<=i

int calc(int lx,int ly,int hx,int hy) {
	int xx=lg[hx-lx+1],yy=lg[hy-ly+1];
	//printf("\t%d %d %d %d / %d %d -> %d %d %d %d\n",lx,ly,hx,hy,xx,yy,c[lx][xx][ly][yy],c[lx][xx][hy-(1<<yy)+1][yy],c[hx-(1<<xx)+1][xx][ly][yy],c[hx-(1<<xx)+1][xx][hy-(1<<yy)+1][yy]);
	int ret=max(max(c[lx][xx][ly][yy],c[lx][xx][hy-(1<<yy)+1][yy]),max(c[hx-(1<<xx)+1][xx][ly][yy],c[hx-(1<<xx)+1][xx][hy-(1<<yy)+1][yy]));
	return ret;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf("%d",&a[x][y]);
	memset(b,0,sizeof(b)); REP(x,h) REP(y,w) if(a[x][y]) b[x][y]=x==0||y==0?1:1+min(b[x-1][y-1],min(b[x-1][y],b[x][y-1]));
	REP(x,h) REP(y,w) c[x][0][y][0]=b[x][y];
	REP(x,h) for(int yy=1;(1<<yy)<=w;++yy) REPE(y,w-(1<<yy)) c[x][0][y][yy]=max(c[x][0][y][yy-1],c[x][0][y+(1<<(yy-1))][yy-1]);
	for(int xx=1;(1<<xx)<=h;++xx) REPE(x,h-(1<<xx)) for(int yy=0;(1<<yy)<=w;++yy) REPE(y,w-(1<<yy)) c[x][xx][y][yy]=max(c[x][xx-1][y][yy],c[x+(1<<(xx-1))][xx-1][y][yy]);
	lg[0]=0; FORE(i,1,MAXDIM) { lg[i]=lg[i-1]; while((1<<(lg[i]+1))<=i) ++lg[i]; }
	//REP(x,h) { REP(y,w) printf("%d",b[x][y]); puts(""); } puts("");

	scanf("%d",&nq);
	REP(qi,nq) {
		int lx,ly,hx,hy; scanf("%d%d%d%d",&lx,&ly,&hx,&hy); --lx,--ly,--hx,--hy;
		int l=0,h=min(hx-lx+1,hy-ly+1)+1;
		while(l+1<h) {
			int m=l+(h-l)/2;
			if(calc(lx+m-1,ly+m-1,hx,hy)>=m) l=m; else h=m;
		}
		printf("%d\n",l);
	}
}

int main() {
	run();
	return 0;
}