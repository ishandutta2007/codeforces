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

const int MAXN=120;
const int NP=5;
const int NC=6;

int n;
int t[MAXN][NP];
int nsolve[NP];
pair<int,bool> need[NP][NC];

int c[NP];

int score(int i) {
	int ret=0;
	REP(j,NP) if(t[i][j]!=-1) ret+=2*(c[j]+1)*(250-t[i][j]);
	return ret;
}
int calccur(int p,int q) {
	REP(i,NC) {
		int c=1,d=1<<i;
		int a=1,b=2<<i; // except when i=NC-1
		if(p*d>c*q) continue;
		if(i!=NC-1&&p*b<=a*q) continue;
		return i;
	}
	assert(false); return -1;
}

bool can(int nextra) {
	int me=0,opp=0;
	REP(i,NP) {
		bool meok=t[0][i]!=-1,oppok=t[1][i]!=-1;
		if(meok&&(!oppok||t[0][i]<=t[1][i])) c[i]=calccur(nsolve[i],n+nextra); else if(meok) c[i]=calccur(nsolve[i]+nextra,n+nextra); else c[i]=calccur(nsolve[i],n+nextra);
	}
	return score(0)>score(1);
}

pair<int,bool> calc(int p,int q,int i) {
	int c=1,d=1<<i;
	int a=1,b=2<<i; // except when i=NC-1
	int ret=0; bool correct=false;
	for(int it=0;;++it) {
		//if(i==NC-1) printf("0"); else printf("%d/%d",a,b); printf(" < %d/%d <= %d/%d\n",p,q,c,d); if(it>100) exit(0);
		if(p*d>c*q) {
			int cnt=(p*d-c*q+c-1)/c;
			ret+=cnt; q+=cnt;
			continue;
		}
		if(i!=NC-1&&p*b<=a*q) {
			int cnt=(a*q-b*p)/(b-a)+1;
			ret+=cnt; p+=cnt; q+=cnt; correct=true;
			continue;
		}
		return MP(ret,correct);
	}
}



void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,NP) scanf("%d",&t[i][j]);
	REP(i,NP) nsolve[i]=0; REP(i,n) REP(j,NP) if(t[i][j]!=-1) ++nsolve[j];
	REP(i,NP) REP(j,NC) need[i][j]=calc(nsolve[i],n,j);
	int ret=INT_MAX;
	if(can(0)) ret=0;
	REP(i,NP) REP(j,NC) if(need[i][j].first!=-1&&can(need[i][j].first)) ret=min(ret,need[i][j].first);
	printf("%d\n",ret>1000000007?-1:ret);
}

int main() {
	run();
	return 0;
}