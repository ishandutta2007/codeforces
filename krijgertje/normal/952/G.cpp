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

const int MAXLEN=10;
const int MAXH=3*MAXLEN;
const int MAXW=2*256+4;

char s[MAXLEN+1]; int slen;


int nmin[MAXLEN];

char g[MAXH][MAXW+1];

void run() {
	scanf("%s",s); slen=strlen(s);

	int at=0;
	REP(i,slen) {
		int to=(int)s[i];
		nmin[i]=(at-to+256)%256; if(nmin[i]<=1) nmin[i]+=256;
		at=to;
	}
	//printf("nmin: "); REP(i,slen) printf(" %d",nmin[i]); puts("");

	int h=3*slen,w=2*256+4;
	REP(x,h) { REP(y,w) g[x][y]='.'; g[x][w]='\0'; }
	REP(i,slen) {
		REP(j,nmin[i]-1) g[3*i+0][2*j+1]='X'; g[3*i+0][w-2]='X';
		REP(j,2*nmin[i]-1) g[3*i+1][j]='X'; g[3*i+1][w-2]='X';
	}
	REP(x,h) printf("%s\n",g[x]);
}

int main() {
	run();
	return 0;
}