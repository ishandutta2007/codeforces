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

const int MAXLEN=1000000;


char A[MAXLEN+1];
char B[MAXLEN+1];

int cmp(char *a,char *b) {
	while(*a=='0') ++a; int alen=strlen(a);
	while(*b=='0') ++b; int blen=strlen(b);
	if(alen!=blen) return alen<blen?-1:+1;
	while(*a!='\0'&&*a==*b) ++a,++b;
	if(*a=='\0') return 0;
	return *a<*b?-1:+1;
}

void run() {
	scanf("%s%s",A,B);
	int res=cmp(A,B);
	if(res<0) printf("<"); else if(res>0) printf(">"); else printf("="); puts("");
	
}

int main() {
	run();
	return 0;
}