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

const int MAXLEN=100000;

char s[MAXLEN+1]; int slen;
char ans[MAXLEN+1];

void solve() {
	REPE(i,slen) ans[i]=s[i];
	int mnbal=0;
	for(int i=slen-1;i>=0;--i) {
		//printf("%d: mnbal=%d\n",i,mnbal);
		if(s[i]=='1'&&mnbal>=0) ans[i]='0';
		int cur=s[i]=='1'?+1:-1;
		mnbal=min(mnbal+cur,cur);
	}
}

void run() {
	scanf("%s",s); slen=strlen(s);
	solve();
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}