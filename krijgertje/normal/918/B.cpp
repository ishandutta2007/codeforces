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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }


int nip, ncommand;
map<string, string> mp;
char ipbuff[4 * 3 + 3 + 1 + 1];
char namebuff[10 + 1];
char commandbuff[10 + 1];

void run() {
	scanf("%d%d", &nip, &ncommand);
	REP(i, nip) { scanf("%s%s", namebuff, ipbuff); int iplen = strlen(ipbuff); ipbuff[iplen] = ';'; ipbuff[iplen + 1] = '\0'; mp[ipbuff] = namebuff; }
	REP(i, ncommand) { scanf("%s%s", commandbuff, ipbuff); printf("%s %s #%s\n", commandbuff, ipbuff, mp[ipbuff].c_str()); }
}

int main() {
	run();
	return 0;
}