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
struct Op { int a,b,c; Op() {} Op(int a,int b,int c):a(a),b(b),c(c) {} };

int n;
char s[MAXN+1];
vector<Op> ans;

void flip(int a) {
	if(s[a]=='0') s[a]='1'; else s[a]='0';
}
void flip(int a,int b,int c) {
	//printf("%s: flipping %d %d %d\n",s,a,b,c);
	ans.PB(Op(a,b,c));
	flip(a); flip(b); flip(c);
}

int dp[2][1<<18];
Op act[2][1<<18];
int q[1<<18],qhead,qtail;

void precalc() {
	REP(kind,2) {
		int len=kind==0?min(n,n%6+12):12;
		REP(i,1<<len) dp[kind][i]=INT_MAX; qhead=qtail=0;
		if(kind==0) {
			dp[kind][0]=0,q[qhead++]=0;
		} else {
			REP(i,1<<6) dp[kind][i]=0,q[qhead++]=i;
		}
		while(qtail<qhead) {
			int at=q[qtail++];
			REP(i,len) FOR(j,i+1,len) {
				int k=j+(j-i); if(k>=len) break;
				int to=at^(1<<i)^(1<<j)^(1<<k);
				if(dp[kind][to]!=INT_MAX) continue;
				dp[kind][to]=dp[kind][at]+1,act[kind][to]=Op(i,j,k),q[qhead++]=to;
			}
		}
		//int mx=0; REP(i,1<<len) mx=max(mx,dp[kind][i]); printf("%d: %d (%d)\n",kind,mx,len);
	}
}

bool solve() {
	ans.clear();
	int rem=n,last=min(n,n%6+12);
	while(rem>last) {
		int at=0,off=rem-12; REP(i,12) if(s[off+i]=='1') at|=1<<i;
		while(dp[1][at]!=0) {
			Op cur=act[1][at];
			flip(off+cur.a,off+cur.b,off+cur.c);
			at^=(1<<cur.a)^(1<<cur.b)^(1<<cur.c);
		}
		rem-=6;
	}
	{
		int at=0; REP(i,rem) if(s[i]=='1') at|=1<<i;
		while(dp[0][at]!=0) {
			if(dp[0][at]==INT_MAX) return false;
			Op cur=act[0][at];
			flip(cur.a,cur.b,cur.c);
			at^=(1<<cur.a)^(1<<cur.b)^(1<<cur.c);
		}
	}
	return true;
}



void run() {
	scanf("%d",&n); REP(i,n) scanf(" %c",&s[i]); s[n]='\0';
	precalc();
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n",SZ(ans)); REPSZ(i,ans) printf("%d %d %d\n",ans[i].a+1,ans[i].b+1,ans[i].c+1);
}


char orig[MAXN+1];

void research() {
	FORE(len,3,25) {
		n=len;
		printf("%d:\n",len);
		precalc();
		REP(mask,1<<len) {
			REP(i,len) orig[i]=s[i]='0'+((mask>>i)&1); orig[len]=s[len]='\0';
			bool res=solve();
			if(res) REP(i,len) assert(s[i]=='0');
			if(res) assert(SZ(ans)<=len/3+12);
			if(!res) printf("%d\n",len);
		}
	}
}

void stress() {
	REP(rep,1000) {
		n=MAXN;
		REP(i,n) s[i]='0'+rand()%2; s[n]='\0';
		precalc();
		bool res=solve();
		assert(res);
		assert(SZ(ans)<=n/3+12);
		printf(".");
	}
}

int main() {
	//research();
	//stress();
	run();
	return 0;
}