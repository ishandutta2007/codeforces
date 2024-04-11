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

const int MAXN=100000;

int n,m;
int kind[MAXN];
vector<int> dep[MAXN],rdep[MAXN];

int rem;
int outdeg[MAXN];
queue<int> q[2];

void process(int z) {
	while(!q[z].empty()) {
		int at=q[z].front(); q[z].pop();
		--rem;
		REPSZ(i,rdep[at]) {
			int to=rdep[at][i];
			if(--outdeg[to]==0) q[kind[to]].push(to);
		}
	}
}

void run() {
	scanf("%d%d",&n,&m); REP(i,n) scanf("%d",&kind[i]); REP(i,m) { int a,b; scanf("%d%d",&a,&b); dep[a].PB(b); rdep[b].PB(a); }

	REP(i,n) outdeg[i]=SZ(dep[i]);
	REP(j,2) q[j]=queue<int>(); REP(i,n) if(outdeg[i]==0) q[kind[i]].push(i);
	int ret=0; rem=n;
	while(rem>0) {
		process(0);
		if(rem==0) break;
		++ret; process(1);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}