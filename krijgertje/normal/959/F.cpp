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
const int MAXQ=100000;
const int MOD=1000000007;
const int MAXBIT=20;
struct Q { int cnt,want,id; };
bool operator<(const Q &a,const Q &b) { return a.cnt<b.cnt; }

int n,nq;
int a[MAXN];
Q q[MAXQ];
int ans[MAXQ];

int b[MAXN],nb;
int ways;

void init() {
	nb=0; ways=1;

}
void append(int x) {
	REP(i,nb) if((x^b[i])<x) x^=b[i];
	if(x==0) { ways=(ll)ways*2%MOD; return; }
	b[nb++]=x;
}
int solve(int x) {
	REP(i,nb) if((x^b[i])<x) x^=b[i];
	return x==0?ways:0;
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&a[i]); REP(i,nq) scanf("%d%d",&q[i].cnt,&q[i].want),q[i].id=i;

	sort(q,q+nq);
	int at=0; init();
	REP(i,nq) {
		while(at<q[i].cnt) append(a[at++]);
		ans[q[i].id]=solve(q[i].want);
	}
	REP(i,nq) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}