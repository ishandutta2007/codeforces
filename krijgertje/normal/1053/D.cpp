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

const int MAXN=200000;
const int MAXVAL=2000000;
const int MOD=1000000007;

int n;
int a[MAXN];

int b[MAXN];
int c[MAXN],nc;

int pmn[MAXVAL+1];
int cnt[MAXVAL+1];
int times[MAXVAL+1];

void mark(int x) { while(x!=1) { int p=pmn[x],cur=0; while(x%p==0) ++cur,x/=p; if(cur>cnt[p]) cnt[p]=cur,times[p]=0; if(cur==cnt[p]) ++times[p]; } }
bool isneeded(int x) { while(x!=1) { int p=pmn[x],cur=0; while(x%p==0) ++cur,x/=p; if(cur==cnt[p]&&times[p]==1) return true; } return false; }

int solve() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;

	REP(i,n) b[i]=a[i]; sort(b,b+n); reverse(b,b+n);

	memset(cnt,0,sizeof(cnt)); memset(times,0,sizeof(times)); nc=0; bool extra=false;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&b[l]==b[r]) ++r;
		int p=b[l],cur=r-l;
		if(cnt[p]==0) {
			if(cur>=1) mark(p),c[nc++]=p;
			if(cur>=2) mark(p-1),c[nc++]=p-1;
			if(cur>=3) extra=true;
		} else {
			if(cur>=1) mark(p-1),c[nc++]=p-1;
			if(cur>=2) extra=true;
		}
	}
	REP(i,nc) if(!isneeded(c[i])) extra=true;

	int ret=1; FORE(i,2,MAXVAL) REP(j,cnt[i]) ret=(ll)ret*i%MOD; if(extra) ret=(ret+1)%MOD; return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

void research1() {
	vector<bool> isp(1001,true); isp[0]=isp[1]=false;
	REPSZ(i,isp) if(isp[i]) for(int j=i+i;j<SZ(isp);j+=i) isp[j]=false;
	REPSZ(i,isp) if(isp[i]) {
		int p=i;
		set<pair<int,int>> can;
		REP(a,p) REP(b,p) REP(c,p) {
			vector<int> seen(p,-1); int t=0,x=c;
			while(seen[x]==-1) { seen[x]=t; x=((ll)x*a+b)%p; ++t; }
			can.insert(MP(t-seen[x],seen[x]));
		}
		printf("%d:",p); for(auto it=can.begin();it!=can.end();++it) { int per=it->first,lead=it->second; if(lead==0&&(per==p||(p-1)%per==0)) continue; if(lead==1&&per==1) continue; printf(" %d",per); if(lead!=0) printf("[%d]",lead); } puts("");
	}
}

void research2() {
	int p1=3,p2=2,p3=2;
	set<int> can;
	REP(a1,p1) REP(b1,p1) REP(c1,p1) REP(a2,p2) REP(b2,p2) REP(c2,p2) REP(a3,p3) REP(b3,p3) REP(c3,p3) {
		vector<int> cur(3); cur[0]=c1,cur[1]=c2,cur[2]=c3;
		set<vector<int>> seen; int nseen=0;
		while(!seen.count(cur)) { seen.insert(cur); ++nseen; cur[0]=((ll)cur[0]*a1+b1)%p1; cur[1]=((ll)cur[1]*a2+b2)%p2; cur[2]=((ll)cur[2]*a3+b3)%p3;  }
		if(!can.count(nseen)) { can.insert(nseen); printf("%d (%d,%d,%d) (%d,%d,%d) (%d,%d,%d)\n",nseen,a1,b1,c1,a2,b2,c2,a3,b3,c3); }
	}
}

int main() {
	//research1();
	//research2();
	run();
	return 0;
}