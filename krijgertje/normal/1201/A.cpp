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

const int MAXSTUD=1000;
const int MAXQUEST=1000;

int nstud,nquest;
char answer[MAXSTUD][MAXQUEST+1];
int score[MAXQUEST];

int cnt[5];

ll solve() {
	ll ret=0;
	REP(i,nquest) {
		REP(j,5) cnt[j]=0;
		REP(j,nstud) ++cnt[answer[j][i]-'A'];
		int mx=0; REP(j,5) mx=max(mx,cnt[j]);
		ret+=(ll)mx*score[i];
	}
	return ret;
}

void run() {
	scanf("%d%d",&nstud,&nquest);
	REP(i,nstud) scanf("%s",answer[i]);
	REP(i,nquest) scanf("%d",&score[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}