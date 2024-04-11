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

const int MAXDAY=500;
const int MAXHOUR=500;
const int MAXSKIP=500;

int nday,nhour,nskip;
char s[MAXDAY][MAXHOUR+1];

vector<int> cur;

int now[MAXHOUR+1];

int dp[MAXSKIP+1];

void run() {
	scanf("%d%d%d",&nday,&nhour,&nskip); REP(i,nday) scanf("%s",s[i]);

	int sum=0; memset(dp,0,sizeof(dp));
	REP(i,nday) {
		cur.clear(); REP(j,nhour) if(s[i][j]=='1') cur.PB(j); if(SZ(cur)==0) continue;
		REPE(j,nhour) now[j]=0;
		int origlen=cur[SZ(cur)-1]-cur[0]+1;
		sum+=origlen;
		now[SZ(cur)]=max(now[SZ(cur)],origlen);
		REPSZ(a,cur) FORSZ(b,a,cur) {
			int skip=a+SZ(cur)-b-1,len=cur[b]-cur[a]+1,gain=origlen-len;
			now[skip]=max(now[skip],gain);
		}
		for(int j=nskip;j>=0;--j) REPE(k,j) if(j-k<=nhour) dp[j]=max(dp[j],dp[k]+now[j-k]);
	}
	int ret=sum; REPE(j,nskip) ret=min(ret,sum-dp[j]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}