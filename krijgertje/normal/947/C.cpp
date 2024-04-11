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

const int MAXN=300000;
const int LG=30;
const int MAXNODE=LG*MAXN+1;
struct Node { int cnt,c[2]; Node():cnt(0) { c[0]=c[1]=-1; } };

int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];

Node r[MAXNODE]; int nr;

void rprint(int at,int dep=0) {
	REP(i,dep) printf("  "); printf("%d=%d\n",at,r[at].cnt);
	REP(x,2) if(r[at].c[x]!=-1) rprint(r[at].c[x],dep+1);
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]);

	nr=0; r[nr++]=Node();
	REP(i,n) { int at=0; ++r[at].cnt; REP(j,LG) { int x=(b[i]>>(LG-j-1))&1; if(r[at].c[x]==-1) r[at].c[x]=nr,r[nr++]=Node(); at=r[at].c[x]; ++r[at].cnt; } }
	//rprint(0);

	REP(i,n) {
		int at=0; --r[at].cnt; c[i]=0;
		REP(j,LG) {
			int x=(a[i]>>(LG-j-1))&1; bool found=false;
			REP(k,2) {
				int y=x^k;
				if(r[at].c[y]==-1||r[r[at].c[y]].cnt==0) continue;
				at=r[at].c[y]; --r[at].cnt; found=true; c[i]|=k<<(LG-j-1); break;
			}
			assert(found);
		}
	}
	//rprint(0);

	REP(i,n) { if(i!=0) printf(" "); printf("%d",c[i]); } puts("");
}

int main() {
	run();
	return 0;
}