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

int n,mod;
int a[MAXN];

int b[MAXN];
int c[MAXN];
int kmp[MAXN+1];

int ret[MAXN],nret;

void solve() {
	REP(i,n-1) b[i]=a[i+1]-a[i]; b[n-1]=mod+a[0]-a[n-1];
	REP(i,n) c[i]=b[i]; reverse(c,c+n);
	kmp[0]=kmp[1]=0; FORE(i,2,n) { int cur=kmp[i-1]; while(cur!=0&&b[i-1]!=b[cur]) cur=kmp[cur]; if(b[i-1]==b[cur]) ++cur; kmp[i]=cur; }
	int at=0;
	REP(i,n) { while(at!=0&&c[i]!=b[at]) at=kmp[at]; if(c[i]==b[at]) ++at; }
	nret=0;
	REP(i,n) {
		if(at==n) ret[nret++]=(a[0]+a[(n-i)%n])%mod,at=kmp[at];
		while(at!=0&&c[i]!=b[at]) at=kmp[at]; if(c[i]==b[at]) ++at;
	}
	sort(ret,ret+nret);
}

void run() {
	scanf("%d%d",&n,&mod);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",nret); if(nret>0) { REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts(""); }
}

int main() {
	run();
	return 0;
}