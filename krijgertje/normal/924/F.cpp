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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXK=9;
const int MAXLEN=19;
const int MAXS=9*MAXLEN/2;
const int XLEN=5;

int xoff[10];
ll xmask[10];

vector<ll> opt[MAXK+1][MAXLEN+1]; // opt[k][i] represents valid options for digits in prefixes such that we can append i digits to make x such that f(x)=k (only for k>=2)
vector<ll> ways[MAXK+1][MAXLEN+1][10]; // ways[k][i][j][x] represents the number integers x with f(x)=k such that the (i-1)th least significant digit is at most j and the count of digits before is opt[k][i][j][x] (only for k>=2)

ll wayspar[2][MAXLEN+1];

bitset<MAXS+1> can[10];
void dfscan(int d,int cnt,int sum,ll x) {
	if(d>9) {
		int mx=sum/2; while(!can[d-1].test(mx)) --mx;
		int k=sum-2*mx; assert(k<=MAXK);
		if(k>=2) opt[k][0].PB(x);
	} else {
		can[d]=can[d-1];
		while(true) {
			dfscan(d+1,cnt,sum,x);
			if(cnt>=MAXLEN) break;
			++cnt; sum+=d; x+=1LL<<xoff[d]; can[d]|=can[d]<<d;
		}
	}
}

void precalc() {
	wayspar[0][0]=1;
	REP(i,MAXLEN) wayspar[0][i+1]=wayspar[0][i]*5+wayspar[1][i]*5,wayspar[1][i+1]=wayspar[0][i]*5+wayspar[1][i]*5;

	xoff[1]=0; FORE(i,2,9) xoff[i]=xoff[i-1]+XLEN;
	FORE(i,1,9) xmask[i]=((ll)((1<<XLEN)-1))<<xoff[i];

	//FORE(d,1,9) printf("%d: xoff=%d xmask=%llx\n",d,xoff[d],xmask[d]);

	can[0].set(0);
	dfscan(1,0,0,0);
	FORE(k,2,MAXK) {
		sort(opt[k][0].begin(),opt[k][0].end());
		opt[k][0].erase(unique(opt[k][0].begin(),opt[k][0].end()),opt[k][0].end());
		//printf("%d: %d %d\n",k,SZ(opt[k][0]),SZ(opt[k][1]));
		REP(d,10) ways[k][0][d]=vector<ll>(SZ(opt[k][0]),1);
		REP(i,MAXLEN) {
			//REPSZ(x,opt[k][i]) printf("%llx\n",opt[k][i][x]);
			REPSZ(x,opt[k][i]) { int sum=0; FORE(d,1,9) if((opt[k][i][x]&xmask[d])!=0) opt[k][i+1].PB(opt[k][i][x]-(1LL<<xoff[d])),sum+=(opt[k][i][x]&xmask[d])>>xoff[d]; if(sum<MAXLEN) opt[k][i+1].PB(opt[k][i][x]); }

			sort(opt[k][i+1].begin(),opt[k][i+1].end());
			opt[k][i+1].erase(unique(opt[k][i+1].begin(),opt[k][i+1].end()),opt[k][i+1].end());
			//printf("\t%d\n",SZ(opt[k][i+1]));
			REP(d,10) ways[k][i+1][d]=vector<ll>(SZ(opt[k][i+1]),0);
			REPSZ(x,opt[k][i]) {
				int sum=0;
				FORE(d,1,9) if((opt[k][i][x]&xmask[d])!=0) {
					int nx=lower_bound(opt[k][i+1].begin(),opt[k][i+1].end(),opt[k][i][x]-(1LL<<xoff[d]))-opt[k][i+1].begin(); assert(0<=nx&&nx<SZ(opt[k][i+1])&&opt[k][i+1][nx]==opt[k][i][x]-(1LL<<xoff[d]));
					ways[k][i+1][d][nx]+=ways[k][i][9][x];
					sum+=(opt[k][i][x]&xmask[d])>>xoff[d];
				}
				if(sum<MAXLEN) {
					int nx=lower_bound(opt[k][i+1].begin(),opt[k][i+1].end(),opt[k][i][x])-opt[k][i+1].begin(); assert(0<=nx&&nx<SZ(opt[k][i+1])&&opt[k][i+1][nx]==opt[k][i][x]);
					ways[k][i+1][0][nx]+=ways[k][i][9][x];
				}
			}
			FORE(d,1,9) REPSZ(x,opt[k][i+1]) ways[k][i+1][d][x]+=ways[k][i+1][d-1][x];
		}
	}
	//FORE(k,2,MAXK) REPE(i,MAXLEN) { REPSZ(x,opt[k][i]) { printf("%d %d %llx:",k,i,opt[k][i][x]); REP(d,10) printf(" %d",ways[k][i][d][x]); puts(""); } }
}

char s[MAXLEN+1];


ll calc(ll lim,int k) {
	sprintf(s,"%lld",lim); int slen=strlen(s);
	ll ret=0,x=0;
	REP(i,slen) {
		int d=s[i]-'0';
		if(d==0) continue;
		int idx=lower_bound(opt[k][slen-i].begin(),opt[k][slen-i].end(),x)-opt[k][slen-i].begin();
		if(idx!=SZ(opt[k][slen-i])&&opt[k][slen-i][idx]==x) {
			//printf("\tways[%d][%d][%d][%d]=%lld (%llx,%s)\n",k,slen-i,d-1,idx,ways[k][slen-i][d-1][idx],opt[k][slen-i][x],s);
			ret+=ways[k][slen-i][d-1][idx];
		}
		x+=1LL<<xoff[d];
	}
	return ret;
}

ll calcodd(ll lim) {
	sprintf(s,"%lld",lim); int slen=strlen(s);
	ll ret=0; int par=0;
	REP(i,slen) {
		int d=s[i]-'0';
		if(d==0) continue;
		int oddhere=d/2,evnhere=(d+1)/2;
		ret+=wayspar[par][slen-i-1]*oddhere+wayspar[1-par][slen-i-1]*evnhere;
		if(d%2==1) par^=1;
	}
	//printf("calcodd(%s)=%lld\n",s,ret);
	return ret;
}

ll solve(ll l,ll r,int kmx) {
	ll ret=r-l+1;
	if(kmx==0) {
		ret-=calcodd(r+1)-calcodd(l);
		for(int k=2;k<=MAXK;k+=2) ret-=calc(r+1,k)-calc(l,k);
	} else {
		FORE(k,kmx+1,MAXK) ret-=calc(r+1,k)-calc(l,k);
	}
	return ret;
}

void run() {
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		ll l,r; int k; scanf("%lld%lld%d",&l,&r,&k);
		printf("%lld\n",solve(l,r,k));
	}
}

int main() {
	precalc();
	run();
	return 0;
}