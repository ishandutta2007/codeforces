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

const int MAXLEVEL=100000;
const int MAXPROB=100000;

int nlevel,nprob;
int level[MAXPROB];
bool ans[MAXPROB];

int cnt[MAXLEVEL];
int freq[MAXPROB+1];

void solve() {
	REP(i,nlevel) cnt[i]=0;
	REPE(i,nprob) freq[i]=0;
	REP(i,nlevel) ++freq[cnt[i]];
	REP(i,nprob) {
		int x=level[i];
		++cnt[x];
		int y=cnt[x];
		++freq[y];
		ans[i]=freq[y]==nlevel;
	}
}

void run() {
	scanf("%d%d",&nlevel,&nprob);
	REP(i,nprob) scanf("%d",&level[i]),--level[i];
	solve();
	REP(i,nprob) printf("%d",ans[i]?1:0); puts("");
}

int main() {
	run();
	return 0;
}