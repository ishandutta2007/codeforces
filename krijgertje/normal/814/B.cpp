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

const int MAXN=1000;

int n;
int a[MAXN];
int b[MAXN];
int p[MAXN];

int diff[MAXN],ndiff;
bool have[MAXN+1];
int rem[MAXN],nrem;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	FORE(i,1,n) have[i]=false;
	ndiff=0; REP(i,n) if(a[i]!=b[i]) diff[ndiff++]=i; else p[i]=a[i],have[a[i]]=true;
	nrem=0; FORE(i,1,n) if(!have[i]) rem[nrem++]=i;
	assert(nrem==ndiff);
	if(ndiff==1) {
		int x=diff[0];
		p[x]=rem[0]; assert(p[x]!=a[x]&&p[x]!=b[x]);
	} else if(ndiff==2) {
		bool found=false;
		// printf("diff=[%d,%d] rem=[%d,%d]\n",diff[0],diff[1],rem[0],rem[1]);
		REP(i,2) if(!found) REP(j,2) {
			int x=diff[i],y=diff[1-i]; int u=rem[j],v=rem[1-j];
			if(a[x]!=u&&b[x]==u&&a[y]==v&&b[y]!=v) { found=true; p[x]=u; p[y]=v; break; }
		}
		assert(found);
	} else {
		assert(false);
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",p[i]); } puts("");
}

int main() {
	run();
	return 0;
}