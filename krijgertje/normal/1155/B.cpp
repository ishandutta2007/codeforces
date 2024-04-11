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

const int MAXN=100000;

int n;
char s[MAXN+1];

bool removed[MAXN];

bool solve() {
	int nremove=(n-11)/2;
	REP(i,n) removed[i]=false;
	int rema=nremove; REP(i,n) if(s[i]!='8'&&rema>0) removed[i]=true,--rema;
	int remb=nremove; REP(i,n) if(s[i]=='8'&&remb>0) removed[i]=true,--remb;
	REP(i,n) if(!removed[i]) return s[i]=='8';
	assert(false); return false;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}