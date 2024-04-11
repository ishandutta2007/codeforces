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

int n;
int a[MAXN];

int side[MAXN];

vector<int> factorize(int x) { vector<int> ret; for(int i=2;(ll)i*i<=x;++i) if(x%i==0) { ret.PB(i); while(x%i==0) x/=i; } if(x!=1) ret.PB(x); return ret; }


vector<int> nxt[MAXN+1];
vector<int> pl,pr,pall;

bool rec(int mask,int at) {
	//printf("rec(%d,%d)\n",mask,at);
	if(mask==0) return true;
	int pos=n; REPSZ(i,pall) if((mask&(1<<i))!=0&&nxt[at][i]!=-1) pos=min(pos,nxt[at][i]); if(pos==n) return false;
	int lmask=mask,rmask=mask;
	REPSZ(i,pl) if(a[pos]%pl[i]!=0&&(lmask&(1<<i))!=0) lmask^=1<<i;
	REPSZ(i,pr) if(a[pos]%pr[i]!=0&&(rmask&(1<<(SZ(pl)+i)))!=0) rmask^=1<<(SZ(pl)+i);
	//printf("rec(%d,%d) -> pos=%d, lmask=%d, rmask=%d\n",mask,at,pos,lmask,rmask);
	if(lmask!=mask) { side[pos]=1; if(rec(lmask,pos+1)) return true; side[pos]=0; }
	if(rmask!=mask) { side[pos]=2; if(rec(rmask,pos+1)) return true; side[pos]=0; }
	return false;
}

bool tryfixed(int l,int r,int sofar) {
	//printf("tryfixed(%d,%d,%d)\n",l,r,sofar);
	pl=factorize(l);
	pr=factorize(r);
	pall.clear(); REPSZ(i,pl) pall.PB(pl[i]); REPSZ(i,pr) pall.PB(pr[i]);

	nxt[n]=vector<int>(SZ(pall),-1); for(int i=n-1;i>=sofar;--i) { nxt[i]=nxt[i+1]; REPSZ(j,pall) if(a[i]%pall[j]!=0) nxt[i][j]=i; }
	int cur=(1<<SZ(pall))-1;
	return rec(cur,sofar);
}


bool solve() {
	REP(i,n) side[i]=0;
	int l=a[0],r=0; side[0]=1;
	vector<int> p=factorize(a[0]);
	FOR(i,1,n) {
		bool ok=false; REPSZ(j,p) if(l%p[j]==0&&a[i]%p[j]!=0) ok=true;
		if(!ok) { side[i]=2; r=gcd(r,a[i]); continue; }
		side[i]=2; if(tryfixed(l,gcd(r,a[i]),i+1)) { REP(j,n) if(side[j]==0) side[j]=1; return true; }
		side[i]=1; l=gcd(l,a[i]);
	}
	return l==1&&r==1;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",side[i]); } puts("");
}

int main() {
	run();
	return 0;
}