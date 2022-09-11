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

int n;
char buff[20];

void run() {
	scanf("%d",&n);
	pair<int,int> a=MP(0,1),b=MP(1,0);
	REP(i,n) {
		pair<int,int> c=MP(a.first+b.first,a.second+b.second);
		printf("%d %d\n",c.first,c.second); fflush(stdout);
		scanf("%s",buff);
		if(strcmp(buff,"black")==0) b=c; else if(strcmp(buff,"white")==0) a=c; else assert(false);
	}
	printf("%d %d %d %d\n",0,0,a.first+b.first,a.second+b.second); fflush(stdout);
}

int main() {
	run();
	return 0;
}