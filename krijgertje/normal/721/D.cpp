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

const int MAXN=200000;

int n,have,by;
ll x[MAXN];

void solve() {
	int nneg=0,nzero=0,npos=0; REP(i,n) if(x[i]<0) ++nneg; else if(x[i]>0) ++npos; else ++nzero;
	if(nneg%2==0) {
		int idx=-1;
		REP(i,n) if(idx==-1||abs(x[i])<abs(x[idx])) idx=i;
		if(x[idx]>=0) {
			int want=x[idx]/by+1;
			if(have<want) { x[idx]-=have*by; return; }
			if(x[idx]==0) --nzero; else --npos; x[idx]-=want*by; have-=want; ++nneg;
		} else {
			int want=-x[idx]/by+1;
			if(have<want) { x[idx]+=have*by; return; }
			--nneg; x[idx]+=want*by; have-=want; ++npos;
		}
	}
	priority_queue<pair<ll,int> > q;
	REP(i,n) q.push(MP(-abs(x[i]),i));
	while(have>0) {
		int at=q.top().second; q.pop();
		if(x[at]==0) --nzero,++npos; if(x[at]<0) x[at]-=by; else x[at]+=by; --have;
		q.push(MP(-abs(x[at]),at));
	}
}

void run() {
	scanf("%d%d%d",&n,&have,&by);
	REP(i,n) scanf("%lld",&x[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",x[i]); } puts("");

}


int main() {
	run();
	return 0;
}