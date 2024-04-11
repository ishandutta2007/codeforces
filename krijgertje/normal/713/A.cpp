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

const int MAXLEN=18;

int nq;
int calc(char *s) { int ret=0; for(int i=0;s[i]!='\0';++i) ret=2*ret+(s[i]-'0')%2; return ret; }

void run() {
	scanf("%d",&nq);
	map<int,int> cnt;
	REP(qi,nq) {
		char c; char s[MAXLEN+1]; scanf(" %c%s",&c,s); int p=calc(s);
		if(c=='+') cnt[p]++;
		if(c=='-') cnt[p]--;
		if(c=='?') printf("%d\n",cnt[p]);
	}
}

int main() {
	run();
	return 0;
}