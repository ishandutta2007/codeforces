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

int n;
int a[MAXN];

pair<int,int> b[MAXN]; int nb;
int prv[MAXN],nxt[MAXN],head,tail; bool alive[MAXN];

priority_queue<pair<int,int> > q;

void kill(int u) {
	alive[u]=false;
	if(prv[u]==-1) head=nxt[u]; else nxt[prv[u]]=nxt[u];
	if(nxt[u]==-1) tail=prv[u]; else prv[nxt[u]]=prv[u];
}
void trymerge(int u,int v) {
	if(u==-1||v==-1||b[u].first!=b[v].first) return;
	b[u].second+=b[v].second; q.push(MP(b[u].second,-u));
	kill(v);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	nb=0;
	for(int l=0,r=0;l<n;l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		b[nb++]=MP(a[l],r-l);
	}
	head=0,tail=nb-1; REP(i,nb) alive[i]=true,prv[i]=i==head?-1:i-1,nxt[i]=i==tail?-1:i+1;

	int ret=0;
	q=priority_queue<pair<int,int> >();
	REP(i,nb) q.push(MP(b[i].second,-i));
	while(!q.empty()) {
		int at=-q.top().second,val=q.top().first; q.pop();
		if(!alive[at]||b[at].second!=val) continue;
		//printf("killing %d*%d (original group %d)\n",b[at].second,b[at].first,at+1);
		++ret;
		kill(at);
		trymerge(prv[at],nxt[at]);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}