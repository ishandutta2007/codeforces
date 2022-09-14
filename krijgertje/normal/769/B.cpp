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

const int MAXN=100;

int n;
int a[MAXN];
bool know[MAXN];

int ret[MAXN][2],nret;
int q[MAXN],qhead,qtail;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	nret=0; REP(i,n) know[i]=false; know[0]=true; qhead=qtail=0; q[qhead++]=0;
	int to=0; bool onlypos=true;
	while(qtail<qhead) {
		int at=q[qtail++];
		while(a[at]>0) {
			while(to<n&&(know[to]||onlypos&&a[to]==0)) ++to;
			if(to>=n&&onlypos) { to=0; onlypos=false; continue; } if(to>=n) break;
			if(a[at]>0&&to<n) ret[nret][0]=at,ret[nret][1]=to,++nret,know[to]=true,q[qhead++]=to,--a[at];
		}
	}
	REP(i,n) if(!know[i]) { printf("-1\n"); return; }
	printf("%d\n",nret); REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
}

int main() {
	run();
	return 0;
}