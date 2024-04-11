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

const int MAXN=1000;

int n;

int horcross[MAXN-1];
int vercross[MAXN-1];

pair<int,int> ans[2];

int query(int lx,int ly,int hx,int hy) {
	printf("? %d %d %d %d\n",lx+1,ly+1,hx+1,hy+1); fflush(stdout);
	int ret; scanf("%d",&ret); return ret;
}

void solve() {
	REP(i,n-1) horcross[i]=query(0,0,i,n-1);
	REP(i,n-1) vercross[i]=query(0,0,n-1,i);

	int fsthorodd=-1; REP(i,n-1) if(horcross[i]%2==1) { fsthorodd=i; break; }
	int fstverodd=-1; REP(i,n-1) if(vercross[i]%2==1) { fstverodd=i; break; }
	assert(fsthorodd!=-1||fstverodd!=-1);
	vector<int> endx,endy;
	if(fsthorodd!=-1) {
		{ int x=fsthorodd; while(x-1>=0&&horcross[x-1]%2==1) --x; endx.PB(x); }
		{ int x=fsthorodd+1; while(x<n-1&&horcross[x]%2==1) ++x; endx.PB(x); }
	}
	if(fstverodd!=-1) {
		{ int y=fstverodd; while(y-1>=0&&vercross[y-1]%2==1) --y; endy.PB(y); }
		{ int y=fstverodd+1; while(y<n-1&&vercross[y]%2==1) ++y; endy.PB(y); }
	}
	sort(endx.begin(),endx.end()); sort(endy.begin(),endy.end());
	//printf("endx:"); REPSZ(i,endx) printf(" %d",endx[i]); puts("");
	//printf("endy:"); REPSZ(i,endy) printf(" %d",endy[i]); puts("");
	if(SZ(endx)==0) {
		assert(SZ(endy)==2);
		int lo=-1,hi=n-1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(query(0,0,mi,endy[0])%2==1) hi=mi; else lo=mi; }
		ans[0]=MP(hi,endy[0]); ans[1]=MP(hi,endy[1]); return;
	}
	if(SZ(endy)==0) {
		assert(SZ(endx)==2);
		int lo=-1,hi=n-1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(query(0,0,endx[0],mi)%2==1) hi=mi; else lo=mi; }
		ans[0]=MP(endx[0],hi); ans[1]=MP(endx[1],hi); return;
	}
	assert(SZ(endx)==2&&SZ(endy)==2);
	REPSZ(i,endx) REPSZ(j,endy) if(query(endx[i],endy[j],endx[i],endy[j])==1) { ans[0]=MP(endx[i],endy[j]); ans[1]=MP(endx[1-i],endy[1-j]); return; }
	assert(false);
}

void run() {
	scanf("%d",&n);
	solve();
	printf("! %d %d %d %d\n",ans[0].first+1,ans[0].second+1,ans[1].first+1,ans[1].second+1); fflush(stdout);
}

int main() {
	run();
	return 0;
}