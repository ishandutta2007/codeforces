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

const int MAXLEN=200000;

int slen,tlen;
char s[MAXLEN+1],t[MAXLEN+1];

bool solve() {
	int l=0,r=0;
	while(l<slen&&s[l]!='*'&&l<tlen&&s[l]==t[l]) ++l;
	while(r<slen&&s[slen-r-1]!='*'&&r<tlen&&s[slen-r-1]==t[tlen-r-1]) ++r;
	return l==slen&&l==tlen||l<slen&&s[l]=='*'&&r<slen&&s[slen-r-1]=='*'&&l+r<=tlen;
}

void run() {
	scanf("%d%d",&slen,&tlen); scanf("%s%s",s,t);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}