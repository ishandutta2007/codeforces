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

int n,scnt,slen,shots;
char s[MAXN+1];

int ret[MAXN],nret;

void run() {
	scanf("%d%d%d%d%s",&n,&scnt,&slen,&shots,s);
	nret=0;
	for(int at=0,to=at;at<n;at=to) {
		to=at+1; if(s[at]=='1') continue;
		while(to<n&&s[to]=='0') ++to;
		//printf("%d..%d\n",at,to);
		int len=to-at,mx=len/slen;
		REP(i,mx) ret[nret++]=at+slen-1+i*slen;
	}
	nret=max(0,nret-(scnt-1));
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}