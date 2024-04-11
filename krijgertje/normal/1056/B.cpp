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

const int MAXFRIEND=1000;

int sz,nfriend;

int cnt[MAXFRIEND];

ll solve() {
	REP(i,nfriend) cnt[i]=i>sz?0:(sz-i+nfriend)/nfriend; --cnt[0];
	//printf("cnt:"); REP(i,nfriend) printf(" %d",cnt[i]); puts("");
	ll ret=0;
	REP(i,nfriend) REP(j,nfriend) if((i*i+j*j)%nfriend==0) ret+=(ll)cnt[i]*cnt[j];
	return ret;
}

void run() {
	scanf("%d%d",&sz,&nfriend);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}