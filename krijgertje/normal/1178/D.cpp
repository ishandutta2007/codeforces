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

const int MAXN=1000;

bool isp[2*MAXN+1];
int n;
vector<pair<int,int>> ans;


void solve() {
	REPE(i,2*MAXN) isp[i]=true; isp[0]=isp[1]=false;
	REPE(i,2*MAXN) if(isp[i]) for(int j=i+i;j<=2*MAXN;j+=i) isp[j]=false;

	int x=n; while(x<=2*MAXN&&!isp[x]) ++x;
	assert(x<=2*MAXN); assert(x-n<=n/2);
	REP(i,n) ans.PB(MP(i,(i+1)%n));
	REP(i,x-n) ans.PB(MP(i,i+n/2));
}

void run() {
	scanf("%d",&n);
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	run();
	return 0;
}