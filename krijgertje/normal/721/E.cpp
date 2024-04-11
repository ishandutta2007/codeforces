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

int len,n,dsong,dpause;

int sx[MAXN],tx[MAXN];
int smx[MAXN],umx[MAXN],ux[MAXN];

void supd(int i,int val) {
	if(i<n&&val>smx[i]) smx[i]=val;
}
void uupd(int i,int val,int x) {
	if(i>=n) return; if(x<sx[i]) x=sx[i];
	int dx=tx[i]-x,cnt=dx/dsong; val+=cnt; x+=cnt*dsong;
	if(val>umx[i]||val==umx[i]&&x<ux[i]) umx[i]=val,ux[i]=x;
}
void advance(int &i,int x) {
	while(i<n&&tx[i]<x) ++i;
}

void run() {
	scanf("%d%d%d%d",&len,&n,&dsong,&dpause);
	REP(i,n) scanf("%d%d",&sx[i],&tx[i]);

	memset(smx,-1,sizeof(smx)); memset(umx,-1,sizeof(umx)); smx[0]=0;
	int j=0;
	REP(i,n) {
		uupd(i,smx[i],sx[i]);
		supd(i+1,smx[i]);
		advance(j,ux[i]+dpause);
		uupd(j,umx[i],ux[i]+dpause);
		supd(j+1,umx[i]);
		//printf("%d: smx=%d umx=%d ux=%d\n",i,smx[i],umx[i],ux[i]);
	}
	int ret=0; REP(i,n) if(smx[i]>ret) ret=smx[i]; REP(i,n) if(umx[i]>ret) ret=umx[i]; printf("%d\n",ret);
}


int main() {
	run();
	return 0;
}