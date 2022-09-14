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

const int MAXN=200000+2;
typedef struct S { int x,p; } S;
bool operator<(const S &a,const S &b) { return a.x<b.x; }

int dst,cap,n;
S s[MAXN];

int q[MAXN],qhead,qtail;

void input() {
	scanf("%d%d%d",&dst,&cap,&n); REP(i,n) scanf("%d%d",&s[i].x,&s[i].p);
	s[n].x=0,s[n].p=INT_MAX,++n; s[n].x=dst,s[n].p=INT_MAX,++n; sort(s,s+n);
}

ll solve() {
	ll ret=0; int at=0,to=1,have=cap; qhead=qtail=0;
	while(s[at].x!=dst) {
		while(to<n&&s[to].x<=s[at].x+cap&&(qhead==qtail||s[q[qhead]].p>=s[at].p)) {
			while(qhead<qtail&&s[to].p<=s[q[qtail-1]].p) --qtail;
			q[qtail++]=to++;
		}
		if(qhead==qtail) return -1;
		int nxt=q[qhead++];
		int cur=s[at].p<=s[nxt].p?min(dst-s[at].x-have,cap-have):max(0,s[nxt].x-s[at].x-have);
		//printf("%d to %d: tanking %d for %d each\n",s[at].x,s[nxt].x,cur,s[at].p);
		ret+=(ll)cur*s[at].p; have+=cur;
		have-=s[nxt].x-s[at].x; at=nxt;
	}
	return ret;
}

void run() {
	input();
	ll ret=solve();
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}