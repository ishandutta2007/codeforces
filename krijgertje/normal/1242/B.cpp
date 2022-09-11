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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=100000;

int n,m;
vector<int> adj[MAXN];

int head,prv[MAXN],nxt[MAXN],tail;
int q[MAXN],qhead,qtail;

void remove(int x) {
	if(prv[x]!=-1) nxt[prv[x]]=nxt[x]; else { assert(head==x); head=nxt[x]; }
	if(nxt[x]!=-1) prv[nxt[x]]=prv[x]; else { assert(tail==x); tail=prv[x]; }
}

int solve() {
	REP(i,n) sort(adj[i].begin(),adj[i].end());

	head=0; REP(i,n) prv[i]=i==0?-1:i-1,nxt[i]=i==n-1?-1:i+1; tail=n-1;
	qhead=qtail=0;
	int ret=-1;
	while(head!=-1) {
		int fst=head; remove(fst); q[qhead++]=fst; ++ret;
		while(qtail<qhead) {
			int at=q[qtail++];
			int i=0;
			for(int x=head;x!=-1;x=nxt[x]) {
				while(i<SZ(adj[at])&&adj[at][i]<x) ++i;
				if(i>=SZ(adj[at])||adj[at][i]!=x) { remove(x); q[qhead++]=x; }
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b),adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}