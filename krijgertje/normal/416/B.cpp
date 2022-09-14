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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int npict,npaint;
int cost[50000][5];
int dp[50000][5];

void run() {
	scanf("%d%d",&npict,&npaint);
	REP(i,npict) REP(j,npaint) scanf("%d",&cost[i][j]);
	REP(i,npict) REP(j,npaint) dp[i][j]=cost[i][j]+max(i==0?0:dp[i-1][j],j==0?0:dp[i][j-1]);
	REP(i,npict) { if(i!=0) printf(" "); printf("%d",dp[i][npaint-1]); } puts("");

}

int main() {
	run();
	return 0;
}