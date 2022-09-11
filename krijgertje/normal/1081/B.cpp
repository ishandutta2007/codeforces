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

int n;
int a[MAXN];
int ans[MAXN];

pair<int,int> o[MAXN];

bool solve() {
	REP(i,n) o[i]=MP(a[i],i);
	sort(o,o+n);
	int ncol=0;
	REP(i,n) ans[i]=-1;
	for(int l=0,r=l;l<n;l=r) {
		int ndiff=o[l].first;
		while(r<n&&o[r].first==ndiff) ++r;
		int cnt=r-l,nsame=n-ndiff;
		if(cnt%nsame!=0) return false;
		REP(i,cnt/nsame) { int col=ncol++; REP(j,nsame) ans[o[l+i*nsame+j].second]=col; }
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("Impossible\n"); return; }
	printf("Possible\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}