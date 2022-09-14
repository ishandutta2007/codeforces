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

const int MAXLEN=15;

ll dp[MAXLEN+1][2]; // dp[i][j] = #ways to fill the first i characters (using the mx-digit iff j==1)
ll dpleq[MAXLEN+1][2]; // dpleq[i] = #ways to fill the first i characters so that that part is <= the corresponding part of s (using the mx-digit iff j==1)

inline int conv(char c) { if(isdigit(c)) return c-'0'; if(islower(c)) return c-'a'+10; assert(false); }
ll calc(char* s) {
	//printf("s=%s\n",s);
	int slen=strlen(s);
	ll ret=0;
	REP(mx,16) {
		int pos=mx/4,off=mx%4; if(pos>=slen) continue;
		memset(dp,0,sizeof(dp)); memset(dpleq,0,sizeof(dpleq));
		dp[0][0]=dpleq[0][0]=1;
		REP(i,slen) REP(j,2) REPE(k,mx) {
			if(i==pos&&(k&(1<<off))==0) continue;
			int nj=j==1||k==mx?1:0;
			dp[i+1][nj]+=dp[i][j];
			if(k<conv(s[i])) dpleq[i+1][nj]+=dp[i][j]; else if(k==conv(s[i])) dpleq[i+1][nj]+=dpleq[i][j];
		}
		ll cur=dpleq[slen][1];
		//printf("\t%d=%lld\n",mx,cur);
		ret+=cur;
	}
	//printf("->%lld\n",ret);
	return ret;
}
void dec(char *s) {
	for(int i=0;;++i) if(s[i]=='0') s[i]='f'; else { assert(s[i]!='\0'); if(s[i]=='a') s[i]='9'; else --s[i]; break; }
	int slen=strlen(s); while(slen>=2&&s[slen-1]=='0') --slen; s[slen]='\0';
}

int nq;
char sl[MAXLEN+1],sr[MAXLEN+1];

ll solve() {
	reverse(sl,sl+strlen(sl)); reverse(sr,sr+strlen(sr));
	ll ret=calc(sr);
	if(strcmp(sl,"0")!=0) { dec(sl); ret-=calc(sl); }
	return ret;
}

void run() {
	scanf("%d",&nq);
	REP(qi,nq) {
		scanf("%s%s",sl,sr); 
		printf("%lld\n",solve());
	}
}

int main() {
	run();
	return 0;
}