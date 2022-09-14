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

const int MAXN=50;

int n;
bool doneh[MAXN],donev[MAXN];

int ret[MAXN*MAXN],nret;

void run() {
	scanf("%d",&n);
	memset(doneh,0,sizeof(doneh));
	memset(donev,0,sizeof(donev));
	nret=0;
	REP(i,n*n) {
		int h,v; scanf("%d%d",&h,&v); --h,--v;
		if(!doneh[h]&&!donev[v]) { ret[nret++]=i+1; doneh[h]=donev[v]=true; }
	}
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}


int main() {
	run();
	return 0;
}