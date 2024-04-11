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

int m;
int needperc;
int a[100],b[100];

int all[200],n;
int fst[200];
int nxt[200];
int to[200];

int cnt1[200][200];
int cnt2[200][200];

void run() {
	scanf("%d%d",&m,&needperc);
	REP(i,m) scanf("%d%d",&a[i],&b[i]);
	
	n=0; REP(i,m) all[n++]=a[i],all[n++]=b[i];
	sort(all,all+n); n=unique(all,all+n)-all;
	REP(i,m) a[i]=lower_bound(all,all+n,a[i])-all,b[i]=lower_bound(all,all+n,b[i])-all;
	//REP(i,m) printf("%d %d\n",a[i],b[i]);

	REP(i,n) fst[i]=-1;
	REP(i,m) {
		nxt[2*i+0]=fst[a[i]]; fst[a[i]]=2*i+0; to[2*i+0]=b[i];
		nxt[2*i+1]=fst[b[i]]; fst[b[i]]=2*i+1; to[2*i+1]=a[i];
	}
	//REP(i,n) { printf("%d:",i); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }

	memset(cnt1,0,sizeof(cnt1)); REP(i,n) for(int x=fst[i];x!=-1;x=nxt[x]) ++cnt1[i][to[x]];
	memset(cnt2,0,sizeof(cnt2)); REP(i,n) for(int x=fst[i];x!=-1;x=nxt[x]) for(int y=fst[to[x]];y!=-1;y=nxt[y]) if(x/2!=y/2) ++cnt2[i][to[y]];
	//REP(i,n) { REP(j,n) printf("%d ",cnt1[i][j]); puts(""); } puts("");
	//REP(i,n) { REP(j,n) printf("%d ",cnt2[i][j]); puts(""); } puts("");

	REP(i,n) {
		int deg=0; for(int x=fst[i];x!=-1;x=nxt[x]) ++deg;
		int cur=0; REP(j,n) if(i!=j&&cnt1[i][j]==0&&cnt2[i][j]*100>=needperc*deg) ++cur;
		printf("%d: %d",all[i],cur); REP(j,n) if(i!=j&&cnt1[i][j]==0&&cnt2[i][j]*100>=needperc*deg) printf(" %d",all[j]); puts("");
	}
}

int main() {
	run();
	return 0;
}