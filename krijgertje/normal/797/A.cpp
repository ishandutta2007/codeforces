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

const int MAXWANT=20;

int n,want;
int ret[MAXWANT],nret;

void run() {
	scanf("%d%d",&n,&want);
	nret=0; for(int x=2;x*x<=n&&nret+1<want;++x) while(n%x==0&&nret+1<want) ret[nret++]=x,n/=x; if(n!=1) ret[nret++]=n;
	if(nret==want) {
		REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
	} else {
		printf("-1\n");
	}

}

int main() {
	run();
	return 0;
}