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

const int MAXN=1000000;
const int MAXQ=1000000;

int n,nq;
int p[MAXN];
int ql[MAXQ],qr[MAXQ]; ll qans[MAXQ];

int pos[MAXN];
int nxt[MAXN],prv[MAXN];
ll ccost[MAXN],rcost[MAXN],lcost[MAXN];

int stck[MAXN],nstck;
ll sum[MAXN+1];

vector<int> byl[MAXN],byr[MAXN];

void solve() {
	REP(i,n) pos[p[i]]=i;

	{ nstck=0; REP(i,n) { while(nstck>0&&p[stck[nstck-1]]<p[i]) --nstck; prv[i]=nstck==0?-1:stck[nstck-1]; stck[nstck++]=i; } }
	{ nstck=0; for(int i=n-1;i>=0;--i) { while(nstck>0&&p[stck[nstck-1]]<p[i]) --nstck; nxt[i]=nstck==0?-1:stck[nstck-1]; stck[nstck++]=i; } }
	//printf("prv:"); REP(i,n) printf(" %d",prv[i]); puts("");
	//printf("nxt:"); REP(i,n) printf(" %d",nxt[i]); puts("");

	REP(i,n) rcost[i]=lcost[i]=0;
	REP(v,n) {
		int i=pos[v];
		int r=nxt[i]==-1?n-1:nxt[i]-1;
		int l=prv[i]==-1?0:prv[i]+1;
		ccost[i]=r-l+1+lcost[i]+rcost[i];
		if(prv[i]!=-1&&(nxt[i]==-1||p[prv[i]]<p[nxt[i]])) rcost[prv[i]]+=ccost[i];
		if(nxt[i]!=-1&&(prv[i]==-1||p[nxt[i]]<p[prv[i]])) lcost[nxt[i]]+=ccost[i];
	}
	//printf("ccost:"); REP(i,n) printf(" %lld",ccost[i]); puts("");
	//printf("lcost:"); REP(i,n) printf(" %lld",lcost[i]); puts("");
	//printf("rcost:"); REP(i,n) printf(" %lld",rcost[i]); puts("");

	REP(i,nq) { int l=ql[i],r=qr[i]; qans[i]=r-l+1; byl[l].PB(i); byr[r].PB(i); }
	{
		nstck=0; sum[nstck]=0;
		for(int i=n-1;i>=0;--i) {
			while(nstck>0&&p[stck[nstck-1]]<p[i]) --nstck;
			stck[nstck++]=i; sum[nstck]=sum[nstck-1]+rcost[i]+(nxt[i]==-1?n:nxt[i]);
			REPSZ(j,byl[i]) {
				int idx=byl[i][j],r=qr[idx];
				int lo=-1,hi=nstck-1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(stck[mi]>r) lo=mi; else hi=mi; }
				// hi..nstck-1 are in range
				//printf("%dR (l=%d,r=%d):",idx,i+1,r+1); for(int k=nstck-1;k>=hi;--k) printf(" %d",stck[k]+1); printf(" -> %lld-%lld-%d*%d\n",sum[nstck],sum[hi+1],nstck-hi-1,i);
				qans[idx]+=sum[nstck]-sum[hi+1]-(ll)(nstck-hi-1)*i;
			}
		}
	}
	{
		nstck=0; sum[nstck]=0;
		REP(i,n) {
			while(nstck>0&&p[stck[nstck-1]]<p[i]) --nstck;
			stck[nstck++]=i; sum[nstck]=sum[nstck-1]+lcost[i]-(prv[i]==-1?0:prv[i]+1);
			REPSZ(j,byr[i]) {
				int idx=byr[i][j],l=ql[idx];
				int lo=-1,hi=nstck-1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(stck[mi]<l) lo=mi; else hi=mi; }
				// hi..nstck-1 are in range
				//printf("%dL (l=%d,r=%d):",idx,l+1,i+1); for(int k=nstck-1;k>=hi;--k) printf(" %d",stck[k]+1); printf(" -> %lld-%lld+%d*%d\n",sum[nstck],sum[hi+1],nstck-hi-1,i+1);
				qans[idx]+=sum[nstck]-sum[hi+1]+(ll)(nstck-hi-1)*(i+1);
			}
		}
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&p[i]),--p[i];
	REP(i,nq) scanf("%d",&ql[i]),--ql[i];
	REP(i,nq) scanf("%d",&qr[i]),--qr[i];
	solve();
	REP(i,nq) { if(i!=0) printf(" "); printf("%lld",qans[i]); } puts("");
}

int main() {
	run();
	return 0;
}