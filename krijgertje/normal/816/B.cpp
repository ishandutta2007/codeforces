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
const int MAXVAL=200000;

int n,need,nq;
int have[MAXVAL+2];
int cnt[MAXVAL+2];



void run() {
	scanf("%d%d%d",&n,&need,&nq);
	REPE(i,MAXVAL+1) have[i]=0; REP(i,n) { int l,r; scanf("%d%d",&l,&r); have[l]++; have[r+1]--; } REPE(i,MAXVAL) have[i+1]+=have[i];
	//REPE(i,MAXVAL) if(have[i]>0) printf("%d: %d\n",i,have[i]);
	cnt[0]=0; REPE(i,MAXVAL) cnt[i+1]=cnt[i]+(have[i]>=need?1:0);
	REP(i,nq) {
		int l,r; scanf("%d%d",&l,&r);
		int ret=cnt[r+1]-cnt[l]; printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}