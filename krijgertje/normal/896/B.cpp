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

const int MAXN=1000;

int n,nq,mxval;

int have[MAXN];

void change(int idx,int val) {
	have[idx]=val;
	printf("%d\n",idx+1); fflush(stdout);
}
bool done() { REP(i,n) if(have[i]==-1) return false; REP(i,n-1) if(have[i]>have[i+1]) return false; return true; }

void run() {
	scanf("%d%d%d",&n,&nq,&mxval);

	REP(i,n) have[i]=-1;
	while(!done()) {
		int val; scanf("%d",&val);
		if(val<=(mxval+1)/2) {
			int at=0; while(have[at]!=-1&&have[at]<=val) ++at; change(at,val);
		} else {
			int at=n-1; while(have[at]!=-1&&have[at]>=val) --at; change(at,val);
		}
	}
}

int main() {
	run();
	return 0;
}