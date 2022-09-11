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

const int MAXEVENT=100000;
const int MAXLEN=1000000;
const int MAXFRIEND=40;
const int MAXN2=MAXFRIEND/2;

int nevent,nfriend;
map<string,int> name2id;
char buff[MAXLEN+1];
int ekind[MAXEVENT],eid[MAXEVENT];

ll conflict[MAXFRIEND];

int dp[1<<MAXN2];

int solve() {
	REP(i,nfriend) conflict[i]=0;
	for(int l=0,r=l;l<nevent;l=r) {
		while(r<nevent&&ekind[l]==ekind[r]) ++r;
		if(ekind[l]==1) continue;
		ll mask=0; FOR(i,l,r) mask|=1LL<<eid[i];
		REP(i,nfriend) if(mask&(1LL<<i)) conflict[i]|=mask^(1LL<<i);
	}
	//REP(i,nfriend) { printf("conflict%d: ",i); REP(j,nfriend) printf("%c",(conflict[i]&(1LL<<j))!=0?'x':'.'); puts(""); }
	int n1=nfriend/2,n2=nfriend-n1;
	dp[0]=0;
	FOR(mask,1,1<<n2) {
		int idx=0; while((mask&(1<<idx))==0) ++idx;
		int at=n1+idx,okmask=(1<<n2)-1-(conflict[at]>>n1)-(1<<idx);
		dp[mask]=max(dp[mask^(1<<idx)],1+dp[mask&okmask]);
		//printf("dp[%x]=%d (at=%d,okmask=%x)\n",mask,dp[mask],at,okmask);
	}
	int ret=0;
	REP(mask,1<<n1) {
		int cur=0,okmask=(1<<n2)-1; bool ok=true;
		REP(i,n1) if(mask&(1<<i)) { 
			++cur;
			if((mask&conflict[i])!=0) { ok=false; break; }
			okmask&=((1LL<<nfriend)-1-conflict[i])>>n1; 
		}
		if(!ok) continue;
		ret=max(ret,cur+dp[okmask]);
	}
	return ret;
}


void run() {
	scanf("%d%d",&nevent,&nfriend);
	name2id.clear();
	REP(i,nevent) {
		scanf("%d",&ekind[i]);
		if(ekind[i]==2) { scanf("%s",buff); if(!name2id.count(buff)) { int id=SZ(name2id); name2id[buff]=id; } eid[i]=name2id[buff]; }
	}
	assert(SZ(name2id)==nfriend);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}