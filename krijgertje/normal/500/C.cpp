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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int nbook,nneed;
int w[500];
int need[1000];

bool inorder[500];
int order[500],norder;

void run() {
	scanf("%d%d",&nbook,&nneed);
	REP(i,nbook) scanf("%d",&w[i]);
	REP(i,nneed) { scanf("%d",&need[i]); --need[i]; }
	REP(i,nbook) inorder[i]=false; norder=0;
	REP(i,nneed) if(!inorder[need[i]]) { order[norder++]=need[i]; inorder[need[i]]=true; }

	int ret=0;
	REP(i,nneed) {
		int at=-1,sum=0; REP(j,norder) if(order[j]==need[i]) { at=j; break; } else { sum+=w[order[j]]; } assert(at!=-1);
		ret+=sum;
		for(int j=at;j>0;--j) swap(order[j],order[j-1]);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}