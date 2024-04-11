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

int n;
char s[3001];

void run() {
	scanf("%d %s",&n,s);
	bool leftfalls=false; int nleft=0,ret=0;
	REP(i,n) {
		if(s[i]=='.') {
			++nleft;
		}
		if(s[i]=='L') {
			if(leftfalls&&nleft%2==1) ++ret;
			leftfalls=false; nleft=0;
		}
		if(s[i]=='R') {
			if(!leftfalls) ret+=nleft;
			leftfalls=true; nleft=0;
		}
	}
	if(!leftfalls) ret+=nleft;
	printf("%d\n",ret);
	
}

int main() {
	run();
	return 0;
}