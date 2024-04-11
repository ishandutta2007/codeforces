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

const int MAXN=100000;

int n;
char s[MAXN+1];

int solve() {
	int tot=0; REP(i,n) if(s[i]=='G') ++tot;
	int ret=0,a=0,b=0;
	REP(i,n) {
		if(s[i]=='G') {
			++a;
		} else {
			b=a,a=0;
		}
		ret=max(ret,min(tot,a+b+1));
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}