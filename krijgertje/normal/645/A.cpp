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

char a[4];
char b[4];

void norm(char g[4]) {
	while(g[0]!='X'||g[1]!='A') { int x=-1; REP(i,4) if(g[i]=='X') x=i; int y=(x+1)%4; swap(g[x],g[y]);	}
}
void print(char g[4]) { REP(i,4) printf("%c",g[i]); puts(""); }

void run() {
	REP(i,2) REP(j,2) scanf(" %c",&a[2*i+j]); swap(a[2],a[3]); norm(a); //print(a);
	REP(i,2) REP(j,2) scanf(" %c",&b[2*i+j]); swap(b[2],b[3]); norm(b); //print(b);
	bool ok=true; REP(i,4) if(a[i]!=b[i]) ok=false; printf("%s\n",ok?"YES":"NO");
}

int main() {
	run();
	return 0;
}