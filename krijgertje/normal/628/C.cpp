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

const int MAXLEN=100000;

char s[MAXLEN+1]; int len,want;

void run() {
	scanf("%d%d%s",&len,&want,s);
	int left=want;
	REP(i,len) {
		if(s[i]-'a'>='z'-s[i]) {
			int cur=min(left,s[i]-'a'); s[i]-=cur; left-=cur;
		} else {
			int cur=min(left,'z'-s[i]); s[i]+=cur; left-=cur;
		}
	}
	if(left>0) printf("-1\n"); else printf("%s\n",s);
}

int main() {
	run();
	return 0;
}