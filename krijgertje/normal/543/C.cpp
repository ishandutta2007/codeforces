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

const int MAXN=20;
const int MAXLEN=20;

int n,len;
char s[MAXN][MAXLEN+1];
int c[MAXN][MAXLEN];

int dp[1<<MAXN];
int cnt[MAXLEN][26];
int msk[MAXLEN][26];
int sum[MAXLEN][26];
int mx[MAXLEN][26];

void run() {
	scanf("%d%d",&n,&len);
	REP(i,n) scanf("%s",s[i]);
	REP(i,n) REP(j,len) scanf("%d",&c[i][j]);

	memset(cnt,0,sizeof(cnt));
	memset(msk,0,sizeof(cnt));
	memset(sum,0,sizeof(cnt));
	memset(sum,0,sizeof(cnt));
	REP(i,n) REP(j,len) {
		int x=s[i][j]-'a';
		++cnt[j][x];
		msk[j][x]|=1<<i;
		sum[j][x]+=c[i][j];
		if(c[i][j]>mx[j][x]) mx[j][x]=c[i][j];
	}

	dp[0]=0;
	FOR(i,1,1<<n) {
		dp[i]=INT_MAX;
		int at=0; while((i&(1<<at))==0) ++at;
		REP(j,len) {
			int x=s[at][j]-'a';
			{ int cur=dp[i&~(1<<at)]+(cnt[j][x]==1?0:c[at][j]); if(cur<dp[i]) dp[i]=cur; }
			{ int cur=dp[i&~msk[j][x]]+sum[j][x]-mx[j][x]; if(cur<dp[i]) dp[i]=cur; }
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
}

int main() {
	run();
	return 0;
}