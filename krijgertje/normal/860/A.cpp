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

const int MAXN=3000;

int n;
char s[MAXN+1];
bool isvow(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }

void run() {
	scanf("%s",s); n=strlen(s);
	int start=0,ncons=0; bool allsame=true; bool first=true;
	REP(i,n) {
		if(isvow(s[i])) { ncons=0; allsame=true; continue; }
		if(ncons==0) { ncons=1; continue; }
		if(ncons+1>=3&&(!allsame||s[i]!=s[i-1])) {
			if(!first) printf(" "); else first=false;
			FOR(j,start,i) printf("%c",s[j]);
			start=i; ncons=1; allsame=true;
		} else {
			++ncons; if(s[i]!=s[i-1]) allsame=false;
		}
	}
	if(!first) printf(" "); else first=false;
	FOR(j,start,n) printf("%c",s[j]);
	puts("");
}

int main() {
	run();
	return 0;
}