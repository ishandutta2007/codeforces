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

const int MAXQ=500000;
const int MAXH=2000;
const int MAXW=2000;
typedef bitset<MAXW> bs;

int h,w,nq;
int qx[MAXQ],ql[MAXQ],qr[MAXQ];
vector<int> ans[MAXQ];

bs pref[MAXW+1];

bs blue[MAXH];
int cnt[MAXH];
set<pair<int,int>> ordered;
vector<int> res[MAXH];
set<int> who;

void upd(int x,vector<int> val) {
	if(SZ(res[x])!=0) who.erase(x);
	res[x]=val;
	if(SZ(res[x])!=0) who.insert(x);
}
vector<int> calc(int ax,int bx) { // #bits in ax<=#bits in bx
	bs ares=blue[ax]&(~blue[bx]);
	int ay=ares._Find_first();
	if(ay==MAXW) return vector<int>();
	bs bres=blue[bx]&(~blue[ax]);
	int by=bres._Find_first();
	//printf("ax=%d bx=%d -> ay=%d by=%d\n",ax,bx,ay,by);
	assert(by!=MAXW&&by!=ay);
	int lx=min(ax,bx),hx=max(ax,bx),ly=min(ay,by),hy=max(ay,by);
	vector<int> ret; ret.PB(lx); ret.PB(ly); ret.PB(hx); ret.PB(hy); return ret;
}

void solve() {
	REPE(y,w) if(y==0) pref[y].reset(); else pref[y]=pref[y-1],pref[y].set(y-1);

	ordered.clear(); who.clear();
	REP(x,h) blue[x].reset(),cnt[x]=0,ordered.insert(MP(cnt[x],x));
	for(auto it=ordered.begin();it!=ordered.end();++it) {
		int x=it->second;
		if(next(it)==ordered.end()) upd(x,vector<int>()); else upd(x,calc(x,next(it)->second));
	}
	REP(i,nq) {
		int x=qx[i],l=ql[i],r=qr[i];
		auto it=ordered.find(MP(cnt[x],x)); assert(it!=ordered.end());
		if(it!=ordered.begin()) {
			auto pit=prev(it); int px=pit->second;
			if(next(it)==ordered.end()) upd(px,vector<int>()); else upd(px,calc(px,next(it)->second));
		}
		ordered.erase(it);
		bs mask=pref[r+1]^pref[l];
		blue[x]^=mask;
		cnt[x]=blue[x].count();
		ordered.insert(MP(cnt[x],x));
		it=ordered.find(MP(cnt[x],x)); assert(it!=ordered.end());
		if(it!=ordered.begin()) {
			auto pit=prev(it); int px=pit->second;
			upd(px,calc(px,x));
		}
		if(next(it)==ordered.end()) upd(x,vector<int>()); else upd(x,calc(x,next(it)->second));
		if(SZ(who)!=0) ans[i]=res[*who.begin()];
	}
}

void run() {
	scanf("%d%d%d",&h,&w,&nq);
	REP(i,nq) scanf("%d%d%d",&qx[i],&ql[i],&qr[i]),--qx[i],--ql[i],--qr[i];
	solve();
	REP(i,nq) if(SZ(ans[i])==0) printf("-1\n"); else { REPSZ(j,ans[i]) { if(j!=0) printf(" "); printf("%d",ans[i][j]+1); } puts(""); }
}

int main() {
	run();
	return 0;
}