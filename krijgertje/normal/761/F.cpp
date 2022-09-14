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
const int MAXZ=26;
const int MAXN=300000;
typedef struct R { int x1,y1,x2,y2; char c; } R;

int h,w,n;
char g[MAXH][MAXW+1];
R r[MAXN];
vector<pair<int,int> > e[MAXZ][MAXH+1];

int d[MAXW+1];
int cnt[MAXZ][MAXH][MAXW];
int scnt[MAXH][MAXW];
ll sum[MAXH+1][MAXW+1];
ll gsum[MAXH+1][MAXW+1];
ll gfsum[MAXH+1][MAXW+1];
ll ssum[MAXH+1][MAXW+1];
ll res[MAXN]; 


void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(x,h) scanf("%s",g[x]);
	REP(i,n) scanf("%d%d%d%d %c",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2,&r[i].c),--r[i].x1,--r[i].y1,--r[i].x2,--r[i].y2;

	REP(i,n) {
		int z=r[i].c-'a',x1=r[i].x1,y1=r[i].y1,x2=r[i].x2,y2=r[i].y2; //printf("x=%d..%d y=%d..%d c=%c\n",x1,x2,y1,y2,'a'+z);
		e[z][x1].PB(MP(y1,+1)); e[z][x1].PB(MP(y2+1,-1)); e[z][x2+1].PB(MP(y1,-1)); e[z][x2+1].PB(MP(y2+1,+1));
	}
	memset(cnt,0,sizeof(cnt));
	REP(z,26) {
		memset(d,0,sizeof(d));
		REPE(x,h) {
			REPSZ(i,e[z][x]) d[e[z][x][i].first]+=e[z][x][i].second;
			int cur=d[0]; REP(y,w) { if(x==h) assert(cur==0); else cnt[z][x][y]=cur; cur+=d[y+1]; } assert(cur==0);
		}
	}
	//REP(z,26) { printf("%c:\n",'a'+z); REP(x,h) { REP(y,w) printf("%3d",cnt[z][x][y]); puts(""); } puts(""); }
	memset(scnt,0,sizeof(scnt)); REP(z,26) REP(x,h) REP(y,w) scnt[x][y]+=cnt[z][x][y];
	//REP(x,h) { REP(y,w) printf("%3d",scnt[x][y]); puts(""); }

	REP(i,n) res[i]=0;
	REP(z,26) {
		REP(x,h) REP(y,w) sum[x+1][y+1]=sum[x][y+1]+sum[x+1][y]-sum[x][y]+cnt[z][x][y];
		//printf("%c:\n",'a'+z); REPE(x,h) { REPE(y,w) printf("%3d",sum[x][y]); puts(""); } puts("");
		REP(x,h) REP(y,w) gsum[x+1][y+1]=gsum[x][y+1]+gsum[x+1][y]-gsum[x][y]+abs(g[x][y]-'a'-z);
		//printf("%c:\n",'a'+z); REPE(x,h) { REPE(y,w) printf("%3d",gsum[x][y]); puts(""); } puts("");
		REP(x,h) REP(y,w) gfsum[x+1][y+1]=gfsum[x][y+1]+gfsum[x+1][y]-gfsum[x][y]+cnt[z][x][y]*abs(g[x][y]-'a'-z);
		//printf("%c:\n",'a'+z); REPE(x,h) { REPE(y,w) printf("%3d",gfsum[x][y]); puts(""); } puts("");
		REP(x,h) REP(y,w) ssum[x+1][y+1]=ssum[x][y+1]+ssum[x+1][y]-ssum[x][y]+scnt[x][y]*abs(g[x][y]-'a'-z);
		//printf("%c:\n",'a'+z); REPE(x,h) { REPE(y,w) printf("%3d",ssum[x][y]); puts(""); } puts("");

		REP(i,n) {
			int zz=r[i].c-'a',x1=r[i].x1,y1=r[i].y1,x2=r[i].x2,y2=r[i].y2;
			// sum(x=0..h-1,y=0..w-1,cnt[x][y]*(x1<=x<=x2&&y1<=y<=y2?abs(zz-z):abs(g[x][y]-'a'-z))+(n-scnt[x][y])*(x1<=x<=x2&&y1<=y<=y2?abs(g[x][y]-'a'-zz):0))
			// sum(x=0..h-1,y=0..w-1,cnt[x][y]*abs(g[x][y]-'a'-z))+sum(x=x1..x2,y=y1..y2,cnt[x][y]*(abs(zz-z)-abs(g[x][y]-'a'-z))+n*abs(g[x][y]-'a'-zz)-scnt[x][y]*abs(g[x][y]-'a'-zz))
			ll a=gfsum[h][w];
			ll b=gfsum[x2+1][y2+1]-gfsum[x2+1][y1]-gfsum[x1][y2+1]+gfsum[x1][y1];
			ll c=sum[x2+1][y2+1]-sum[x2+1][y1]-sum[x1][y2+1]+sum[x1][y1];
			res[i]+=a-b+abs(zz-z)*c;
			//printf("\t%d %c: %lld - %lld + %d*%lld = %lld\n",i,'a'+z,a,b,abs(zz-z),c,a-b+abs(zz-z)*c);
			//printf("\t%d -: %d*%lld - %lld = %lld\n",i,n,d,e,n*d-e);
		}
		REP(i,n) if(r[i].c-'a'==z) {
			int zz=r[i].c-'a',x1=r[i].x1,y1=r[i].y1,x2=r[i].x2,y2=r[i].y2;
			ll d=gsum[x2+1][y2+1]-gsum[x2+1][y1]-gsum[x1][y2+1]+gsum[x1][y1];
			ll e=ssum[x2+1][y2+1]-ssum[x2+1][y1]-ssum[x1][y2+1]+ssum[x1][y1];
			res[i]+=n*d-e;
			//printf("\t%d -: %d*%lld - %lld = %lld\n",i,n,d,e,n*d-e);
		}
	}
	//REP(i,n) printf("%d: %lld\n",i,res[i]);
	ll ret=res[0]; FOR(i,1,n) if(res[i]<ret) ret=res[i]; printf("%lld\n",ret);

}

int main() {
	run();
	return 0;
}