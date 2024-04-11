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
const int MAXP=8;

int n;
int val[MAXN];
vector<int> adj[MAXN];

int p[MAXP],np;
int ans[MAXN];

void go(int at,int par,vector<pair<int,int> > mn,vector<pair<int,int> > mn2,int noroot) {
	REP(i,np) { int cnt=0,rem=val[at]; while(rem%p[i]==0) ++cnt,rem/=p[i]; if(cnt<mn[i].first) mn2[i]=mn[i],mn[i]=MP(cnt,at); else if(cnt<mn2[i].first) mn2[i]=MP(cnt,at); }
	if(at!=0) {
		noroot=gcd(noroot,val[at]);
		ans[at]=noroot;
		REP(i,np) { int skip=mn[i].second,cur=1; REP(j,np) { int cnt=mn[j].second!=skip?mn[j].first:mn2[j].first; REP(k,cnt) cur*=p[j]; } if(cur>ans[at]) ans[at]=cur; }
	} else {
		ans[at]=val[at];
	}
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		go(to,at,mn,mn2,noroot);
	}
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	np=0; { int rem=val[0]; for(int i=2;i*i<=rem;++i) if(rem%i==0) { p[np++]=i; while(rem%i==0) rem/=i; } if(rem!=1) p[np++]=rem; }

	vector<pair<int,int> > mn(np,MP(INT_MAX,-1)),mn2(np,MP(INT_MAX,-1));
	go(0,-1,mn,mn2,0);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}