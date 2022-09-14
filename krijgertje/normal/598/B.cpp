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

const int MAXLEN=10000;

char s[MAXLEN+1]; int slen;
char t[MAXLEN];
int nq;


void run() {
	scanf("%s",s); slen=strlen(s); scanf("%d",&nq);
	REP(qi,nq) {
		int l,r,k; scanf("%d%d%d",&l,&r,&k); --l,--r; int clen=r-l+1; k%=clen;
		REP(i,clen) t[i]=s[l+i];
		REP(i,clen) s[l+i]=t[(i-k+clen)%clen];
		//printf("\t%s\n",s);
	}
	printf("%s\n",s);
}

int main() {
	run();
	return 0;
}