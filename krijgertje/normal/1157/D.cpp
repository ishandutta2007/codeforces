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

const int MAXLEN=100000;

int wantsum,len;
int ans[MAXLEN];

int delta[MAXLEN];

bool solve() {
	REP(i,len) delta[i]=1;
	ll havesum=0; REP(i,len) havesum+=i+1;
	if(havesum>wantsum) return false;
	int prev=0;
	REP(i,len) {
		int each=len-i;
		int rem=wantsum-havesum;
		int nfull=rem/each; if(prev!=0) nfull=min(nfull,prev-1);
		delta[i]+=nfull; havesum+=nfull*each; rem-=nfull*each;
		if((prev==0||nfull<prev-1)&&len-rem>1||delta[0]!=1) { assert(rem<each); ++delta[len-rem]; havesum+=rem; rem-=rem; }
		prev+=delta[i];
	}
	if(havesum!=wantsum) return false;

	REP(i,len) ans[i]=(i==0?0:ans[i-1])+delta[i];
}

void run() {
	scanf("%d%d",&wantsum,&len);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,len) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}