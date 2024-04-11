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

int n;
int numnoovertake;
int limstck[MAXN],nlimstck;
int speed;

void run() {
	scanf("%d",&n);
	numnoovertake=0,nlimstck=0; int ret=0;
	REP(i,n) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			scanf("%d",&speed);
			while(nlimstck>0&&speed>limstck[nlimstck-1]) ++ret,--nlimstck;
		}
		if(kind==2) {
			ret+=numnoovertake; numnoovertake=0;
		}
		if(kind==3) {
			int lim; scanf("%d",&lim);
			if(lim>=speed) limstck[nlimstck++]=lim; else ++ret;
		}
		if(kind==4) {
			numnoovertake=0;
		}
		if(kind==5) {
			nlimstck=0;
		}
		if(kind==6) {
			++numnoovertake;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}