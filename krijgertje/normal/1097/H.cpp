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

const int MAXBASE=20;
const int MAXB=30000;
const int MAXLG=100;
const int MAXMOD=60;

int base,MOD;
int gen[MAXBASE];
int nb;
int b[MAXB];
ll ql,qr;

int bfcalc(int na) {
	vector<int> a(na,0); REP(i,na) { int x=i; while(x!=0) a[i]+=gen[x%base],x/=base; a[i]%=MOD; }
	printf("a:"); REPSZ(i,a) printf(" %d",a[i]); puts("");
	int ret=0; REPE(i,SZ(a)-nb) { bool ok=true; REP(j,nb) if(b[j]<a[i+j]) { ok=false; break; } if(ok) ++ret; } return ret;
}

int d[MAXLG],nd;
ll dp[MAXLG+1][MAXMOD]; // with i freedigits, make j
ll dpsum[MAXLG+1][MAXMOD][MAXMOD]; // with i free digits and one less than k, make j

void dbuild(ll len) {
	nd=0; for(ll x=len;x!=0;x/=base) d[nd++]=x%base; reverse(d,d+nd);
}


ll calc(ll len,int want) {
	//printf("len:%lld want:%d, d:",len,want); REP(i,nd) printf(" %d",d[i]); puts("");
	int have=0; REP(i,nd) have+=gen[d[i]]; have%=MOD;
	ll ret=0;
	for(int i=nd-1;i>=0;--i) {
		have-=gen[d[i]]; if(have<0) have+=MOD;
		/*REP(j,d[i]) {
			int cur=have+gen[j]; if(cur>=MOD) cur-=MOD;
			int need=want-cur; if(need<0) need+=MOD;
			//printf("\tneed %d with %d free digits\n",need,nd-i-1);
			ret+=dp[nd-i-1][need];
		}*/
		int need=want-have; if(need<0) need+=MOD; ret+=dpsum[nd-i-1][need][d[i]];
	}
	//printf("=>%lld\n",ret);
	return ret;
}

map<ll,int> mem2;
vector<vector<ll>> memvals;

ll calcmask(ll len,ll mask) {
	if(!mem2.count(len)) {
		dbuild(len); vector<ll> vals(MOD); REP(i,MOD) vals[i]=calc(len,i);
		memvals.PB(vals); mem2[len]=SZ(memvals)-1;
	}
	int idx=mem2[len]; ll ret=0; REP(i,MOD) if((mask&(1LL<<i))!=0) ret+=memvals[idx][i]; return ret;
}

map<pair<ll,vector<ll>>,ll> mem;

ll rec(ll len,vector<ll> mask,int dep=0) {
	//if(dep!=0&&dep<=2) { REP(rep,dep) printf("  "); printf("len=%lld mask:",len); REPSZ(i,mask) { printf(" ["); int last=-2; REP(j,MOD) if(mask[i]&(1LL<<j)) { if(last>=0&&j!=last+1) { printf("..%d",last); last=-1; } if(last==-1) printf(","); if(last<0||j!=last+1) printf("%d",j); last=j; } if(last>=0) printf("..%d",last); printf("]"); } puts(""); }
	if(SZ(mask)>len) return 0;
	assert(SZ(mask)>0);
	//if(len==1) return SZ(mask)==1&&((mask[0]&1)!=0)?1:0;
	if(SZ(mask)==1) return calcmask(len,mask[0]);
	//if(SZ(mask)==2) { dbuild(len); ll ret=0; REP(i,MOD) if((mask[0]&(1LL<<i))!=0) REP(j,MOD) if((mask[1]&(1LL<<j))!=0) ret+=calc(len,i,j); return ret; }
	//if(len>2) { REP(rep,dep) printf("  "); printf("len=%lld SZ(mask)=%d\n",len,SZ(mask)); }
	ll ret=0;
	//pair<ll,vector<ll>> key=MP(len,mask); if(mem.count(key)) return mem[key];
	REP(offset,base) if(offset+SZ(mask)<=len) {
		vector<ll> nmask; bool ok=true;
		REPSZ(i,mask) {
			// l[i]<=a[x*base+offset+i]<=r[i] -> l[i]<=gen[(offset+i)%base]+a[x+(offset+i)/base] mod MOD<=r[i] -> l[i]-gen[(offset+i)%base]+x*MOD<=a[x+(offset+i)/base]<=r[i]-gen[(offset+i)%base]+y*MOD
			// nl[(offset+i)/base]>=l[i]-gen[(offset+i)%base]+x*MOD and nr[(offset+i)/base]<=r[i]-gen[(offset+i)%base]+y*MOD
			int idx=(offset+i)/base,delta=gen[(offset+i)%base];
			ll cmask=(mask[i]>>delta)|((mask[i]&((1LL<<delta)-1))<<(MOD-delta));
			//printf("offset=%d i=%d idx=%d delta=%d omask=%lld cmask=%lld\n",offset,i,idx,delta,mask[i],cmask);
			if(idx>=SZ(nmask)) nmask.PB(cmask); else { nmask[idx]&=cmask; if(nmask[idx]==0) { ok=false; break; } }
		}
		if(!ok) continue;
		//REP(rep,dep) printf("  "); printf("%d:",offset); REPSZ(i,nmask) { printf(" ["); bool fst=true; REP(j,MOD) if(nmask[i]&(1LL<<j)) { if(fst) fst=false; else printf(","); printf("%d",j); } printf("]"); } puts("");
		// x*base+offset+SZ(mask)<=len
		// x+SZ(nmask)<=(len-SZ(mask)-offset)/base+SZ(nmask)
		ll nlen=(len-SZ(mask)-offset)/base+SZ(nmask);
		if(nlen>=len) { REP(rep,dep) printf("  "); printf("len does not decrease (len=%lld nlen=%lld SZ(mask)=%d SZ(nmask)=%d offset\n",len,nlen,SZ(mask),SZ(nmask),offset); continue; }
		ret+=rec(nlen,nmask,dep+1);
	}
	//mem[key]=ret;
	return ret;
}

