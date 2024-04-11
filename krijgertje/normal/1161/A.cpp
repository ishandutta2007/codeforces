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
const int MAXQ=100000;

int n,nq;
int qx[MAXQ];

int fst[MAXN],lst[MAXN];

int solve() {
	REP(i,n) fst[i]=INT_MAX,lst[i]=INT_MIN;
	REP(i,nq) { int x=qx[i]; fst[x]=min(fst[x],i); lst[x]=max(lst[x],i); }
	int ret=0;
	REP(i,n) if(fst[i]==INT_MAX) ++ret;
	REP(i,n) for(int di=-1;di<=+1;di+=2) {
		int ii=i+di; if(ii<0||ii>=n) continue;
		if(fst[i]>lst[ii]) ++ret;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,nq) scanf("%d",&qx[i]),--qx[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}