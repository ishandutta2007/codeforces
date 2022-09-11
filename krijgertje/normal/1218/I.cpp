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

const int MAXN=2000;

int n;
char a[MAXN][MAXN+1];
char b[MAXN][MAXN+1];
char c[MAXN+1];
vector<pair<int,int>> ans;

char d[MAXN][MAXN+1];

bool test() { REP(x,n) REP(y,n) if(d[x][y]!=b[x][y]) return false; return true; }
void docol(int y) { ans.PB(MP(1,y)); REP(x,n) if(c[x]=='1') d[x][y]='1'-(d[x][y]-'0'); }
void dorow(int x) { ans.PB(MP(0,x)); REP(y,n) if(c[y]=='1') d[x][y]='1'-(d[x][y]-'0'); }

bool solve() {
	int idx=-1; REP(i,n) if(c[i]=='1') { idx=i; break; }
	if(idx!=-1) {
		REP(rep,2) {
			ans.clear(); REP(x,n) REPE(y,n) d[x][y]=a[x][y];
			if(rep==1) dorow(idx);
			REP(y,n) if(d[idx][y]!=b[idx][y]) docol(y);
			REP(x,n) if(x!=idx&&d[x][idx]!=b[x][idx]) dorow(x);
			if(test()) return true;
		}
		return false;
	} else {
		ans.clear(); REP(x,n) REPE(y,n) d[x][y]=a[x][y];
		return test();
	}
}

void run() {
	scanf("%d",&n);
	REP(x,n) scanf("%s",a[x]);
	REP(x,n) scanf("%s",b[x]);
	scanf("%s",c);
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%s %d\n",ans[i].first==0?"row":"col",ans[i].second);
}

int main() {
	run();
	return 0;
}