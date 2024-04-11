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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXWORD=100000;
const int MOD=998244353;
const int MAXLEN=10;
const int MAXALPH=26+26+10;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int nword;
char word[MAXWORD][MAXLEN+1];

vector<string> bylen[MAXLEN+1];
char alph[4*MAXWORD+1]; int nalph;

int cnt[MAXALPH][MAXALPH];
int dp[MAXALPH][MAXALPH][MAXALPH];

int calc(int len) {
	if(SZ(bylen[len])==0) return 0;
	//printf("%d:",len); REPSZ(i,bylen[len]) printf(" %s",bylen[len][i].c_str()); puts("");
	nalph=0; REPSZ(i,bylen[len]) alph[nalph++]=bylen[len][i][0],alph[nalph++]=bylen[len][i][SZ(bylen[len][i])-1]; sort(alph,alph+nalph); nalph=unique(alph,alph+nalph)-alph; alph[nalph]='\0'; assert(nalph<=MAXALPH);
	//printf("alph=%s nalph=%d MAXALPH=%d\n",alph,nalph,MAXALPH);
	memset(cnt,0,sizeof(cnt));
	REPSZ(i,bylen[len]) {
		int a=lower_bound(alph,alph+nalph,bylen[len][i][0])-alph,b=lower_bound(alph,alph+nalph,bylen[len][i][SZ(bylen[len][i])-1])-alph;
		++cnt[a][b];
	}
	int ret=0;
	REP(a,nalph) FOR(b,a,nalph) FOR(c,b,nalph) { dp[a][b][c]=0; REP(i,nalph) dp[a][b][c]=(dp[a][b][c]+(ll)cnt[i][a]*cnt[i][b]*cnt[i][c])%MOD; }
	REP(a,nalph) FOR(b,a,nalph) FOR(c,b,nalph) FOR(d,c,nalph) {
		int cur=(ll)dp[a][b][c]*dp[a][b][d]%MOD*dp[a][c][d]%MOD*dp[b][c][d]%MOD;
		int ways=a==d?1:a==c||b==d?4:a==b&&c==d?6:a==b||b==c||c==d?12:24;
		ret=(ret+(ll)cur*ways)%MOD;
	}
	return ret;
}

int solve() {
	REPE(i,MAXLEN) bylen[i].clear();
	REP(i,nword) { string s=word[i]; bylen[SZ(s)].PB(s); reverse(s.begin(),s.end()); bylen[SZ(s)].PB(s); }
	REPE(i,MAXLEN) { sort(bylen[i].begin(),bylen[i].end()); bylen[i].erase(unique(bylen[i].begin(),bylen[i].end()),bylen[i].end()); }
	int ret=0;
	REPE(i,MAXLEN) inc(ret,calc(i));
	return ret;
}

void run() {
	scanf("%d",&nword);
	REP(i,nword) scanf("%s",word[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}