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

const int MAXLEN=19;

char s[MAXLEN+1]; int slen;

void run() {
	scanf("%s",s); slen=strlen(s);

	int ret=INT_MAX;
	REP(a,slen) if(s[a]!='0') REP(b,slen) REP(c,slen) {
		if(slen>2&&a==b||a==c) continue; if(b==c||(10*(s[b]-'0')+(s[c]-'0'))%25!=0) continue;
		int cur=0;
		cur+=a;
		cur+=slen-1-(c+(a>c?1:0));
		if(b!=a) cur+=slen-2-(b+(a>b?1:0)-(c<b?1:0));
		//printf("%d %d %d -> %d\n",a,b,c,cur);
		ret=min(ret,cur);
	}
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}