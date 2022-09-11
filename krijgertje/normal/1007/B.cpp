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

const int MAXV=100000;

int pmn[MAXV+1];
int dv[MAXV+1];
vector<vector<int>> opt;

int v[3];

bool ok(const vector<int> &cnt) {
	vector<int> lst; REPSZ(i,cnt) REP(j,cnt[i]) lst.PB(i); assert(SZ(lst)==3);
	REP(i,3) REP(j,3) REP(k,3) if(j!=i&&k!=i&&k!=j&&(lst[i]&1)!=0&&(lst[j]&2)!=0&&(lst[k]&4)!=0) return true;
	return false;
}

void gen(vector<int> &cnt,int at,int rem) {
	if(at>=SZ(cnt)) {
		if(rem==0&&ok(cnt)) opt.PB(cnt);
	} else {
		for(cnt[at]=0;cnt[at]<=rem;++cnt[at]) gen(cnt,at+1,rem-cnt[at]);
	}
}

void run() {
	scanf("%d%d%d",&v[0],&v[1],&v[2]);

	vector<int> cnt(8,0);
	FOR(mask,1,8) {
		int g=0; vector<int> forbidden; REP(i,3) if(mask&(1<<i)) g=gcd(g,v[i]); else forbidden.PB(i);
		REP(i,1<<SZ(forbidden)) { int num=0; int gg=g; REPSZ(j,forbidden) if(i&(1<<j)) ++num,gg=gcd(gg,v[forbidden[j]]); if(num%2==0) cnt[mask]+=dv[gg]; else cnt[mask]-=dv[gg]; }
	}
	//printf("cnt:"); REPSZ(i,cnt) printf(" %d",cnt[i]); puts("");

	ll ans=0;
	REPSZ(i,opt) {
		ll cur=1;
		REP(mask,8) {
			if(opt[i][mask]==1) cur*=cnt[mask];
			if(opt[i][mask]==2) cur*=(ll)cnt[mask]*(cnt[mask]+1)/2;
			if(opt[i][mask]==3) cur*=(ll)cnt[mask]*(cnt[mask]+1)*(cnt[mask]+2)/6;
		}
		ans+=cur;
	}
	printf("%lld\n",ans);
}

void precalc() {
	opt.clear();
	vector<int> cnt(8);
	gen(cnt,0,3);
	//printf("nopt=%d\n",SZ(opt)); REPSZ(i,opt) { printf("opt%d: ",i); REPSZ(j,opt[i]) printf("%d",opt[i][j]); puts(""); }

	REPE(i,MAXV) pmn[i]=-1;
	FORE(i,2,MAXV) if(pmn[i]==-1) for(int j=i;j<=MAXV;j+=i) if(pmn[j]==-1) pmn[j]=i;
	dv[1]=1; FORE(i,2,MAXV) { int p=pmn[i],num=0,j=i; while(j%p==0) j/=p,++num; dv[i]=(num+1)*dv[j]; }
	//printf("dv:"); FORE(i,1,40) printf(" %d",dv[i]); puts("");
}

int main() {
	precalc();
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}