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

const int MAXH=5000;
const int MAXW=5000;

int h,w,nq;
int rc[MAXH],rt[MAXH];
int cc[MAXW],ct[MAXW];

void run() {
	scanf("%d%d%d",&h,&w,&nq);
	memset(rc,0,sizeof(rc)); memset(rt,0,sizeof(rt));
	memset(cc,0,sizeof(cc)); memset(ct,0,sizeof(ct));
	FORE(qi,1,nq) {
		int type,idx,col; scanf("%d%d%d",&type,&idx,&col); --idx;
		if(type==1) rc[idx]=col,rt[idx]=qi;
		if(type==2) cc[idx]=col,ct[idx]=qi;
	}
	REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%d",rt[x]>=ct[y]?rc[x]:cc[y]); } puts(""); }

}

int main() {
	run();
	return 0;
}