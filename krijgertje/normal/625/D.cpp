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

const int MAXLEN=100001;

char s[MAXLEN+1]; int slen;

int dp[2][MAXLEN][2][2]; // dp[off][i][rc][nlc] is t[off+i]+t[slen-i-1] which makes t[off+i..slen-i-1]+tr[off+i..slen-i-1]+rc='nlc'+s[off+i..slen-i-1] i<=(slen-off-1)/2

char t[MAXLEN+1];
bool go(int off,int i,int rc,int nlc) {
	if(off+i==slen-i-1) {
		int want=(s[off+i]-'0')+10*nlc-rc;
		if(want%2!=0) return false;
		t[off+i]='0'+want/2; return true;
	} else if(off+i+1==slen-i-1) {
		int want=(s[off+i+1]-'0')+10*(s[off+i]-'0')+100*nlc-rc;
		if(want%11!=0) return false;
		t[off+i]='0'+(want/11+1)/2; t[off+i+1]='0'+(want/11)/2; return true;
	} else {
		int xr=s[slen-i-1]-'0'-rc,nrc=0;
		if(xr<0) xr+=10,++nrc;
		// possibly xr+=10,++nrc
		int xl=s[off+i]-'0'+10*nlc,lc=0;
		// possibly xl--,++lc
		if(xl%10!=xr%10) --xl,++lc;
		if(xl!=xr) xr+=10,++nrc;
		if(xl!=xr) return false;
		if(i==0&&xl==0||xl>18) return false;
		t[off+i]='0'+(xl+1)/2; t[slen-i-1]='0'+(xl)/2;
		return go(off,i+1,nrc,lc);
	}
}

void run() {
	scanf("%s",s); slen=strlen(s);
	t[slen]='\0';
	if(go(0,0,0,0)) printf("%s\n",t);
	else if(s[0]=='1'&&go(1,0,0,1)) printf("%s\n",t+1);
	else printf("0\n");

/*
	REP(off,2) {
		for(int i=(slen-1-off)/2;i>=0;--i) REP(rc,2) REP(nlc,2) {
			dp[off][i][rc][nlc]=-1;
			if(off+i==slen-i-1) {
				int want=(s[off+i]-'0')+10*nlc-rc;
				if(want%2==0) dp[off][i][rc][nlc]=want;
			} else if(off+i+1==slen-i-1) {
				int want=(s[off+i+1]-'0')+10*(s[off+i]-'0')+100*nlc-rc;
				if(want%11==0) dp[off][i][rc][nlc]=want/11;
			} else {
				//xr==s[slen-i-1]-'0'-rc+?*10
				int xr=s[slen-i-1]-'0'-rc,nrc=0;
				if(xr<0) want+=10,++nrc;
				// possibly xr+=10,++nrc
				int xl=s[off+i]-'0'+10*nlc;
				// possibly xl--,++lc
				if(xl%10!=xr%10) --xl,++lc;
				if(xl!=xr) xr+=10,++nrc;
				if(xl!=xr) continue;
				//int r=x+rc,nrc=0; if(r>=10) r-=10,++nrc; if(s[slen-i-1]!='0'+r) continue;
				//int lc=0; int l=x,cnlc=0; if(l>=10) l-=10,++cnlc; if(cnlc!=nlc||s[off+i]!='0'+l) ++lc,if(++l>=0) l-=10,cnlc++; if(cnlc!=nlc||s[off+i]!='0'+l) continue;
				if(dp[off][i+1][nrc][lc]==-1) continue;
				dp[off][i][rc][nlc]=xl; break;
			}
		}
	}
	*/



	// abcdef
	// fedcba

}

int main() {
	run();
	return 0;
}