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

const int MAXN=1000000;
const int MAXVAL=10000000;

int n;
int a[MAXN];
int ans[2];

vector<int> who[MAXVAL+1];

void solve() {
	REPE(i,MAXVAL) who[i].clear(); REP(i,n) who[a[i]].PB(i);
	ll best=LLONG_MAX;
	FORE(g,1,MAXVAL) {
		int fst=-1,fstidx=-1,snd=-1,sndidx=-1;
		for(int i=g;i<=MAXVAL;i+=g) {
			REPSZ(j,who[i]) {
				if(fst==-1) fst=i,fstidx=who[i][j]; else if(snd==-1) snd=i,sndidx=who[i][j];
				if(snd!=-1) break;
			}
			if(snd!=-1) break;
		}
		if(snd==-1) continue;
		ll cur=(ll)fst/g*snd; if(cur<best) best=cur,ans[0]=fstidx,ans[1]=sndidx;
	}
	if(ans[0]>ans[1]) swap(ans[0],ans[1]);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d %d\n",ans[0]+1,ans[1]+1);
}

int main() {
	run();
	return 0;
}