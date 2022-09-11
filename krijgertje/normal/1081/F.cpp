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

const int MAXN=300;

int n,initone;
char ans[MAXN+1];

int curone;
bool flipped[MAXN];

bool local=false; int nq;
char initlocal[MAXN+1];
char curlocal[MAXN+1];

int query(int l,int r) {
	++nq;
	if(!local) {
		printf("? %d %d\n",l+1,r+1); fflush(stdout); int ret; scanf("%d",&ret); if(ret==-1) exit(0); return ret;
	} else {
		if(rand()%2==0) REPE(i,r) curlocal[i]='0'+1-(curlocal[i]-'0'); else FOR(i,l,n) curlocal[i]='0'+1-(curlocal[i]-'0');
		int ret=0; REP(i,n) ret+=curlocal[i]=='1'?1:0; 
		//printf("query(%d,%d) -> %s (%d)\n",l,r,curlocal,ret);
		return ret;
	}
}

bool isone(int idx) { assert(ans[idx]!='?'); return (ans[idx]=='1')==(!flipped[idx]); }

void fliprange(int l,int r,int nxtone) {
	int outside=0; REP(i,n) if(i<l||i>r) outside+=isone(i)?1:0;
	assert(nxtone==outside+(r-l+1)-(curone-outside));
	FORE(i,l,r) flipped[i]=!flipped[i];
	curone=nxtone;
}
void fliprangeunchecked(int l,int r,int nxtone) {
	FORE(i,l,r) flipped[i]=!flipped[i];
	curone=nxtone;
}
void setans(int idx,char val) {
	ans[idx]=!flipped[idx]?val:'0'+1-(val-'0');
	//printf("ans[%d]=%c\n",idx,ans[idx]);
}
int getpair(int cnt,int idx1,int idx2) {
	assert(flipped[idx1]==flipped[idx2]);
	if(flipped[idx1]) cnt=2-cnt;
	return cnt;
}

void solveeven() {
	curone=initone; REP(i,n) flipped[i]=false,ans[i]='?';
	while(ans[0]=='?') {
		int nxtone=query(1,n-1);
		if(nxtone%2==curone%2) fliprange(0,n-1,nxtone); else { int whenzero=n-curone-1,whenone=n-curone+1; assert(nxtone==whenzero||nxtone==whenone); setans(0,nxtone==whenzero?'0':'1'); fliprange(1,n-1,nxtone); }
	}
	while(ans[n-1]=='?') {
		int nxtone=query(0,n-2);
		if(nxtone%2==curone%2) fliprange(0,n-1,nxtone); else { int whenzero=n-curone-1,whenone=n-curone+1; assert(nxtone==whenzero||nxtone==whenone); setans(n-1,nxtone==whenzero?'0':'1'); fliprange(0,n-2,nxtone); }
	}
	for(int i=n-2;i>=1;--i) {
		while(ans[i]=='?') {
			int l=0,r=i-1; if((r-l+1)%2==0) ++l;
			int nxtone=query(l,r);

			bool samepar=nxtone%2==curone%2,firsteven=(r+1)%2==0;
			if(samepar==firsteven) {
				int outside=0; FOR(j,r+2,n) outside+=isone(j)?1:0;
				int whenzero=outside+(r+1)-(curone-outside),whenone=outside+1+(r+1)-(curone-outside-1);
				assert(nxtone==whenzero||nxtone==whenone); setans(i,nxtone==whenzero?'0':'1'); fliprange(0,r,nxtone);
			} else {
				fliprange(l,n-1,nxtone);
			}
		}
	}
}

int apair[MAXN];
int bpair[MAXN];

void solveodd() {
	curone=initone; REP(i,n) flipped[i]=false,ans[i]='?';
	REP(i,(n-1)/2) {
		apair[i]=-1;
		while(apair[i]==-1) {
			int l=0,r=2*i+1;
			int nxtone=query(l,r);
			if(nxtone%2!=curone%2) {
				fliprange(0,n-1,nxtone);
			} else {
				int inside=0; REP(j,i) inside+=getpair(apair[j],2*j+0,2*j+1);
				int whenzero=curone-inside+2*i-inside+2,whenmixed=curone-(inside+1)+2*i-inside+1,whenone=curone-(inside+2)+2*i-inside;
				assert(nxtone==whenzero||nxtone==whenmixed||nxtone==whenone); apair[i]=getpair(nxtone==whenzero?0:nxtone==whenmixed?1:2,2*i+0,2*i+1); fliprangeunchecked(l,r,nxtone);
			}
		}
	}
	REP(i,(n-1)/2) {
		while(flipped[2*i+1]!=flipped[2*i+2]) {
			int l=0,r=2*i+1;
			int nxtone=query(l,r);
			if(nxtone%2!=curone%2) {
				fliprange(0,n-1,nxtone);
			} else {
				fliprangeunchecked(l,r,nxtone);
			}
		}
	}
	REP(i,(n-1)/2) {
		bpair[i]=-1;
		while(bpair[i]==-1) {
			int l=n-2-2*i,r=n-1;
			int nxtone=query(l,r);
			if(nxtone%2!=curone%2) {
				fliprange(0,n-1,nxtone);
			} else {
				int inside=0; REP(j,i) inside+=getpair(bpair[j],n-2-2*j+0,n-2-2*j+1);
				int whenzero=curone-inside+2*i-inside+2,whenmixed=curone-(inside+1)+2*i-inside+1,whenone=curone-(inside+2)+2*i-inside;
				assert(nxtone==whenzero||nxtone==whenmixed||nxtone==whenone); bpair[i]=getpair(nxtone==whenzero?0:nxtone==whenmixed?1:2,n-2-2*i+0,n-2-2*i+1); fliprangeunchecked(l,r,nxtone);
			}
		}
	}

	//printf("apair:"); REP(i,(n-1)/2) printf(" %d",apair[i]); puts("");
	//printf("bpair:"); REP(i,(n-1)/2) printf(" %d",bpair[i]); puts("");
	int asum=0; REP(i,(n-1)/2) asum+=apair[i];
	ans[n-1]='0'+initone-asum;
	for(int i=n-2;i>=0;--i) {
		if(i%2==1) ans[i]='0'+bpair[(n-i-2)/2]-(ans[i+1]-'0');
		if(i%2==0) ans[i]='0'+apair[i/2]-(ans[i+1]-'0');
	}
}

void solve() {
	if(n%2==0) solveeven(); else solveodd();
	ans[n]='\0';
}

void run() {
	scanf("%d%d",&n,&initone);
	solve();
	printf("! %s\n",ans); fflush(stdout);
}

int mxq=0;
void runlocal() {
	local=true; nq=0;
	//printf("initlocal=%s\n",initlocal);
	solve();
	bool ok=true; REP(i,n) if(ans[i]!=initlocal[i]) ok=false;
	if(ok) { if(nq>mxq) printf("nq=%d\n",nq),mxq=nq; printf("."); return; }
	printf("have=%s want=%s\n",ans,initlocal);
}

void stress() {
	REP(rep,10000) {
		n=rand()%2==0?MAXN:MAXN-1; REP(i,n) initlocal[i]=curlocal[i]='0'+rand()%2; initlocal[n]=curlocal[n]='\0'; initone=0; REP(i,n) initone+=initlocal[i]=='1'?1:0;
		runlocal();
	}
}

int main() {
	run();
	//stress();
	return 0;
}