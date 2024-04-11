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

const int MAXN=26;

int n;
int cnt[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&cnt[i]);
	int g=cnt[0]; FOR(i,1,n) g=gcd(g,cnt[i]);
	int nodd=0,oddidx=-1; REP(i,n) if(cnt[i]%2==1) ++nodd,oddidx=i;
	if(nodd==0) {
		printf("%d\n",g);
		REP(i,g) {
			if(i%2==0) REP(j,n) REP(k,cnt[j]/g) printf("%c",'a'+j);
			if(i%2==1) for(int j=n-1;j>=0;--j) REP(k,cnt[j]/g) printf("%c",'a'+j);
		}
		puts("");
	} else if(nodd==1) {
		printf("%d\n",g);
		REP(i,g) {
			REP(j,n) REP(k,cnt[j]/g/2) printf("%c",'a'+j);
			printf("%c",'a'+oddidx);
			for(int j=n-1;j>=0;--j) REP(k,cnt[j]/g/2) printf("%c",'a'+j);
		}
		puts("");
	} else {
		printf("%d\n",0);
		REP(j,n) REP(k,cnt[j]) printf("%c",'a'+j);
		puts("");
	}
}

int main() {
	run();
	return 0;
}