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
const int MAXALPH=17;

int n,nalph;
char s[MAXN+1];
int allowed[MAXALPH][MAXALPH];

int nxt[26];
int adjmask[1<<MAXALPH][MAXALPH];
bool valid[1<<MAXALPH];
bool can[1<<MAXALPH];
int q[1<<MAXALPH],qhead,qtail;
int cnt[MAXALPH];

pair<int,int> o[MAXALPH]; int no;

int solve() {
	REP(i,nalph) nxt[i]=-1;
	REP(mask,1<<nalph) REP(j,nalph) adjmask[mask][j]=0;
	for(int i=n-1;i>=0;--i) {
		no=0; REP(j,nalph) if(nxt[j]!=-1) o[no++]=MP(nxt[j],j); sort(o,o+no);
		int mask=0,x=s[i]-'a';
		//printf("%d:",i); REP(j,no) printf(" %d=%d",o[j].first,o[j].second); puts("");
		REP(j,no) { int y=o[j].second; if(!allowed[x][y]) adjmask[mask][x]|=1<<y; if(y==x) break; mask|=1<<y; }
		nxt[x]=i;
	}
	REP(mask,1<<nalph) REP(x,nalph) REP(z,nalph) if(z!=x) adjmask[mask|(1<<z)][x]|=adjmask[mask][x]&~(1<<z);
	//REP(mask,1<<nalph) REP(x,nalph) REP(y,nalph) if(adjmask[mask][x]&(1<<y)) printf("%x -> %c%c\n",mask,'a'+x,'a'+y);
	REP(mask,1<<nalph) { valid[mask]=true; REP(x,nalph) REP(y,nalph) if(!allowed[x][y]&&(adjmask[mask][x]&(1<<y))!=0) valid[mask]=false; }
	REP(mask,1<<nalph) can[mask]=false; qhead=qtail=0;
	assert(valid[0]); can[0]=true,q[qhead++]=0;
	while(qtail<qhead) { int mask=q[qtail++]; REP(z,nalph) if(valid[mask|(1<<z)]&&!can[mask|(1<<z)]) can[mask|(1<<z)]=true,q[qhead++]=mask|(1<<z); }
	REP(i,nalph) cnt[i]=0; REP(i,n) ++cnt[s[i]-'a'];
	int ret=INT_MAX;
	REP(mask,1<<nalph) if(can[mask]) { int cur=0; REP(x,nalph) if((mask&(1<<x))==0) cur+=cnt[x]; ret=min(ret,cur); }
	return ret;
}

void run() {
	scanf("%d%d",&n,&nalph);
	scanf("%s",s);
	REP(i,nalph) REP(j,nalph) scanf("%d",&allowed[i][j]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}