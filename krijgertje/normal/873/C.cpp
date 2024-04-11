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

const int MAXH=100;
const int MAXW=100;

int h,w,k;
int g[MAXH][MAXW];

void run() {
	scanf("%d%d%d",&h,&w,&k); REP(x,h) REP(y,w) scanf("%d",&g[x][y]);

	int ret=0,retchanges=0;
	REP(y,w) {
		int now=0,nowchanges=0; REP(x,h) if(x<h-k) nowchanges+=g[x][y]; else now+=g[x][y];
		int cur=now,curchanges=nowchanges;
		//printf("y=%d init=%d/%d\n",y,now,nowchanges);
		for(int x=h-k-1;x>=0;--x) {
			now+=g[x][y]-g[x+k][y],nowchanges-=g[x][y];
			//printf("\tx=%d: %d/%d\n",x,now,nowchanges);
			if(now>=cur) cur=now,curchanges=nowchanges;
		}
		ret+=cur,retchanges+=curchanges;
	}
	printf("%d %d\n",ret,retchanges);
}

int main() {
	run();
	return 0;
}