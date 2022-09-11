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

const int MAXN=100000;

int n,mxdepth,MOD;

int INV2;
int inv[2*MAXN+1];

vector<int> parts;
void rec(int l,int r,int h) {
	if(l>r) return;
	if(h==1||l==r) { parts.PB(r-l+1); return; }
	int m=(l+r)/2;
	rec(l,m,h-1); rec(m+1,r,h-1);
}

// 196396217

int cntpairs(int sz) { return (ll)sz*(sz-1)/2%MOD; }
int calc(int sz) { return (ll)cntpairs(sz)*INV2%MOD; }
int calc(int sza,int szb) {
	int ret=0;
	FORE(den,2,sza+szb) { int lo=max(1,den-szb),hi=min(sza,den-1),cnt=hi-lo+1; if(lo>hi) continue; int cur=(ll)(den-2)%MOD*inv[den]%MOD*INV2%MOD; ret=(ret+(ll)cnt*cur)%MOD; }
	return ret;
}

int solve() {
	INV2=(MOD+1)/2;
	inv[1]=1; FORE(i,2,2*n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;

	parts.clear();
	rec(1,n,mxdepth);
	//printf("parts:"); REPSZ(i,parts) printf(" %d",parts[i]); puts("");
	
	int sz1=-1,cnt1=0,sz2=-1,cnt2=0;
	REPSZ(i,parts) { int x=parts[i]; if(x==sz1) ++cnt1; else if(x==sz2) ++cnt2; else if(sz1==-1) sz1=x,++cnt1; else if(sz2==-1) sz2=x,++cnt2; else assert(false); }
	//printf("%d times %d and %d times %d\n",cnt1,sz1,cnt2,sz2);

	int ret=0;
	if(cnt1!=0) ret=(ret+(ll)cnt1*calc(sz1))%MOD;
	if(cnt2!=0) ret=(ret+(ll)cnt2*calc(sz2))%MOD;

	if(cnt1!=0) ret=(ret+(ll)cntpairs(cnt1)*calc(sz1,sz1))%MOD;
	if(cnt1!=0&&cnt2!=0) ret=(ret+(ll)cnt1*cnt2%MOD*calc(sz1,sz2))%MOD;
	if(cnt2!=0) ret=(ret+(ll)cntpairs(cnt2)*calc(sz2,sz2))%MOD;
	
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&mxdepth,&MOD);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}