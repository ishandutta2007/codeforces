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

const int MAXLEN=100000;
const char NAME[3][20]={"Kuro","Shiro","Katie"};

int nchanges;
char s[3][MAXLEN+1]; int len[3];

int mxscore[3];

int cnt[256];

void run() {
	scanf("%d",&nchanges); REP(i,3) scanf("%s",s[i]),len[i]=strlen(s[i]);

	REP(i,3) {
		memset(cnt,0,sizeof(cnt));
		REP(j,len[i]) ++cnt[(int)s[i][j]];
		mxscore[i]=0;
		REP(j,256) {
			int cur=cnt[j];
			if(cur+nchanges<=len[i]||nchanges>=2) cur=min(cur+nchanges,len[i]); else cur=len[i]-1;
			mxscore[i]=max(mxscore[i],cur);
		}
	}
	int retidx=0,retcnt=1; FOR(i,1,3) if(mxscore[i]>mxscore[retidx]) retidx=i,retcnt=1; else if(mxscore[i]==mxscore[retidx]) ++retcnt;
	if(retcnt==1) printf("%s\n",NAME[retidx]); else printf("Draw\n");




}

int main() {
	run();
	return 0;
}