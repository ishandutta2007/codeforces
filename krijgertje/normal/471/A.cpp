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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n=6;
int x[6];

void run() {
	REP(i,n) scanf("%d",&x[i]);
	// 4 legs = same, bear: h<b, eleph: h=b
	sort(x,x+n);
	if(x[0]==x[3]&&x[4]!=x[5]) { printf("Bear\n"); return; }
	if(x[1]==x[4]&&x[0]!=x[5]) { printf("Bear\n"); return; }
	if(x[2]==x[5]&&x[0]!=x[1]) { printf("Bear\n"); return; }
	if(x[0]==x[3]&&x[4]==x[5]) { printf("Elephant\n"); return; }
	if(x[1]==x[4]&&x[0]==x[5]) { printf("Elephant\n"); return; }
	if(x[2]==x[5]&&x[0]==x[1]) { printf("Elephant\n"); return; }
	printf("Alien\n");
}

int main() {
	run();
	return 0;
}