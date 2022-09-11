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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=200000;

char s[MAXLEN]; int slen;

int solve() {
	int ret=0;
	REP(i,slen) if(s[i]=='1') {
		int cntzero=0; while(cntzero<i&&s[i-cntzero-1]=='0') ++cntzero;
		int val=1;
		FOR(j,i,slen) {
			if(j!=i) val=2*val+s[j]-'0';
			if(val>slen) break;
			int sufflen=j-i+1;
			if(val>=sufflen&&val<=sufflen+cntzero) ++ret;
		}
	}
	return ret;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	printf("%d\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}