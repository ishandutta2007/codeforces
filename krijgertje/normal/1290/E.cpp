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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 150000;

#define LC x+1
#define RC x+2*(m-l+1)
struct SegtreeBeatsMin {
	int n,lim; vector<int> maxval,maxval2; vector<int> maxcnt;
	vector<bool> ischanged; vector<int> changes; vector<int> changedby;
	
	void logchange(int val,int by) { if(val==-1) return; if(!ischanged[val]) ischanged[val]=true,changes.PB(val); changedby[val]+=by; }
	void sapplymin(int x,int val,bool log) { if(val>=maxval[x]) return; assert(val>maxval2[x]); if(log) logchange(maxval[x],-maxcnt[x]); maxval[x]=val; if(log) logchange(maxval[x],+maxcnt[x]); }
	void spush(int x,int l,int m,int r) { sapplymin(LC,maxval[x],false); sapplymin(RC,maxval[x],false); }
	void spull(int x,int l,int m,int r) { maxval[x]=max(maxval[LC],maxval[RC]); maxval2[x]=max(maxval[LC]!=maxval[x]?maxval[LC]:maxval2[LC],maxval[RC]!=maxval[x]?maxval[RC]:maxval2[RC]); maxcnt[x]=(maxval[LC]==maxval[x]?maxcnt[LC]:0)+(maxval[RC]==maxval[x]?maxcnt[RC]:0); }
	
	void sinit(int x,int l,int r) {
		if(l==r) { maxval[x]=-1,maxval2[x]=INT_MIN,maxcnt[x]=1; } else { int m=l+(r-l)/2; sinit(LC,l,m); sinit(RC,m+1,r); spull(x,l,m,r); }
	}
	void sset(int x,int l,int r,int IDX,int VAL) {
		if(l==r) { logchange(maxval[x],-maxcnt[x]); maxval[x]=VAL,maxval2[x]=INT_MIN,maxcnt[x]=1; logchange(maxval[x],+maxcnt[x]); } else { int m=l+(r-l)/2; spush(x,l,m,r); if(IDX<=m) sset(LC,l,m,IDX,VAL); else sset(RC,m+1,r,IDX,VAL); spull(x,l,m,r); }
	}
	void smin(int x,int l,int r,int L,int R,int VAL) {
		if(VAL>=maxval[x]) return;
		if(L<=l&&r<=R&&VAL>maxval2[x]) { sapplymin(x,VAL,true); } else { int m=l+(r-l)/2; spush(x,l,m,r); if(L<=m) smin(LC,l,m,L,R,VAL); if(m+1<=R) smin(RC,m+1,r,L,R,VAL); spull(x,l,m,r); }
	}
	
	void init(int _n,int _lim) { n=_n,lim=_lim; maxval=maxval2=vector<int>(2*n-1); maxcnt=vector<int>(2*n-1); sinit(0,0,n-1); ischanged=vector<bool>(lim,false); changes=vector<int>(); changedby=vector<int>(lim,0); }
	void set(int idx,int val) { sset(0,0,n-1,idx,val); }
	void minrange(int lidx,int ridx,int val) { smin(0,0,n-1,lidx,ridx,val); }
	void reset() { REPSZ(i,changes) { int val=changes[i]; ischanged[val]=false; changedby[val]=0; } changes.clear(); }
};
#undef LC
#undef RC


struct BIT {
	int n; vector<ll> bit; ll sum;
	void init(int _n) { n=_n; bit=vector<ll>(n,0); sum=0; }
	void add(int idx,ll val) { sum+=val; while(idx<n) { bit[idx]+=val; idx|=idx+1; } }
	ll prefixsum(int idx) { ll ret=0; while(idx>=0) { ret+=bit[idx]; idx=(idx&(idx+1))-1; } return ret; }
	ll suffixsum(int idx) { return sum-prefixsum(idx-1); }
};

int n;
int val[MAXN];
ll ans[MAXN];

int pos[MAXN];

SegtreeBeatsMin leftseg; set<int> leftset; // for each position at which a node starts, keep rightmost point in segment tree
BIT alivebit; set<int> aliveset; // which indices are alive
BIT freq; // frequency in which prefixes are counted towards the answer



void solvermax() {
	leftseg.init(n,n); leftset.clear();
	alivebit.init(n); aliveset.clear();
	freq.init(n);
	ll sum=0;
	int fst=-1,lst=-1;
	REP(v,n) {
		int idx=pos[v];
		alivebit.add(idx,1); aliveset.insert(idx);
		sum+=freq.suffixsum(idx);
		if(fst==-1||idx<fst) {
			fst=idx;
			if(fst!=0) freq.add(fst-1,-1),sum-=alivebit.prefixsum(fst-1),leftset.insert(fst);
			if(lst==-1) lst=idx;
		} else {
			auto it=aliveset.find(idx);
			int prv=*prev(it);
			leftseg.minrange(0,prv,prv);
			if(idx>lst) {
				lst=idx;
			} else {
				int nxt=*next(it);
				leftseg.set(nxt,lst);
				if(leftset.find(nxt)==leftset.end()) freq.add(nxt-1,-1),sum-=alivebit.prefixsum(nxt-1),leftset.insert(nxt);
			}
		}
		leftseg.set(fst,lst);
		REPSZ(i,leftseg.changes) {
			int val=leftseg.changes[i],by=leftseg.changedby[val];
			//printf("\tchange %d by %d\n",val,by);
			freq.add(val,by),sum+=(ll)by*alivebit.prefixsum(val);
		}
		leftseg.reset();
		//printf("v=%d idx=%d: sum=%lld\n",v,idx,sum);
		ans[v]+=sum;
	}
	
}

void solve() {
	REP(i,n) pos[val[i]]=i;
	REP(i,n) ans[i]=0;
	REP(kind,2) {
		solvermax();
		REP(i,n) pos[i]=n-pos[i]-1;
	}
	REP(i,n) ans[i]-=i+1;
}

void run() {
	scanf("%d", &n);
	REP(i,n) scanf("%d", &val[i]), --val[i];
	solve();
	REP(i,n) printf("%lld\n",ans[i]);
}

int main() {
	run();
	return 0;
}