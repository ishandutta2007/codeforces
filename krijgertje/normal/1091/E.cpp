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

const int MAXN=500000;
const int MAXS=4*(MAXN+2);

int na;
int a[MAXN];

vector<int> ans;

int nb;
int b[MAXN+1];

ll bsum[MAXN+2];
ll cons[MAXN+2];

ll slazy[MAXS];
ll sval[MAXS];

void sapply(int x,int val) { slazy[x]+=val; sval[x]+=val; }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void spull(int x) { sval[x]=min(sval[2*x+1],sval[2*x+2]); }
void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		sval[x]=cons[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void smod(int x,int l,int r,int L,int R,int BY) {
	//if(x==0) printf("smod(%d,%d..%d,%d..%d,%d)\n",x,l,r,L,R,BY);
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}

void binc(int idx) {
	smod(0,1,nb,idx+1,nb,-1);
	int l=b[idx]+1,r=idx; if(l<=r) smod(0,1,nb,l,r,+1);
	b[idx]++;
}

void solve() {
	ans.clear();
	sort(a,a+na); reverse(a,a+na);
	//printf("a:"); REP(i,na) printf(" %d",a[i]); puts("");

	ll asum=0; REP(i,na) asum+=a[i];
	int me=asum%2;
	nb=0; REP(i,na) b[nb++]=a[i]; b[nb++]=me; sort(b,b+nb); reverse(b,b+nb);
	//printf("b:"); REP(i,nb) printf(" %d",b[i]); puts("");
	int meidx=-1; REP(i,nb) if(b[i]==me) { meidx=i; break; } assert(meidx!=-1);
	bsum[0]=0; REP(i,nb) bsum[i+1]=bsum[i]+b[i];

	int at=nb; // b[at]<=k
	FORE(k,1,nb) {
		cons[k]=(ll)k*(k-1)-bsum[k];
		while(at>0&&b[at-1]<=k) --at;
		cons[k]+=bsum[nb]-bsum[max(k,at)];
		cons[k]+=(ll)(max(k,at)-k)*k;
		//FOR(i,k,nb) cons[k]+=min(b[i],k);
	}
	//printf("cons:"); FORE(k,1,nb) printf(" %lld",cons[k]); puts("");

	sinit(0,1,nb);
	while(true) {
		if(sval[0]>=0) ans.PB(b[meidx]);
		REP(rep,2) {
			while(meidx>0&&b[meidx]==b[meidx-1]) --meidx;
			binc(meidx);
		}
		if(b[meidx]>na) break;
	}
	sort(ans.begin(),ans.end());
}

void run() {
	scanf("%d",&na);
	REP(i,na) scanf("%d",&a[i]);
	solve();
	if(SZ(ans)==0) { printf("-1\n"); return; }
	REPSZ(i,ans) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}