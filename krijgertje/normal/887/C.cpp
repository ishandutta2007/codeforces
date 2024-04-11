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


void exec(int op[3][4],int s[24],int t[24]) {
	REP(i,24) t[i]=-1;
	REP(i,3) REP(j,4) {
		int a=op[i][j],b=op[i][(j+1)%4];
		t[b]=s[a];
	}
	REP(i,24) if(t[i]==-1) t[i]=s[i];
}
int x[24],y[24];
void exec3(int op[3][4],int s[24],int t[24]) {
	exec(op,s,x); exec(op,x,y); exec(op,y,t);
}

int ops[3][3][4]={
	{{13,14,16,15},{1,5,9,24},{3,7,11,22}},
	{{1,2,4,3},{6,14,22,18},{5,13,21,17}},
	{{5,6,8,7},{3,17,10,16},{4,19,9,14}}
};

int s[24];
int t[24];


void run() {
	REP(i,24) scanf("%d",&s[i]);
	REP(i,3) REP(j,3) REP(k,4) --ops[i][j][k];
	bool ret=false;
	REP(i,3) {
		REP(ii,2) {
			if(ii==0) exec(ops[i],s,t); else exec3(ops[i],s,t);
			bool ok=true; REP(j,24) if(j%4!=0&&t[j]!=t[j-1]) ok=false;
			if(ok) ret=true;
			//printf("%d:",i); REP(j,24) printf(" %d",t[j]); puts("");
		}
	}
	printf("%s\n",ret?"YES":"NO");
}

int main() {
	run();
	return 0;
}