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

const int MAXSLEN=1000;
const int MAXPLEN=50;

vector<int> calckmp(char *s,int slen) {
	vector<int> kmp(slen+1,0);
	FORE(i,2,slen) {
		int cur=kmp[i-1]; while(cur!=0&&s[cur]!=s[i-1]) cur=kmp[cur];
		if(s[cur]==s[i-1]) ++cur;
		kmp[i]=cur;
	}
	return kmp;
}

char s[MAXSLEN+1]; int slen;
char a[MAXPLEN+1]; int alen;
char b[MAXPLEN+1]; int blen;

vector<int> anxt;
vector<int> bnxt;

void upd(vector<vector<int>> &dp,int j,int k,int val,char c) {
	while(j!=0&&a[j]!=c) j=anxt[j];
	if(a[j]==c) ++j;
	if(j==alen) ++val,j=anxt[j];
	while(k!=0&&b[k]!=c) k=bnxt[k];
	if(b[k]==c) ++k;
	if(k==blen) --val,k=bnxt[k];
	dp[j][k]=max(dp[j][k],val);
}

int solve() {
	anxt=calckmp(a,alen);
	bnxt=calckmp(b,blen);
	//printf("anxt:"); REPSZ(i,anxt) printf(" %d",anxt[i]); puts("");
	//printf("bnxt:"); REPSZ(i,bnxt) printf(" %d",bnxt[i]); puts("");

	vector<vector<int>> dp(alen,vector<int>(blen,INT_MIN)); dp[0][0]=0;
	REP(i,slen) {
		vector<vector<int>> ndp(alen,vector<int>(blen,INT_MIN));
		REP(j,alen) REP(k,blen) if(dp[j][k]!=INT_MIN) {
			if(s[i]!='*') {
				upd(ndp,j,k,dp[j][k],s[i]);
			} else {
				upd(ndp,j,k,dp[j][k],'-');
				upd(ndp,j,k,dp[j][k],a[j]);
				upd(ndp,j,k,dp[j][k],b[k]);
			}
		}
		dp=ndp;
	}
	int ret=INT_MIN; REP(j,alen) REP(k,blen) ret=max(ret,dp[j][k]); return ret;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%s",a); alen=strlen(a);
	scanf("%s",b); blen=strlen(b);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}