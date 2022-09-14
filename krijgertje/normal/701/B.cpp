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

const int MAXN=100000;
const int MAXQ=100000;

int n,nq;
bool c[MAXN],r[MAXN];
ll ret[MAXQ];

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) c[i]=r[i]=false;
	int nr=n,nc=n;
	REP(qi,nq) {
		int x,y; scanf("%d%d",&x,&y); --x,--y;
		if(!r[x]) r[x]=true,--nr;
		if(!c[y]) c[y]=true,--nc;
		ret[qi]=(ll)nr*nc;
	}
	REP(i,nq) { if(i!=0) printf(" "); printf("%lld",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}