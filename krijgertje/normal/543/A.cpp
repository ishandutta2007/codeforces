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

const int MAXPROG=500;
const int MAXLINE=500;
const int MAXBUG=500;

int nprog,nline,nbug,MOD;
int x[MAXPROG];
int ways[MAXLINE+1][MAXBUG+1];

const inline void inc(int &a,int b) { a+=b; if(a>=MOD) a-=MOD; }

void run() {
	scanf("%d%d%d%d",&nprog,&nline,&nbug,&MOD);
	REP(i,nprog) scanf("%d",&x[i]);

	memset(ways,0,sizeof(ways));
	ways[0][0]=1;
	REP(i,nprog) REPE(j,nline) REPE(k,nbug) if(j+1<=nline&&k+x[i]<=nbug) inc(ways[j+1][k+x[i]],ways[j][k]);

	int ret=0; REPE(k,nbug) inc(ret,ways[nline][k]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}