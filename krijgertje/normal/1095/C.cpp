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

int n,want;

vector<int> ans;

bool solve() {
	if(want>n) return false;
	ans.clear();
	for(int i=0;(1LL<<i)<=n;++i) if(n&(1<<i)) ans.PB(1<<i);
	if(SZ(ans)>want) return false;
	REPSZ(i,ans) while(ans[i]>1&&SZ(ans)<want) { ans[i]/=2; ans.PB(ans[i]); }
	return true;
}

void run() {
	scanf("%d%d",&n,&want);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i,ans) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}