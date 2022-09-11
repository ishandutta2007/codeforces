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

const int MAXLEN=100000;
const int MAXPERM=10;

int len,nperm;
int p[MAXPERM][MAXLEN];

int r[MAXPERM][MAXLEN];
int common[MAXPERM];

ll solve() {
	REP(i,nperm) REP(j,len) r[i][p[i][j]]=j;
	FOR(i,1,nperm) common[i]=0;
	ll ret=0;
	REP(k,len) {
		FOR(i,1,nperm) {
			common[i]=max(1,common[i]-1);
			while(k+common[i]<len&&r[i][p[0][k+common[i]]]==r[i][p[0][k]]+common[i]) ++common[i];
		}
		int mn=len-k; FOR(i,1,nperm) mn=min(mn,common[i]); ret+=mn;
	}
	return ret;
}

void run() {
	scanf("%d%d",&len,&nperm);
	REP(i,nperm) REP(j,len) scanf("%d",&p[i][j]),--p[i][j];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}