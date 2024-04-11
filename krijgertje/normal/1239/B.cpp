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
#include <chrono>
#include <chrono>
#include <random>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300000;

int n;
char s[MAXN+1];
pair<int,int> ansop;

int bal[MAXN+1];

int solve() {
	bal[0]=0;
	REP(i,n) bal[i+1]=bal[i]+(s[i]=='('?+1:-1);
	if(bal[n]!=0) { ansop=MP(0,0); return 0; }
	
	int mn=bal[0]; REP(i,n) mn=min(mn,bal[i]);
	REP(i,n) bal[i]-=mn;
	
	int ret=0; ansop=MP(0,0);
	
	// keep ones
	REP(i,n) if(bal[i]==0) {
		int cnt=0;
		int j=i+1; while(true) { int val=bal[j%n]; if(val==0) break; if(val==1) ++cnt; ++j; }
		if(cnt>ret) { ret=cnt; ansop=MP(i,(j+n-1)%n); }
	}

	// keep all zeroes and possibly some twos
	int cntzero=0; REP(i,n) if(bal[i]==0) ++cntzero;
	if(cntzero>ret) { ret=cntzero; ansop=MP(0,0); }
	REP(i,n) if(bal[i]==2) {
		int cnt=cntzero+1;
		int j=i+1; while(true) { int val=bal[j%n]; if(val<2) break; if(val==2) ++cnt; ++j; }
		if(cnt>ret) { ret=cnt; ansop=MP((i+n-1)%n,(j+n-1)%n); }
	}
	
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	int ans=solve();
	printf("%d\n%d %d\n",ans,ansop.first+1,ansop.second+1);

}

int main() {
	run();
	return 0;
}