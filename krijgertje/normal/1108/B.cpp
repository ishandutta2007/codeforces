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

const int MAXN=128;

int n;
int a[MAXN];

int b[MAXN],nb;
int c[MAXN],nc;

pair<int,int> solve() {
	nb=0; REP(i,n) b[nb++]=a[i]; sort(b,b+n);
	int l=b[nb-1];
	//printf("l=%d\n",l);
	nc=0; FORE(i,1,l) if(l%i==0) c[nc++]=i;
	//printf("c:"); REP(i,nc) printf(" %d",c[i]); puts("");
	{ int at=0,cnt=0; REP(i,nb) if(at<nc&&b[i]==c[at]) ++at; else b[cnt++]=b[i]; nb=cnt; assert(at==nc); }
	//printf("b:"); REP(i,nb) printf(" %d",b[i]); puts("");
	int r=b[nb-1];	
	//printf("r=%d\n",r);
	nc=0; FORE(i,1,r) if(r%i==0) c[nc++]=i;
	//printf("c:"); REP(i,nc) printf(" %d",c[i]); puts("");
	{ int at=0,cnt=0; REP(i,nb) if(at<nc&&b[i]==c[at]) ++at; else b[cnt++]=b[i]; nb=cnt; assert(at==nc); }
	//printf("b:"); REP(i,nb) printf(" %d",b[i]); puts("");
	assert(nb==0);
	return MP(l,r);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	pair<int,int> ans=solve();
	printf("%d %d\n",ans.first,ans.second);
}

int main() {
	run();
	return 0;
}