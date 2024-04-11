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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
struct Op { int idx; vector<int> vals; };

int n,sz;
int a[MAXN];
vector<Op> ans;

int asum[MAXN+1];
int each;
int bal[MAXN];

pair<int,int> o[MAXN];

int x[2*MAXN],nx;
int y[2*MAXN];
int last[MAXN];
int nxt[2*MAXN];
vector<int> jump[2*MAXN];

int bestval,bestx,bestidx;

int cur[MAXN];

void calc() {
	int den=sz-1;
	REP(i,nx) x[nx+i]=x[i]+n;
	REP(i,2*nx) y[i]=x[i]%den;
	for(int i=2*nx-1;i>=0;--i) { nxt[i]=last[(y[i]+1)%den]; last[y[i]]=i; }
	for(int i=2*nx-1;i>=0;--i) { last[y[i]]=-1; }
	for(int i=2*nx-1;i>=0;--i) { jump[i].clear(); if(nxt[i]==-1) continue; jump[i].PB(nxt[i]); for(int k=1;;++k) { int mid=jump[i][k-1]; if(k-1>=SZ(jump[mid])) break; jump[i].PB(jump[mid][k-1]); } }

	//printf("%d\n",nx);
	//printf("x:"); REP(i,2*nx) printf(" %d",x[i]); puts("");
	//printf("y:"); REP(i,2*nx) printf(" %d",y[i]); puts("");
	//printf("nxt:"); REP(i,2*nx) printf(" %d",nxt[i]); puts("");
	//printf("jump:"); REP(i,2*nx) { printf(" ["); REPSZ(k,jump[i]) { if(k!=0) printf(","); printf("%d",jump[i][k]); } printf("]"); } puts("");

	REP(i,nx) {
		int j=i,steps=0; for(int k=SZ(jump[i])-1;k>=0;--k) if(k<SZ(jump[j])&&jump[j][k]<i+nx) j=jump[j][k],steps+=1<<k;
		int cur=(n-(steps+1)+den-1)/den;
		//printf("%d..%d -> %d\n",i,j,cur);
		if(cur<bestval) bestval=cur,bestx=x[i],bestidx=i;
	}
}

void fixrange(int l,int r,int extra) {
	//printf("fixrange(%d..%d,%d)\n",l,r,extra);
	int totcnt=r-l+1,fstcnt=min(totcnt,sz),fstoff=l;
	int fstsum=0; REP(i,fstcnt) fstsum+=cur[(fstoff+i)%n];
	//printf("fstcnt=%d fstsum=%d each=%d\n",fstcnt,fstsum,each);
	if(fstcnt==1) {
		assert(fstsum==each+extra);
	} else if(fstsum>=(fstcnt-1)*each+extra) {
		int rem=fstsum-(fstcnt-1)*each-extra; if(rem!=each) assert(fstcnt<totcnt);
		Op op; op.idx=fstoff%n; op.vals=vector<int>(sz,-1); REP(i,sz) op.vals[i]=i==0?each+extra:i<fstcnt-1?each:i==fstcnt-1?rem:cur[(fstoff+i)%n]; ans.PB(op);
		int before=0,after=0; REP(i,sz) { int idx=(fstoff+i)%n; before+=cur[idx],after+=op.vals[i]; cur[idx]=op.vals[i]; } assert(before==after);
		if(fstcnt<totcnt) fixrange(l+fstcnt-1,r,0);
	} else {
		assert(fstcnt<totcnt);
		fixrange(l+fstcnt-1,r,(fstcnt-1)*each+extra-fstsum+cur[(fstoff+fstcnt-1)%n]);
		fixrange(l,l+fstcnt-1,extra);
	}
}

void solve() {
	assert(sz>=2);
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	//printf("asum:"); REPE(i,n) printf(" %d",asum[i]); puts("");
	assert(asum[n]%n==0); each=asum[n]/n;
	REP(i,n) bal[i]=asum[i]-i*each;
	//printf("bal:"); REP(i,n) printf(" %d",bal[i]); puts("");

	REP(i,n) o[i]=MP(bal[i],i);
	sort(o,o+n);
	bestval=INT_MAX,bestx=-1,bestidx=-1;
	memset(last,-1,sizeof(last));
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&o[r].first==o[l].first) ++r;
		nx=0; FOR(i,l,r) x[nx++]=o[i].second;
		calc();
	}
	//printf("bestval=%d bestx=%d bestidx=%d\n",bestval,bestx,bestidx);
	nx=0; REP(i,n) if(bal[i]==bal[bestx]) x[nx++]=i;
	calc();

	ans.clear();
	REP(i,n) cur[i]=a[i];
	int at=bestidx;
	while(at<bestidx+nx) {
		if(nxt[at]==-1||nxt[at]>=bestidx+nx) {
			fixrange(x[at],x[bestidx+nx]-1,0);
			break;
		}
		fixrange(x[at],x[nxt[at]]-1,0);
		at=nxt[at];
	}
	//printf("nop=%d\n",SZ(ans));
	//printf("cur:"); REP(i,n) printf(" %d",cur[i]); puts("");
	assert(SZ(ans)==bestval);
	REP(i,n) assert(cur[i]==each);
}

void run() {
	scanf("%d%d",&n,&sz);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) { printf("%d",ans[i].idx); REPSZ(j,ans[i].vals) printf(" %d",ans[i].vals[j]); puts(""); }
}

void stress() {
	int mxn=10,mxeach=10;
	REP(rep,1000000) {
		n=rand()%(mxn-2+1)+2; sz=rand()%(n-2+1)+2; int each=rand()%(mxeach+1);
		REP(i,n) a[i]=0; REP(i,n*each) { int idx=rand()%n; ++a[idx]; }
		//if(rep!=45853) continue;
		//printf("%d %d\n",n,sz);	REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
		solve();
		printf(".");
	}
}

void stresstime() {
	REP(rep,3) {
		n=MAXN; sz=MAXN-1; REP(i,n) a[i]=rand()%1001; int sum=0; REP(i,n) sum+=a[i]; int need=(n-sum%n)%n; REP(i,need) { int idx=rand()%n; a[idx]++; }
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	//stresstime();
	return 0;
}