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

const int MAXN=200000;

int n[2];
ll cnt[2][MAXN]; char c[2][MAXN];

int nxt[MAXN]; // p[1..nxt[i]) is longest suffix of p[1..i) that is also a prefix

void run() {
	REP(i,2) scanf("%d",&n[i]);
	REP(i,2) REP(j,n[i]) scanf("%I64d-%c",&cnt[i][j],&c[i][j]);
	//REP(i,2) { REP(j,n[i]) { if(j!=0) printf(" "); printf("%I64d-%c",cnt[i][j],c[i][j]); } puts(""); }
	REP(i,2) {
		int nn=0;
		REP(j,n[i]) if(nn==0||c[i][j]!=c[i][nn-1]) cnt[i][nn]=cnt[i][j],c[i][nn]=c[i][j],++nn; else cnt[i][nn-1]+=cnt[i][j];
		n[i]=nn;
	}
	//REP(i,2) { REP(j,n[i]) { if(j!=0) printf(" "); printf("%I64d-%c",cnt[i][j],c[i][j]); } puts(""); }

	ll ret=0;
	if(n[1]==1) {
		REP(i,n[0]) if(c[0][i]==c[1][0]&&cnt[0][i]>=cnt[1][0]) ret+=cnt[0][i]-cnt[1][0]+1;
	}
	if(n[1]==2) {
		REP(i,n[0]-1) if(c[0][i]==c[1][0]&&c[0][i+1]==c[1][1]&&cnt[0][i]>=cnt[1][0]&&cnt[0][i+1]>=cnt[1][1]) ++ret;
	}
	if(n[1]>=3) {
		int at=1; // p[1..at) is longest prefix of p[1..] that is a suffix of s[1..i)
		nxt[1]=nxt[2]=1;
		FOR(i,2,n[1]-1) {
			nxt[i+1]=nxt[i];
			while(nxt[i+1]!=1&&(c[1][i]!=c[1][nxt[i+1]]||cnt[1][i]!=cnt[1][nxt[i+1]])) nxt[i+1]=nxt[nxt[i+1]];
			if(c[1][i]==c[1][nxt[i+1]]&&cnt[1][i]==cnt[1][nxt[i+1]]) ++nxt[i+1];
		}
		//printf("nxt:"); FOR(i,1,n[1]) printf(" %d",nxt[i]); puts("");
		FOR(i,1,n[0]-1) {
			while(at!=1&&(c[0][i]!=c[1][at]||cnt[0][i]!=cnt[1][at])) at=nxt[at];
			if(c[0][i]==c[1][at]&&cnt[0][i]==cnt[1][at]) ++at;
			if(at==n[1]-1) {
				if(c[0][i-n[1]+2]==c[1][0]&&c[0][i+1]==c[1][at]&&cnt[0][i-n[1]+2]>=cnt[1][0]&&cnt[0][i+1]>=cnt[1][at]) ++ret;
				at=nxt[at];
			}
		}
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}