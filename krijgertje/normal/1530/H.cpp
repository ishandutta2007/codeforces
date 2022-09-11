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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 15000;

int n;
int a[MAXN];

struct MNBIT {
	int n; vector<int> val;
	void init(int _n) { n=_n; val=vector<int>(n+1,INT_MAX); }
	void mod(int idx,int by) { ++idx; while(idx>0) { val[idx]=min(val[idx],by); idx-=idx&-idx; } }
	int get(int idx) { ++idx; int ret=INT_MAX; while(idx<=n) { ret=min(ret,val[idx]); idx+=idx&-idx; } return ret; }
};
MNBIT mnbit;
struct MXBIT {
	int n; vector<int> val;
	void init(int _n) { n=_n; val=vector<int>(n+1,INT_MIN); }
	void mod(int idx,int by) { ++idx; while(idx<=n) { val[idx]=max(val[idx],by); idx+=idx&-idx; } }
	int get(int idx) { ++idx; int ret=INT_MIN; while(idx>0) { ret=max(ret,val[idx]); idx-=idx&-idx; } return ret; }
};
MXBIT mxbit;

int solve() {
	// [lval,rval,side,len] -> side=L: [lval,len,min rval] + side=R [rval,len,max lval]
	int ret=0;
	REP(dummy,2) {
		int len=1;
		vector<int> ldp(n,INT_MAX),rdp(n,INT_MIN);
		if(dummy==0) ldp[n-1]=rdp[n-1]=a[n-1];
		if(dummy==1) REP(i,n-1) ldp[i]=rdp[i]=a[i];
		while(true) {
			vector<int> nldp(n,INT_MAX),nrdp(n,INT_MIN);
			vector<vector<pair<int,int>>> emn(n),emx(n);
			REP(i,n) {
				if(ldp[i]!=INT_MAX) {
					if(i-1>=0) emn[i-1].PB(MP(a[i]-1,ldp[i]));
					//REP(j,i) if(a[j]<a[i]) nldp[j]=min(nldp[j],ldp[i]);
					if(i-(len-1+dummy)-1>=0) emx[i-(len-1+dummy)-1].PB(MP(ldp[i]+1,a[i]));
					//REP(j,i-(len-1+dummy)) if(a[j]>ldp[i]) nrdp[j]=max(nrdp[j],a[i]);
				}
				if(rdp[i]!=INT_MIN) {
					if(i-(len-1+dummy)-1>=0) emn[i-(len-1+dummy)-1].PB(MP(rdp[i]-1,a[i]));
					//REP(j,i-(len-1+dummy)) if(a[j]<rdp[i]) nldp[j]=min(nldp[j],a[i]);
					if(i-1>=0) emx[i-1].PB(MP(a[i]+1,rdp[i]));
					//REP(j,i) if(a[j]>a[i]) nrdp[j]=max(nrdp[j],rdp[i]);
				}
			}
			mnbit.init(n);
			for(int i=n-1;i>=0;--i) {
				for(auto z : emn[i]) mnbit.mod(z.first,z.second);
				nldp[i]=mnbit.get(a[i]);
			}
			mxbit.init(n);
			for(int i=n-1;i>=0;--i) {
				for(auto z : emx[i]) mxbit.mod(z.first,z.second);
				nrdp[i]=mxbit.get(a[i]);
			}
			bool any=false; REP(i,n) if(nldp[i]!=INT_MAX||nrdp[i]!=INT_MIN) any=true; if(!any) break;
			ldp=nldp,rdp=nrdp,++len;
		}
		ret=max(ret,len);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	printf("%d\n",solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}