ll calc(ll na) {
	//int want=na<1000?bfcalc(na):-1;
	vector<ll> smask(nb); REP(i,nb) smask[i]=(2LL<<b[i])-1;
	ll have=rec(na,smask);
	//if(want!=-1&&want!=have) { printf("err: have=%lld want=%d\n",have,want); }
	return have;
}

ll solve() {
	mem.clear(); mem2.clear(); memvals.clear();
	REP(j,MOD) dp[0][j]=j==0?1:0;
	FORE(i,1,MAXLG) REP(j,MOD) { dp[i][j]=0; REP(k,base) dp[i][j]+=dp[i-1][(j+MOD-gen[k])%MOD]; }
	REPE(i,MAXLG) REP(j,MOD) { dpsum[i][j][0]=0; REP(k,base) dpsum[i][j][k+1]=dpsum[i][j][k]+dp[i][(j+MOD-gen[k])%MOD]; }
	ll ret=calc(qr+1)-calc(ql+nb-1);
	return ret;
}

void run() {
	scanf("%d%d",&base,&MOD);
	REP(i,base) scanf("%d",&gen[i]);
	scanf("%d",&nb);
	REP(i,nb) scanf("%d",&b[i]);
	scanf("%lld%lld",&ql,&qr),--ql,--qr;
	printf("%lld\n",solve());
}

void stress() {
	REP(rep,1000) {
		base=20; //rand()%(20-2+1)+2;
		MOD=60; //rand()%(60-2+1)+2;
		gen[0]=0; FOR(i,1,base) gen[i]=rand()%MOD;
		nb=MAXB; REP(i,nb) b[i]=MOD-1; //rand()%MOD;
		REP(i,10) { int idx=rand()%nb; --b[idx]; if(b[idx]<0) b[idx]+=MOD; }
		ql=rand()%1000*1000000000000000LL+rand()%1000*1000000000000LL+rand()%1000*1000000000LL+rand()%1000*1000000+rand()%1000*1000+rand()%1000+1;
		qr=rand()%1000*1000000000000000LL+rand()%1000*1000000000000LL+rand()%1000*1000000000LL+rand()%1000*1000000+rand()%1000*1000+rand()%1000+1;
		//ql=rand()%1000*1000000+rand()%1000*1000+rand()%1000+1;
		//qr=rand()%1000*1000000+rand()%1000*1000+rand()%1000+1;
		if(ql>qr) swap(ql,qr);
		printf("base=%d MOD=%d ql=%lld qr=%lld\n",base,MOD,ql,qr);
		ll have=solve();
		printf("=%lld\n",have);
	}
}

int main() {
	run();
	//stress();
	return 0;
}