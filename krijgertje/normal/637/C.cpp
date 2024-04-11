
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

const int MAXN=1000;
const int LEN=6;

int n;
char s[MAXN][LEN+1];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",s[i]);
	if(n==1) { printf("6\n"); return; }
	int mx=0;
	REP(i,n) FOR(j,i+1,n) {
		int cnt=0; REP(k,LEN) if(s[i][k]==s[j][k]) ++cnt; if(cnt>mx) mx=cnt;
	}
	printf("%d\n",(LEN-mx-1)/2);

}

int main() {
	run();
	return 0;
}