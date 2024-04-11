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

const int MAXQ=500000;

int nq;
char qkind[MAXQ]; int qval[MAXQ],qans[MAXQ];

int a[MAXQ],na; // distinct values

int sum;
int cnt[MAXQ];
set<int> have; // all values we currently have
set<int> opt;  // all values such that two times the previous value is smaller than it

ll bit[MAXQ+1];
ll bget(int idx) { ++idx; ll ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=na) { bit[idx]+=by; idx+=idx&-idx; } }

void solve() {
	na=0; REP(i,nq) a[na++]=qval[i]; sort(a,a+na); na=unique(a,a+na)-a;

	have.clear(); opt.clear(); sum=0; REP(i,na) cnt[i]=0; REPE(i,na) bit[i]=0;
	REP(i,nq) {
		int idx=lower_bound(a,a+na,qval[i])-a;
		if(qkind[i]=='+') {
			++sum,++cnt[idx]; bmod(idx,+a[idx]);
			if(cnt[idx]==1) {
				have.insert(idx);
				auto it=have.find(idx); assert(it!=have.end());
				if(it!=have.begin()) {
					int pidx=*prev(it);
					if(2*a[pidx]<a[idx]) opt.insert(idx);
				}
				if(next(it)!=have.end()) {
					int nidx=*next(it);
					if(it==have.begin()) {
						if(2*a[idx]<a[nidx]) opt.insert(nidx);
					} else {
						int pidx=*prev(it);
						if(2*a[pidx]<a[nidx]&&2*a[idx]>=a[nidx]) opt.erase(nidx);
					}
				}
			}
		} else {
			--sum,--cnt[idx]; bmod(idx,-a[idx]);
			if(cnt[idx]==0) {
				auto it=have.find(idx); assert(it!=have.end());
				if(it!=have.begin()) {
					int pidx=*prev(it);
					if(2*a[pidx]<a[idx]) opt.erase(idx);
				}
				if(next(it)!=have.end()) {
					int nidx=*next(it);
					if(it==have.begin()) {
						if(2*a[idx]<a[nidx]) opt.erase(nidx);
					} else {
						int pidx=*prev(it);
						if(2*a[pidx]<a[nidx]&&2*a[idx]>=a[nidx]) opt.insert(nidx);
					}
				}
				have.erase(it);
			}
		}
		//printf("opt:"); for(auto it=opt.begin();it!=opt.end();++it) printf(" %d",a[*it]); puts("");
		qans[i]=max(0,sum-1); for(auto it=opt.begin();it!=opt.end();++it) { int idx=*it; if(2*bget(idx-1)<a[idx]) --qans[i]; }
	}

}

void run() {
	scanf("%d",&nq);
	REP(i,nq) scanf(" %c%d",&qkind[i],&qval[i]);
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}