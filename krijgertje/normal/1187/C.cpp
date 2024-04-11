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

const int MAXN=1000;
const int MAXFACT=1000;

int n,nfact;
int factkind[MAXFACT],factl[MAXFACT],factr[MAXFACT];
int ans[MAXN];

int same[MAXN];

bool solve() {
	REP(i,n) same[i]=i;
	REP(i,nfact) if(factkind[i]==1) {
		int l=factl[i],r=factr[i];
		FORE(j,l+1,r) if(same[j]!=same[l]) {
			int at=j,old=same[j]; while(at<n&&same[at]==old) same[at]=same[l],++at;
		}
	}
	//printf("same:"); REP(i,n) printf(" %d",same[i]); puts("");
	REP(i,nfact) if(factkind[i]==0) {
		int l=factl[i],r=factr[i];
		if(same[l]==same[r]) return false;
	}
	int nxt=1; for(int i=n-1;i>=0;--i) if(i+1>=n||same[i+1]!=same[i]) ans[i]=nxt++; else ans[i]=ans[i+1]; return true;
}

void run() {
	scanf("%d%d",&n,&nfact);
	REP(i,nfact) scanf("%d%d%d",&factkind[i],&factl[i],&factr[i]),--factl[i],--factr[i];
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}