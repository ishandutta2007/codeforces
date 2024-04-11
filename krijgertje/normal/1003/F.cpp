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

const int MAXN=300;
const int MAXLEN=100000;

int n;
char buff[MAXLEN+1];

map<string,int> mp;
int id[MAXN],nid;
int len[MAXN];
string name[MAXN];

int lcp[MAXN+1][MAXN+1];



void run() {
	scanf("%d",&n);
	nid=0; REP(i,n) { scanf("%s",buff); if(!mp.count(buff)) { int cid=nid++; mp[buff]=cid; len[cid]=strlen(buff); name[cid]=buff; } id[i]=mp[buff]; }

	for(int i=n;i>=0;--i) for(int j=n;j>=0;--j) lcp[i][j]=i<n&&j<n&&id[i]==id[j]?1+lcp[i+1][j+1]:0;
	int orig=n-1; REP(i,n) orig+=len[id[i]];
	
	int best=0;
	REP(off,n) FORE(cnt,1,n-off) {
		int times=1;
		int at=off+cnt;
		while(at<n) { if(lcp[off][at]>=cnt) ++times,at+=cnt; else ++at; }
		if(times==1) continue;
		int before=cnt-1; REP(i,cnt) before+=len[id[off+i]];
		int after=cnt;
		best=max(best,times*(before-after));
	}
	printf("%d\n",orig-best);
}

int main() {
	run();
	return 0;
}