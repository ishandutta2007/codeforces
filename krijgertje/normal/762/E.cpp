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
const int MAXF=10000;
typedef struct R { int x,r,f,xid; } R;
bool fcmp(const R &a,const R &b) { if(a.f!=b.f) return a.f<b.f; return a.x<b.x; }
bool scmp(const R &a,const R &b) { if(a.x+a.r!=b.x+b.r) return a.x+a.r>b.x+b.r; return a.x<b.x; }

int n,mxdiff;
R r[MAXN];
R q[MAXN];

int cnt[MAXF+1];
int off[MAXF+2];
int pos[MAXF+1];

int x[MAXN],nx;

int bit[MAXN+1];
int mark[MAXN+1],curmark;

void binc(int x) {
	//printf("\t\tbinc(%d)\n",::x[x]);
	int idx=x+1;
	while(idx<=nx) { if(mark[idx]!=curmark) mark[idx]=curmark,bit[idx]=0; ++bit[idx]; idx+=idx&-idx; }
}
int bget(int x) {
	int idx=x+1;
	int ret=0; while(idx>0) { if(mark[idx]!=curmark) mark[idx]=curmark,bit[idx]=0; ret+=bit[idx]; idx-=idx&-idx; } return ret;
}
int bget(int lx,int rx) {
	if(lx>rx) return 0;
	//printf("\t\tbget(%d..%d)\n",::x[lx],::x[rx]);
	return bget(rx)-bget(lx-1);
}

ll solve() {
	sort(r,r+n,fcmp);
	nx=0; REP(i,n) x[nx++]=r[i].x; sort(x,x+nx); nx=unique(x,x+nx)-x;
	REP(i,n) r[i].xid=lower_bound(x,x+nx,r[i].x)-x;
	memset(cnt,0,sizeof(cnt)); REP(i,n) ++cnt[r[i].f];
	REPE(i,MAXF) off[i+1]=off[i]+cnt[i];
	REP(i,n) q[i]=r[i]; REPE(i,MAXF) sort(q+off[i],q+off[i+1],scmp);

	ll ret=0; memset(mark,-1,sizeof(mark)); curmark=-1;
	for(int at=0,to=at;at<n;at=to) {
		int f=r[at].f; ++curmark;
		while(to<n&&r[to].f==f) ++to;
		int fmn=max(0,f-mxdiff),fmx=min(MAXF,f+mxdiff);
		//printf("processing f=%d -> %d..%d\n",f,fmn,fmx); FORE(j,fmn,fmx) if(cnt[j]>0) printf("\t%d: %d -> %d\n",j,cnt[j],q[off[j]+pos[j]].x+q[off[j]+pos[j]].r);
		FORE(j,fmn,fmx) pos[j]=0;
		for(int i=to-1;i>=at;--i) {
			//printf("\tq%d\n",r[i].x);
			FORE(j,fmn,fmx) while(pos[j]<cnt[j]&&q[off[j]+pos[j]].x+q[off[j]+pos[j]].r>=r[i].x) binc(q[off[j]+(pos[j]++)].xid);
			int lxid=lower_bound(x,x+nx,r[i].x-r[i].r)-x,rxid=r[i].xid-1;
			int cur=bget(lxid,rxid);
			ret+=cur;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&mxdiff); REP(i,n) scanf("%d%d%d",&r[i].x,&r[i].r,&r[i].f);
	printf("%lld\n",solve());
}


int main() {
	run();
	return 0;
}