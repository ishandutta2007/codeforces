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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MOD=1000000007;
const int MAXLEN=3000;
const int MAXS=4*MAXLEN;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
struct SVal { int prefways[4]; int ways[4][4]; }; // ways[a][b]=#ways when taking a extra characters before the beginning and leaving b unused at the end

int len;
char s[MAXLEN+1];
int ans[MAXLEN];

bool isvalid[MAXLEN][5];
SVal sval[MAXS];

SVal smake(int pos) {
	SVal ret;
	REP(a,4) ret.prefways[a]=pos-a>=0&&isvalid[pos-a][a+1]?1:0;
	REP(a,4) REP(b,4) ret.ways[a][b]=pos-a<0||a+1-b<0?0:a+1-b==0?1:b==0&&isvalid[pos-a][a+1-b]?1:0;
	//printf("smake(%d):",pos); REP(a,4) printf(" %d",ret.prefways[a]); printf(" |"); REP(a,4) { if(a!=0) printf(","); REP(b,4) printf(" %d",ret.ways[a][b]); } puts("");
	return ret;
}
SVal smerge(const SVal &lft,const SVal &rgt) {
	SVal ret;
	REP(a,4) { ret.prefways[a]=lft.prefways[a]; REP(b,4) inc(ret.prefways[a],(ll)lft.ways[a][b]*rgt.prefways[b]%MOD); }
	REP(a,4) REP(b,4) { ret.ways[a][b]=0; REP(c,4) inc(ret.ways[a][b],(ll)lft.ways[a][c]*rgt.ways[c][b]%MOD); }
	//printf("smerge:\n");
	//printf("lft:"); REP(a,4) printf(" %d",lft.prefways[a]); printf(" |"); REP(a,4) { if(a!=0) printf(","); REP(b,4) printf(" %d",lft.ways[a][b]); } puts("");
	//printf("rgt:"); REP(a,4) printf(" %d",rgt.prefways[a]); printf(" |"); REP(a,4) { if(a!=0) printf(","); REP(b,4) printf(" %d",rgt.ways[a][b]); } puts("");
	//printf("ret:"); REP(a,4) printf(" %d",ret.prefways[a]); printf(" |"); REP(a,4) { if(a!=0) printf(","); REP(b,4) printf(" %d",ret.ways[a][b]); } puts("");
	return ret;
}

void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=smake(l);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=smerge(sval[2*x+1],sval[2*x+2]);
	}
}

SVal sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2;
		if(R<=m) return sget(2*x+1,l,m,L,R);
		if(m+1<=L) return sget(2*x+2,m+1,r,L,R);
		return smerge(sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R));
	}
}

int dplcp[MAXLEN+1][MAXLEN+1];

void solve() {
	reverse(s,s+len);
	REP(i,len) { int mask=0; REP(j,4) if(i+j>=len) isvalid[i][j+1]=false; else { mask|=(s[i+j]-'0')<<j; isvalid[i][j+1]=j+1<4||(mask!=3&&mask!=5&&mask!=14&&mask!=15); } }
	sinit(0,0,len-1);
	//REP(i,len) FOR(j,i,len) { int cur=sget(0,0,len-1,i,j).prefways[0]; printf("[%d..%d] = %d\n",i,j,cur); }
	
	REPE(j,MAXLEN) dplcp[len][j]=0;
	for(int i=len-1;i>=0;--i) REPE(j,MAXLEN) dplcp[i][j]=s[i]!=s[j]?0:1+dplcp[i+1][j+1];
	
	int sumways=0;
	REP(i,len) {
		int idx=len-i-1;
		int lcp=0; FOR(j,idx+1,len) lcp=max(lcp,dplcp[idx][j]);
		int addways=sget(0,0,len-1,idx,len-1).prefways[0];
		int subways=lcp==0?0:sget(0,0,len-1,idx,idx+lcp-1).prefways[0];
		//printf("%d-%d [lcp=%d]\n",addways,subways,lcp);
		inc(sumways,addways); inc(sumways,MOD-subways);
		ans[i]=sumways;
	}
	
}

void run() {
	scanf("%d",&len);
	REP(i,len) scanf(" %c",&s[i]); s[len]='\0';
	solve();
	REP(i,len) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}