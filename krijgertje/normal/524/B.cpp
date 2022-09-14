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

int n;
int w[1000],h[1000];

int fsth[1001],fstw[1001];
int nxth[1000],nxtw[1000];

int q[2001],nq;

typedef struct LIE { int gain,idx; } LIE;
bool operator<(const LIE &p,const LIE &q) { if(p.gain!=q.gain) return p.gain>q.gain; return p.idx<q.idx; }
LIE lie[1000]; int nlie;
int fstl,prvl[1000],nxtl[1000],lidx[1000];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&w[i],&h[i]);

	REPE(i,1000) fstw[i]=fsth[i]=-1;
	REP(i,n) {
		nxth[i]=fsth[h[i]]; fsth[h[i]]=i;
		nxtw[i]=fstw[w[i]]; fstw[w[i]]=i;
	}

	nq=0; REP(i,n) q[nq++]=w[i],q[nq++]=h[i]; sort(q,q+nq); nq=unique(q,q+nq)-q;

	bool ok=true; int sumw=0; nlie=0; int curlie=0,maxlie=n;
	REP(i,n) { sumw+=w[i]; if(w[i]>h[i]) lie[nlie].gain=w[i]-h[i],lie[nlie].idx=i,++nlie; }
	sort(lie,lie+nlie);
	REP(i,n) lidx[i]=-1; REP(i,nlie) lidx[lie[i].idx]=i;
	fstl=nlie==0?-1:0; REP(i,nlie) prvl[i]=i==0?-1:i-1,nxtl[i]=i==nlie-1?-1:i+1;
	int atlie=-1;
	while(curlie<maxlie&&(atlie==-1&&fstl!=-1||atlie!=-1&&nxtl[atlie]!=-1)) { atlie=atlie==-1?fstl:nxtl[atlie]; sumw-=lie[atlie].gain; ++curlie; }

	int ret=INT_MAX;
	for(int qi=nq-1;ok&&qi>=0;--qi) {
		int ch=q[qi],cur=sumw*ch; if(cur<ret) ret=cur;
		for(int i=fsth[ch];i!=-1;i=nxth[i]) {
			if(h[i]>=w[i]) {
				sumw+=h[i]-w[i]; ++curlie;
			} else {
				ok=false;
			}
		}
		for(int i=fstw[ch];i!=-1;i=nxtw[i]) {
			if(w[i]>h[i]) {
				if(lidx[i]<=atlie) { sumw+=w[i]-h[i]; --curlie; }
				if(lidx[i]==atlie) atlie=prvl[atlie];
				if(prvl[lidx[i]]!=-1) nxtl[prvl[lidx[i]]]=nxtl[lidx[i]]; else fstl=nxtl[lidx[i]];
				if(nxtl[lidx[i]]!=-1) prvl[nxtl[lidx[i]]]=prvl[lidx[i]];
			} else {
				ok=false;
			}
		}
		while(curlie>maxlie&&atlie!=-1) { sumw+=lie[atlie].gain; atlie=prvl[atlie]; --curlie; }
		if(curlie>maxlie) ok=false;
		while(curlie<maxlie&&(atlie==-1&&fstl!=-1||atlie!=-1&&nxtl[atlie]!=-1)) { atlie=atlie==-1?fstl:nxtl[atlie]; sumw-=lie[atlie].gain; ++curlie; }
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}