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

const int SZ=1000;

int n;
int cnt1[2*SZ-1],cnt2[2*SZ-1];

void run() {
	scanf("%d",&n); memset(cnt1,0,sizeof(cnt1)); memset(cnt2,0,sizeof(cnt2));
	REP(i,n) { int x,y; scanf("%d%d",&x,&y); --x,--y; ++cnt1[x+y]; ++cnt2[SZ-x-1+y]; }
	int ret=0; REP(i,2*SZ-1) ret+=cnt1[i]*(cnt1[i]-1)/2+cnt2[i]*(cnt2[i]-1)/2; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}