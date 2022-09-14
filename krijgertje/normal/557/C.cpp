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
const int MAXCOST=200;
typedef struct Leg { int len,cost; } Leg;
bool operator<(const Leg &a,const Leg &b) { return a.len>b.len; }

int n;
Leg leg[MAXN];
int costcnt[MAXCOST+1];


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&leg[i].len);
	REP(i,n) scanf("%d",&leg[i].cost);
	sort(leg,leg+n);
	int sumcost=0; REP(i,n) sumcost+=leg[i].cost;
	memset(costcnt,0,sizeof(costcnt)); REP(i,n) costcnt[leg[i].cost]++;

	int at=0; int ret=INT_MAX; 
	while(at<n) {
		int save=0,to=at;
		while(to<n&&leg[at].len==leg[to].len) { save+=leg[to].cost; costcnt[leg[to].cost]--; ++to; }
		int left=to-at-1;
		for(int i=MAXCOST;i>=0&&left>0;--i) { int now=min(costcnt[i],left); save+=now*i; left-=now; }
		int cur=sumcost-save;
//		printf("%d..%d=%d\n",at,to-1,cur);
		if(cur<ret) ret=cur;
		at=to;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}