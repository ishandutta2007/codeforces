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

const int MAXLEN=100;

int slen;
char s[MAXLEN+1];

bool solve() {
	for(int i=0;i<slen-i-1;++i) {
		char a=s[i],b=s[slen-i-1];
		int diff=abs(a-b);
		if(diff!=0&&diff!=2) return false;
	}
	return true;
}

void run() {
	scanf("%d%s",&slen,s);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}