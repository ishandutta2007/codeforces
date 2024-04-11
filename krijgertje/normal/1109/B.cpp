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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=5000;

char s[MAXLEN+1]; int slen;

int calc(int len) {
	int partlen=(len-len%2)/2;
	bool allsame=true; FOR(i,1,partlen) if(s[i]!=s[0]) allsame=false; if(allsame) return -1;
	if(len%2==1) {
		return 2;
	} else {
		int partlen=len/2;
		bool partpal=true; REP(i,partlen) if(s[i]!=s[partlen-i-1]) partpal=false; if(!partpal) return 1;
		int sub=calc(len/2);
		return sub==1?1:2;
	}
}

int solve() {
	return calc(slen);
}

void run() {
	scanf("%s",s); slen=strlen(s);
	int ans=solve();
	if(ans==-1) printf("Impossible\n"); else printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}