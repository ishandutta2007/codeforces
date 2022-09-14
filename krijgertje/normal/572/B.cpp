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

int n,depth;

typedef struct X {
	vector<pair<int,int> > have;

	void norm(int dir) {
		sort(have.rbegin(),have.rend());
		int n=0;
		REPSZ(i,have) if(n==0||have[n-1].first!=have[i].first) have[n++]=have[i]; else have[n-1].second+=have[i].second;
		have.resize(n);
		if(dir==-1) reverse(have.begin(),have.end());
		while(SZ(have)>depth) have.pop_back();
		if(dir==-1) reverse(have.begin(),have.end());
	}
} X;


X buy,sll;


void run() {
	scanf("%d%d",&n,&depth);

	REP(i,n) {
		char c; int p,v; scanf(" %c%d%d",&c,&p,&v);
		if(c=='B') buy.have.PB(MP(p,v)); else sll.have.PB(MP(p,v));
	}
	buy.norm(+1); sll.norm(-1);
	REPSZ(i,sll.have) printf("S %d %d\n",sll.have[i].first,sll.have[i].second);
	REPSZ(i,buy.have) printf("B %d %d\n",buy.have[i].first,buy.have[i].second);
}

int main() {
	run();
	return 0;
}