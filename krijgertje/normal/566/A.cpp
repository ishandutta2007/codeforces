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

const int MAXPAIRS=100000;
const int MAXCHARS=800000;
const int MAXNODES=MAXCHARS+1;

int npair;
char s[MAXCHARS+1]; int len;

int nnode,root;
int nxt[MAXNODES][26];
int lhead[MAXNODES];
int lnxt[2*MAXPAIRS];

int nret,retscore;
int retmatch[MAXPAIRS][2];

int stck[2][MAXPAIRS],nstck[2];

int createnode() { REP(i,26) nxt[nnode][i]=-1; lhead[nnode]=-1; return nnode++; }
void dfs(int at,int depth) {
	int a=nstck[0],b=nstck[1];
	REP(i,26) if(nxt[at][i]!=-1) {
		dfs(nxt[at][i],depth+1);
	}
	for(int x=lhead[at];x!=-1;x=lnxt[x]) if(x<npair) stck[0][nstck[0]++]=x; else stck[1][nstck[1]++]=x-npair;
	while(nstck[0]>a&&nstck[1]>b) {
		retscore+=depth;
		retmatch[nret][0]=stck[0][--nstck[0]];
		retmatch[nret][1]=stck[1][--nstck[1]];
		++nret;
	}
}



void run() {
	scanf("%d",&npair);
	nnode=0; root=createnode();	
	REP(i,2*npair) {
		scanf("%s",&s); len=strlen(s); int at=root;
		REP(j,len) {
			int x=s[j]-'a';
			if(nxt[at][x]==-1) nxt[at][x]=createnode();
			at=nxt[at][x];
		}
		lnxt[i]=lhead[at]; lhead[at]=i;
	}
	nret=retscore=nstck[0]=nstck[1]=0;
	dfs(root,0);
	printf("%d\n",retscore);
	REP(i,nret) printf("%d %d\n",retmatch[i][0]+1,retmatch[i][1]+1);
}


int main() {
	run();
	return 0;
}