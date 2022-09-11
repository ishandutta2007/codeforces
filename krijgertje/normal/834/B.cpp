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

const int MAXLEN=1000000;

int n,have;
char s[MAXLEN+1];
int lst[26];
int fst[26];

void run() {
	scanf("%d%d%s",&n,&have,s);
	REP(i,26) fst[i]=lst[i]=n; REP(i,n) { if(fst[s[i]-'A']==n) fst[s[i]-'A']=i; lst[s[i]-'A']=i; }
	int cur=0,need=0;
	REP(i,n) {
		if(i==fst[s[i]-'A']) ++cur;
		if(cur>need) need=cur;
		if(i==lst[s[i]-'A']) --cur;
	}
	printf("%s\n",need>have?"YES":"NO");
}

int main() {
	run();
	return 0;
}