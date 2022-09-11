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

const int MAXLEN=100000;

int slen; char s[MAXLEN+1];

int cnt[26];

bool solve() {
	if(slen<=1) return true;
	memset(cnt,0,sizeof(cnt)); REP(i,slen) ++cnt[s[i]-'a'];
	REP(i,26) if(cnt[i]>=2) return true;
	return false;
}

void run() {
	scanf("%d%s",&slen,s);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}