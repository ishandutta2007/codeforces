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

const int MAXN=500;

int n;
int deglim[MAXN];

int one[MAXN],none;
int mult[MAXN],nmult;

int ndiam;
vector<pair<int,int>> e;

bool solve() {
	none=nmult=0;
	REP(i,n) if(deglim[i]==1) one[none++]=i;
	REP(i,n) if(none<2&&deglim[i]>1) deglim[i]=1,one[none++]=i;
	REP(i,n) if(deglim[i]>1) mult[nmult++]=i;
	ll multsum=0; REP(i,nmult) multsum+=deglim[mult[i]];
	if(nmult==0) return false;

	int need=none+2*(nmult-1);
	if(multsum<need) return false;

	ndiam=nmult+1;
	e.clear(); FOR(i,1,nmult) e.PB(MP(mult[i-1],mult[i]));
	e.PB(MP(one[0],mult[0])); e.PB(MP(one[1],mult[nmult-1]));
	int at=2; REP(i,nmult) { int cur=mult[i],rem=deglim[cur]-2; while(rem>0&&at<none) e.PB(MP(cur,one[at++])),--rem; } assert(at==none);
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&deglim[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES %d\n",ndiam);
	printf("%d\n",SZ(e));
	REPSZ(i,e) printf("%d %d\n",e[i].first+1,e[i].second+1);

}

int main() {
	run();
	return 0;
}