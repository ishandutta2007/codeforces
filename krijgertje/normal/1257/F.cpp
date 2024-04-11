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

const int MAXN=100;
const int MAXBITS=30;

int n;
int a[MAXN];

vector<vector<int>> all;
vector<vector<int>> sorted;

int solve() {
	int x1=MAXBITS/2,x2=MAXBITS-x1;
	all.clear();
	REP(mask,1<<x1) {
		vector<int> diff(n-1); int fst;
		REP(i,n) {
			int cnt=0;
			REP(k,x1) { int cur=((a[i]>>k)^(mask>>k))&1; cnt+=cur; }
			if(i==0) fst=cnt; else diff[i-1]=cnt-fst;
		}
		//printf("%x:",mask); REPSZ(k,diff) printf(" %d",diff[k]); printf(" [%d]\n",fst);
		REPSZ(k,diff) diff[k]=-diff[k];
		all.PB(diff);
	}
	sorted=all;
	sort(sorted.begin(),sorted.end());
	REP(mask,1<<x2) {
		vector<int> diff(n-1); int fst;
		REP(i,n) {
			int cnt=0;
			REP(k,x2) { int cur=((a[i]>>(x1+k))^(mask>>k))&1; cnt+=cur; }
			if(i==0) fst=cnt; else diff[i-1]=cnt-fst;
		}
		//printf("%x:",mask); REPSZ(k,diff) printf(" %d",diff[k]); puts("");
		int idx=lower_bound(sorted.begin(),sorted.end(),diff)-sorted.begin();
		if(idx!=SZ(sorted)&&sorted[idx]==diff) {
			int realidx=-1; REPSZ(i,all) if(all[i]==sorted[idx]) { realidx=i; break; } assert(realidx!=-1);
			return (mask<<x1)|realidx;
		}
	}
	return -1;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}