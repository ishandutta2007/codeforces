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

char s[MAXLEN+1]; int len;

void run() {
	scanf("%s",s); len=strlen(s);
	if(len%2!=0) { printf("-1\n"); return; }
	int dx=0,dy=0; REP(i,len) if(s[i]=='R') ++dx; else if(s[i]=='L') --dx; else if(s[i]=='U') ++dy; else if(s[i]=='D') --dy; else assert(false);
	int ret=0;
	{ int cur=abs(dx)/2; ret+=cur; if(dx>0) dx-=2*cur; else dx+=2*cur; } assert(abs(dx)<=1);
	{ int cur=abs(dy)/2; ret+=cur; if(dy>0) dy-=2*cur; else dy+=2*cur; } assert(abs(dy)<=1);
	assert(dx==0&&dy==0||dx!=0&&dy!=0); if(dx!=0) ++ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}