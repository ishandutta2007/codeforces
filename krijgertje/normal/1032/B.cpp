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

const int MAXLEN=100;
const int MAXH=5;
const int MAXW=20;

char s[MAXLEN+1]; int slen;

int h,w; char g[MAXH][MAXW+1];

void solve() {
	h=(slen+MAXW-1)/MAXW;
	w=(slen+h-1)/h;
	int each=slen/h,rem=slen%h;
	int at=0; REP(x,h) { REP(y,w) g[x][y]='*'; g[x][w]='\0'; REP(y,each) if(at<slen) g[x][y]=s[at++]; if(x<rem&&at<slen) g[x][each]=s[at++]; }
}

void run() {
	scanf("%s",s); slen=strlen(s);
	solve();
	printf("%d %d\n",h,w); REP(x,h) printf("%s\n",g[x]);
}

int main() {
	run();
	return 0;
}