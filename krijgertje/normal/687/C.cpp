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

const int MAXN=500;
const int MAXP=500;

int n,p;
int x[MAXN];
bool can[MAXP+1][MAXP+1];

void run() {
	scanf("%d%d",&n,&p);
	REP(i,n) scanf("%d",&x[i]);
	memset(can,false,sizeof(can)); can[0][0]=true;
	REP(i,n) for(int a=p-x[i];a>=0;--a) for(int b=a;b>=0;--b) if(can[a][b]) {
		can[a+x[i]][b]=can[a+x[i]][b+x[i]]=true;
	}
	int ret=0; REPE(i,p) if(can[p][i]) ++ret;
	printf("%d\n",ret); bool first=true; REPE(i,p) if(can[p][i]) { if(first) first=false; else printf(" "); printf("%d",i); } puts("");
}

int main() {
	run();
	return 0;
}