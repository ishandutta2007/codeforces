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
const int MAXSUMLEN=100000;

int n;
char s[MAXSUMLEN+1];
int off[MAXN],len[MAXN];

int dp[MAXN][26];

int solve() {
	REP(i,n) {
		REP(x,26) dp[i][x]=0;
		pair<int,int> pref,suff;
		for(int l=0,r=l;l<len[i];l=r) { while(r<len[i]&&s[off[i]+l]==s[off[i]+r]) ++r; int x=s[off[i]+l]-'a'; dp[i][x]=max(dp[i][x],r-l); if(l==0) pref=MP(x,r-l); suff=MP(x,r-l); }
		if(i!=0) {
			REP(x,26) if(dp[i-1][x]>=1) { int cur=(suff.first==x?suff.second:0)+1+(pref.first==x?pref.second:0); dp[i][x]=max(dp[i][x],cur); }
			if(pref.second==len[i]) { int x=pref.first; dp[i][x]=max(dp[i][x],dp[i-1][x]*(len[i]+1)+len[i]); }
		}
	}
	int ret=0; REP(x,26) ret=max(ret,dp[n-1][x]); return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) { off[i]=i==0?0:off[i-1]+len[i-1]; scanf("%s",s+off[i]); len[i]=strlen(s+off[i]); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}