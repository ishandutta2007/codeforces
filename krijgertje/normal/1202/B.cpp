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

const int MAXLEN=2000000;

char s[MAXLEN+1]; int slen;
int ans[10][10];

int cnt[10][10];
int cost[10][10];
int q[10],qhead,qtail;
void upd(int a,int b,int c) { if(cost[a][b]!=INT_MAX) return; cost[a][b]=c,q[qhead++]=b; }

void solve() {
	REP(x,10) REP(y,10) cnt[x][y]=0;
	REP(i,slen-1) ++cnt[s[i]-'0'][s[i+1]-'0'];
	REP(x,10) REP(y,10) {
		REP(a,10) {
			qhead=qtail=0; REP(b,10) cost[a][b]=INT_MAX;
			upd(a,(a+x)%10,0); upd(a,(a+y)%10,0);
			while(qtail<qhead) { int at=q[qtail++]; upd(a,(at+x)%10,cost[a][at]+1); upd(a,(at+y)%10,cost[a][at]+1); }
		}
		//REP(a,10) { printf("cost%d:",a); REP(b,10) printf(" %d",cost[a][b]); puts(""); }
		ans[x][y]=0; REP(a,10) REP(b,10) if(cnt[a][b]>0&&ans[x][y]!=-1) if(cost[a][b]==INT_MAX) ans[x][y]=-1; else ans[x][y]+=cost[a][b]*cnt[a][b];
	}
}

void run() {
	scanf("%s",s); slen=strlen(s);
	solve();
	REP(x,10) { REP(y,10) { if(y!=0) printf(" "); printf("%d",ans[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}