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

const int MAXN=500000;
const int MAXBITS=10;

int n;
int res[MAXBITS][2];

int calc(int a,char op,int b) { if(op=='|') return a|b; if(op=='&') return a&b; if(op=='^') return a^b; assert(false); return -1; }

void run() {
	REP(j,MAXBITS) REP(k,2) res[j][k]=k;
	scanf("%d",&n);
	REP(i,n) {
		char op; int x; scanf(" %c%d",&op,&x);
		REP(j,MAXBITS) REP(k,2) {
			int a=res[j][k],b=(x>>j)&1,c=calc(a,op,b);
			//if(j<=2) printf("%d %c %d = %d\n",a,op,b,c);
			res[j][k]=c;
		}
	}
	//REP(j,MAXBITS) { printf("%d:",j); REP(k,2) printf(" %d",res[j][k]); puts(""); }
	
	printf("%d\n",3);
	{ int x=0; REP(j,MAXBITS) if(res[j][0]==1&&res[j][1]==0) x|=1<<j; printf("^ %d\n",x); }
	{ int x=0; REP(j,MAXBITS) if(res[j][0]!=0||res[j][1]!=0) x|=1<<j; printf("& %d\n",x); }
	{ int x=0; REP(j,MAXBITS) if(res[j][0]==1&&res[j][1]==1) x|=1<<j; printf("| %d\n",x); }
}

int main() {
	run();
	return 0;
}