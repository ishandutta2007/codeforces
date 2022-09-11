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

const int MAXN=50;
const char WANT[4]={'A','C','T','G'};

int n;
char s[MAXN+1];

int solve() {
	int ret=INT_MAX;
	REPE(i,n-4) {
		int cur=0;
		REP(j,4) {
			int a=s[i+j]-'A',b=WANT[j]-'A';
			int now=min(abs(a-b),26-abs(a-b));
			//printf("%d %d: %d\n",i,j,now);
			cur+=now;
		}
		ret=min(ret,cur);
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