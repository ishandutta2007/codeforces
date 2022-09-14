#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }


char s[201]; int slen,nadd;

void run() {
	scanf("%s%d",s,&nadd); slen=strlen(s);
	for(int ret=(slen+nadd)/2;ret>=0;--ret) REPE(i,slen+nadd-2*ret) {
		bool ok=true;
		REP(j,ret) if(i+ret+j<slen&&s[i+j]!=s[i+ret+j]) { ok=false; break; }
		if(ok) { printf("%d\n",2*ret); return; }
	}
}

int main() {
	run();
	return 0;
}