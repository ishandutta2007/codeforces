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

const int MAXN=300000;
const int LOGMAXN=19;
const int MAXMOD=1000000;
const int MAXQ=LOGMAXN*MAXN;

int n,MOD;
int a[MAXN];
int asum[MAXN+1];

int l[MAXN],r[MAXN];
int stck[MAXN],nstck;

int nq;
int fst[MAXN+1];
int nxt[MAXQ],sgn[MAXQ],val[MAXQ];
int cnt[MAXMOD];

void run() {
	scanf("%d%d",&n,&MOD);
	REP(i,n) scanf("%d",&a[i]);
	asum[0]=0; REP(i,n) asum[i+1]=(asum[i]+a[i])%MOD;

	nstck=0;
	REP(i,n) {
		while(nstck>0&&a[stck[nstck-1]]<a[i]) --nstck;
		l[i]=nstck==0?0:stck[nstck-1]+1;
		stck[nstck++]=i;
	}
	nstck=0;
	for(int i=n-1;i>=0;--i) {
		while(nstck>0&&a[stck[nstck-1]]<=a[i]) --nstck;
		r[i]=nstck==0?n-1:stck[nstck-1]-1;
		stck[nstck++]=i;
	}
	//REP(i,n) printf("%d=%d: %d..%d\n",i,a[i],l[i],r[i]);

	REPE(i,n) fst[i]=-1; nq=0;
	REP(i,n) {
		//printf("%d=%d: %d..%d\n",i,a[i],l[i],r[i]);
		if(i-l[i]<=r[i]-i) {
			// sum(a[j]..a[i-1])+sum(a[i+1]..a[k]) = 0 (mod MOD) | i<=k<=r[i]
			// asum[k+1] = asum[j]+asum[i+1]-asum[i] = C (mod MOD) | i<=k<=r[i]
			// asum[k] = asum[j]+asum[i+1]-asum[i] = C (mod MOD) | i+1<=k<=r[i]+1
			// #(asum[k]=C, 0<=k<=r[i]+1)-#(asum[k]=C, 0<=k<=i)
			FORE(j,l[i],i) {
				int cur=asum[j]+asum[i+1]-asum[i]; if(cur>=MOD) cur-=MOD; if(cur<0) cur+=MOD;
				//printf("\t%d..%d + %d..k (max %d) -> %d (+%d -%d)\n",j,i-1,i+1,r[i],cur,r[i]+1,i);
				nxt[nq]=fst[r[i]+1]; fst[r[i]+1]=nq; sgn[nq]=+1; val[nq]=cur; ++nq;
				nxt[nq]=fst[i]; fst[i]=nq; sgn[nq]=-1; val[nq]=cur; ++nq;
			}
		} else {
			// sum(a[k]..a[i-1])+sum(a[i+1]..a[j]) = 0 (mod MOD) | l[i]<=k<=i
			// asum[k] = asum[j+1]+asum[i]-asum[i+1] = C (mod MOD) | l[i]<=k<=i
			// #(asum[k]=C, 0<=k<=i)-#(asum[k]=C, 0<=k<=l[i]-1)
			FORE(j,i,r[i]) {
				int cur=asum[j+1]+asum[i]-asum[i+1]; if(cur>=MOD) cur-=MOD; if(cur<0) cur+=MOD;
				//printf("\tk  (min %d)..%d + %d..%d -> %d (+%d -%d)\n",l[i],i-1,i+1,j,cur,i,l[i]-1);
				nxt[nq]=fst[i]; fst[i]=nq; sgn[nq]=+1; val[nq]=cur; ++nq;
				if(l[i]!=0) { nxt[nq]=fst[l[i]-1]; fst[l[i]-1]=nq; sgn[nq]=-1; val[nq]=cur; ++nq; }
			}
		}
	}
	//REPE(i,n) if(fst[i]!=-1) { printf("%d:",i); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %c%d",sgn[x]==+1?'+':sgn[x]==-1?'-':'?',val[x]); puts(""); }

	ll ret=-n;
	REP(i,MOD) cnt[i]=0;
	REPE(i,n) {
		++cnt[asum[i]];
		for(int x=fst[i];x!=-1;x=nxt[x]) ret+=sgn[x]*cnt[val[x]];
	}
	cout<<ret<<endl;

	//int chk=0; REPE(i,n) for(int x=fst[i];x!=-1;x=nxt[x]) REPE(j,i) if(asum[j]==val[x]) chk+=sgn[x]; chk-=n; assert(chk==ret);
}


int main() {
	run();
	return 0;
}