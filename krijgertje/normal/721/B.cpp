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

const int MAXN=100;
const int MAXLEN=100;
int n,nwait;

char s[MAXN][MAXLEN+1];
char t[MAXLEN+1];

void run() {
	scanf("%d%d",&n,&nwait);
	REP(i,n) scanf("%s",s[i]);
	scanf("%s",t); int tlen=strlen(t);
	int mncnt=1,mxcnt=0;
	REP(i,n) {
		int len=strlen(s[i]);
		if(len<tlen) ++mncnt,++mxcnt;
		if(len==tlen) ++mxcnt;
	}
	//printf("mncnt=%d mxcnt=%d\n",mncnt,mxcnt);
	int mn=(mncnt-1)/nwait*5+mncnt,mx=(mxcnt-1)/nwait*5+mxcnt;
	printf("%d %d\n",mn,mx);
}


int main() {
	run();
	return 0;
}