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

char s[20]; int slen;

int ret[100],nret;

void run() {
	scanf("%d",&slen); scanf("%s",s);
	nret=0;
	REP(i,slen) {
		switch(s[i]) {
			case '2': ret[nret++]=2; break;
			case '3': ret[nret++]=3; break;
			case '4': ret[nret++]=2; ret[nret++]=2; ret[nret++]=3; break;
			case '5': ret[nret++]=5; break;
			case '6': ret[nret++]=5; ret[nret++]=3; break;
			case '7': ret[nret++]=7; break;
			case '8': ret[nret++]=7; ret[nret++]=2; ret[nret++]=2; ret[nret++]=2; break;
			case '9': ret[nret++]=7; ret[nret++]=2; ret[nret++]=3; ret[nret++]=3; break;
		}
	}
	sort(ret,ret+nret); reverse(ret,ret+nret);
	REP(i,nret) printf("%d",ret[i]); puts("");
}

int main() {
	run();
	return 0;
}