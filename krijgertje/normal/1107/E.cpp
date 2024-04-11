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

const int MAXN=100;

int n;
char s[MAXN+1];
int a[MAXN+1];

int sum[2][MAXN+1];
ll dp[MAXN][MAXN];
ll dpcons[MAXN][MAXN][2][MAXN+1];

ll solve() {
	REP(x,2) { sum[x][0]=0; REP(i,n) sum[x][i+1]=sum[x][i]+(s[i]=='0'+x?1:0); }

	FORE(len,1,n) REPE(i,n-len) {
		int j=i+len-1;
		dp[i][j]=a[1]+(i==j?0:dp[i+1][j]);
		FORE(k,i+1,j) if(s[k]==s[i]) {
			int x=s[i]-'0';
			int have=sum[x][k]-sum[x][i+1];
			REPE(cnt,have) dp[i][j]=max(dp[i][j],a[2+cnt]+(k==i+1?0:dpcons[i+1][k-1][x][cnt])+(j==k?0:dp[k+1][j]));
		}
		REP(x,2) {
			int have=sum[x][j+1]-sum[x][i];
			dpcons[i][j][x][0]=dp[i][j];
			FORE(cnt,1,have) {
				dpcons[i][j][x][cnt]=0;
				FORE(k,i,j) if(s[k]-'0'==x&&sum[x][j+1]-sum[x][k+1]>=cnt-1) dpcons[i][j][x][cnt]=max(dpcons[i][j][x][cnt],(k==i?0:dp[i][k-1])+(k==j?0:dpcons[k+1][j][x][cnt-1]));
			}
		}
	}
	return dp[0][n-1];
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	FORE(i,1,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}