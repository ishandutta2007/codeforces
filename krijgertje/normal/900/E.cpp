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

const int MAXN=100000;

int n;
char s[MAXN+1];
int plen;

int ecnt[MAXN+1];
int ocnt[MAXN+1];

pair<int,int> dp[MAXN+1];
void upd(pair<int,int> &a,pair<int,int> b,int d) { b.first++; b.second+=d; if(b.first>a.first||b.first==a.first&&b.second<a.second) a=b; }

void run() {
	scanf("%d%s%d",&n,s,&plen);

	ecnt[0]=0; REP(i,n) ecnt[i+1]=ecnt[i]+(s[i]=='a'+(i%2==0?0:1)?1:0);
	ocnt[0]=0; REP(i,n) ocnt[i+1]=ocnt[i]+(s[i]=='a'+(i%2==0?1:0)?1:0);
	//REPE(i,n) printf("%d: %d %d\n",i,ecnt[i],ocnt[i]);

	dp[0]=MP(0,0);
	REP(i,n) {
		dp[i+1]=dp[i];
		if(i+1>=plen&&(i+1-plen)%2==0&&ocnt[i+1]-ocnt[i+1-plen]==0) upd(dp[i+1],dp[i+1-plen],plen-(ecnt[i+1]-ecnt[i+1-plen]));
		if(i+1>=plen&&(i+1-plen)%2==1&&ecnt[i+1]-ecnt[i+1-plen]==0) upd(dp[i+1],dp[i+1-plen],plen-(ocnt[i+1]-ocnt[i+1-plen]));
		//printf("dp[%d]=%d,%d\n",i+1,dp[i+1].first,dp[i+1].second);
	}
	printf("%d\n",dp[n].second);
}

int main() {
	run();
	return 0;
}