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

const int MAXN=200;

int n; char s[MAXN+1];
char ret[3+1]; int nret;

bool can(int a,int b,int c) {
	if(b>0&&c>0) return true;
	if(a==0) return false;
	if(b==0&&c==0) return true;
	if(b>1||c>1) return true;
	return false;
}

void run() {
	scanf("%d%s",&n,s);
	int r=0,g=0,b=0; REP(i,n) if(s[i]=='R') ++r; else if(s[i]=='G') ++g; else if(s[i]=='B') ++b;
	nret=0;
	if(can(b,g,r)) ret[nret++]='B';
	if(can(g,r,b)) ret[nret++]='G';
	if(can(r,b,g)) ret[nret++]='R';
	ret[nret]='\0';
	printf("%s\n",ret);
}
int main() {
	run();
	return 0;
}