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

const int MAXDIG=19;
const int MAXC=MAXDIG+1+10;

ll C[MAXC+1][MAXC+1];

int nd;
int dl[MAXDIG],ndl;
int dr[MAXDIG],ndr;

ll calc(int len,int mask) {
	int nopt=0; REP(i,10) if((mask&(1<<i))==0) ++nopt;
	return nopt==0?0:C[len+nopt-1][nopt-1];
}

ll calcabove(int at,int mask) {
	int omask=mask;
	if(at>=nd) return 1;
	ll ret=0; int nrem=nd-at-1;
	FORE(a,dl[at]+1,9) if((mask&(1<<a))==0) ret+=calc(nrem,mask),mask|=1<<a;
	if((mask&(1<<dl[at]))==0) ret+=calcabove(at+1,mask);
	//printf("calcabove(%d,%x)=%lld\n",at,omask,ret);
	return ret;
}

ll calcbelow(int at,int mask) {
	int omask=mask;
	if(at>=nd) return 1;
	ll ret=0; int nrem=nd-at-1;
	FORE(a,0,dr[at]-1) if((mask&(1<<a))==0) ret+=calc(nrem,mask),mask|=1<<a;
	if((mask&(1<<dr[at]))==0) ret+=calcbelow(at+1,mask);
	//printf("calcbelow(%d,%x)=%lld\n",at,omask,ret);
	return ret;
}

ll calcboth(int atr,int mask,vector<int> &cntrneed) {
	int omask=mask;
	if(atr>=nd) { REP(i,10) if(cntrneed[i]>0) return 0; return 1; }
	ll ret=0; int nrem=nd-atr-1; bool done=false;
	FORE(a,0,dr[atr]-1) if(cntrneed[a]>0||(mask&(1<<a))==0) {
		bool needed=cntrneed[a]>0; if(needed) --cntrneed[a];
		int sum=0; REP(i,10) sum+=cntrneed[i]; if(sum<=nrem) ret+=calc(nrem-sum,mask),mask|=1<<a,done=needed;
		if(needed) ++cntrneed[a];
		if(done) break;
	}
	if(!done&&(cntrneed[dr[atr]]>0||(mask&(1<<dr[atr]))==0)) {
		bool needed=cntrneed[dr[atr]]>0; if(needed) --cntrneed[dr[atr]];
		ret+=calcboth(atr+1,mask,cntrneed);
		if(needed) ++cntrneed[dr[atr]];
	}
	//printf("\tcalcboth(%d,%x,",atr,omask); REP(i,10) printf("%d",cntrneed[i]); printf(")=%lld\n",ret);
	return ret;
}

ll calcboth(int atl,int atr,int mask,vector<int> &cntlneed,vector<int> &cntrneed) {
	int omask=mask;
	if(atl>=nd) { REP(i,10) if(cntlneed[i]>0) return 0; return calcboth(atr,mask,cntrneed); }
	ll ret=0; int nrem=nd-atl-1; bool done=false;
	FORE(a,dl[atl]+1,9) if((mask&(1<<a))==0) {
		if(cntlneed[a]>0) --cntlneed[a]; else ++cntrneed[a];
		int sum=0; REP(i,10) sum+=cntlneed[i]; if(sum<=nrem) ret+=calcboth(atr,mask,cntrneed),mask|=1<<a,done=cntrneed[a]==0;
		if(cntrneed[a]>0) --cntrneed[a]; else ++cntlneed[a];
		//printf("%d: calcboth(%d,%d,%x,",a,atl,atr,omask); REP(i,10) printf("%d",cntlneed[i]); printf(","); REP(i,10) printf("%d",cntrneed[i]); printf(")=%lld\n",ret);
		if(done) break;
	}
	if(!done&&(mask&(1<<dl[atl]))==0) {
		if(cntlneed[dl[atl]]>0) --cntlneed[dl[atl]]; else ++cntrneed[dl[atl]];
		ret+=calcboth(atl+1,atr,mask,cntlneed,cntrneed);
		if(cntrneed[dl[atl]]>0) --cntrneed[dl[atl]]; else ++cntlneed[dl[atl]];
	}
	//printf("calcboth(%d,%d,%x,",atl,atr,omask); REP(i,10) printf("%d",cntlneed[i]); printf(","); REP(i,10) printf("%d",cntrneed[i]); printf(")=%lld\n",ret);
	return ret;
}


ll solve(ll ql,ll qr) {
	memset(C,0,sizeof(C)); REPE(i,MAXC) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j]; }

	ndl=0; for(ll x=ql;x!=0;x/=10) dl[ndl++]=x%10;
	ndr=0; for(ll x=qr;x!=0;x/=10) dr[ndr++]=x%10;
	nd=ndr; while(ndl<nd) dl[ndl++]=0;
	reverse(dl,dl+ndl); reverse(dr,dr+ndr);
	//printf("l:"); REP(i,ndl) printf(" %d",dl[i]); puts("");
	//printf("r:"); REP(i,ndr) printf(" %d",dr[i]); puts("");

	int s=0; while(s<nd&&dl[s]==dr[s]) ++s;
	if(s>=nd) return 1;

	ll ret=0; int mask=0; int nrem=nd-s-1;
	FORE(a,dl[s]+1,dr[s]-1) ret+=calc(nrem,mask),mask|=1<<a;
	ret+=calcabove(s+1,mask);
	ret+=calcbelow(s+1,mask);
	//printf("before sub=%lld\n",ret);
	vector<int> cntlneed(10,0),cntrneed(10,0); ++cntlneed[dr[s]]; ++cntrneed[dl[s]]; ret-=calcboth(s+1,s+1,mask,cntlneed,cntrneed);
	return ret;
}


void run() {
	ll ql,qr; scanf("%lld%lld",&ql,&qr);
	printf("%lld\n",solve(ql,qr));
}

void stress() {
	int lim=10000;
	FORE(l,1,lim) {
		set<int> cur;
		FORE(r,l,lim) {
			vector<int> d; for(int x=r;x!=0;x/=10) d.PB(x%10); sort(d.begin(),d.end()); int z=0; REPSZ(i,d) z=10*z+d[i]; cur.insert(z);
			ll have=solve(l,r),want=SZ(cur);
			if(have!=want) { printf("%d %d: have=%lld want=%lld\n",l,r,have,want); }
		}
	}
}

int main() {
	run();
	//stress();
	return 0;
}