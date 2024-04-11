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


int n,want;
int ret[MAXN];

void go(int l,int r,int mn,int want) {
	//printf("go(%d,%d,%d,%d)\n",l,r,mn,want);
	int cnt=r-l; assert(want%2==1&&1<=want&&want<=2*cnt-1);
	if(want==1) {
		REP(i,cnt) ret[l+i]=mn+i;
	} else {
		int m=(l+r)/2;
		int lwant=min(2*(m-l)-1,want-2),rwant=want-lwant-1;
		go(l,m,mn+(r-m),lwant); go(m,r,mn,rwant);
	}
}

bool solve() {
	if(want%2==0||want<1||want>2*n-1) return false;
	go(0,n,1,want);
	return true;
}

void run() {
	scanf("%d%d",&n,&want);
	if(!solve()) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}