#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
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
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

int n;
char g[3][3];
char ret[1000][1000];

void go(int x,int y,int k,char c) {
	if(k==0) { ret[x][y]=c; return; }
	REP(i,n) REP(j,n) {
		go(n*x+i,n*y+j,k-1,c=='.'&&g[i][j]=='.'?'.':'*');
	}
}


void run() {
	int k; scanf("%d%d",&n,&k);
	REP(i,n) REP(j,n) scanf(" %c",&g[i][j]);
	go(0,0,k,'.');
	int size=1; REP(i,k) size*=n;
	REP(i,size) { ret[i][size]='\0'; printf("%s\n",ret[i]); }
}

int main() {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}