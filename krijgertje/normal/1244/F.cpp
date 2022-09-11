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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n,nops;
char s[MAXN+1];
char ans[MAXN+1];

bool black[MAXN];
bool isfixed[MAXN];
vector<pair<int,int>> alt;

void solve() {
	REP(i,n) black[i]=s[i]=='B';
	REP(i,n) isfixed[i]=s[(i+n-1)%n]==s[i]||s[(i+1)%n]==s[i];

	int cntfixed=0; REP(i,n) if(isfixed[i]) ++cntfixed;
	if(cntfixed==0) { 
		if(nops%2==1) REP(i,n) black[i]=!black[i];
	} else {
		alt.clear();
		REP(i,n) if(!isfixed[i]&&isfixed[(i+n-1)%n]) {
			int l=i,r=i; while(!isfixed[(r+1)%n]) ++r;
			alt.PB(MP(l,r));
		}
		REPSZ(i,alt) {
			int l=alt[i].first,r=alt[i].second,len=r-l+1;
			//printf("alt of length %d\n",len);
			if(2*nops>=len) {
				FORE(j,l,r) black[j%n]=j-l<=r-j?black[(l+n-1)%n]:black[(r+1)%n];
			} else {
				REP(j,nops) black[(l+j)%n]=black[(l+n-1)%n];
				REP(j,nops) black[(r-j+n)%n]=black[(r+1)%n];
				if(nops%2==1) FORE(j,l+nops,r-nops) black[j%n]=!black[j%n];
			}
		}
	}

	REP(i,n) ans[i]=black[i]?'B':'W'; ans[n]='\0';
}

void run() {
	scanf("%d%d",&n,&nops);
	scanf("%s",s); assert(strlen(s)==n);
	solve();
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}