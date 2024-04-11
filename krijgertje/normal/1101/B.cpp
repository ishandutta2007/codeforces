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

const int MAXLEN=500000;

char s[MAXLEN+1]; int slen;

int solve() {
	int l=0; while(l<slen&&s[l]!='[') ++l; while(l<slen&&s[l]!=':') ++l; if(l>=slen) return -1;
	int r=slen-1; while(r>=0&&s[r]!=']') --r; while(r>=0&&s[r]!=':') --r; if(l>=r) return -1;
	int ret=4; FORE(i,l+1,r-1) if(s[i]=='|') ++ret; return ret;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}