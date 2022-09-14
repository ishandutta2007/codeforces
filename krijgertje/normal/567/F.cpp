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

const int MAXPAIRS=35;
const int MAXREQ=100;

int npair,nreq;
int ra[MAXREQ],rb[MAXREQ]; char rc[MAXREQ][3];

bool caneq(char *s) { return s[0]=='='||s[1]=='='; }
bool cangt(char *s) { return s[0]=='>'; }
bool canlt(char *s) { return s[0]=='<'; }
bool check(int s,int t,int p,int q) {
	//printf("checking [%d..%d] %d+%d\n",s,t,p,q);
	REP(i,nreq) {
		if((ra[i]==p||ra[i]==q)&&(rb[i]==p||rb[i]==q)) if(caneq(rc[i])) continue; else return false;
		if((ra[i]==p||ra[i]==q)) if(s<=rb[i]&&rb[i]<=t) if(canlt(rc[i])) continue; else return false; else if(cangt(rc[i])) continue; else return false;
		if((rb[i]==p||rb[i]==q)) if(s<=ra[i]&&ra[i]<=t) if(cangt(rc[i])) continue; else return false; else if(canlt(rc[i])) continue; else return false;
	}
	//printf("[%d..%d] %d+%d\n",s,t,p,q);
	return true;
}

ll mem[MAXPAIRS+1][2*MAXPAIRS];
ll go(int n,int off) {
	if(n==0) return 1;
	ll &ret=mem[n][off];
	if(ret==-1) {
		ret=0;
		if(check(off,off+2*n-1,off,off+1)) ret+=go(n-1,off+2);
		if(n!=1&&check(off,off+2*n-1,off,off+2*n-1)) ret+=go(n-1,off+1);
		if(n!=1&&check(off,off+2*n-1,off+2*n-2,off+2*n-1)) ret+=go(n-1,off);
		//printf("%d %d -> %lld\n",n,off,ret);
	}
	return ret;
}


void run() {
	scanf("%d%d",&npair,&nreq);
	REP(i,nreq) scanf("%d%s%d",&ra[i],&rc[i],&rb[i]),--ra[i],--rb[i];

	memset(mem,-1,sizeof(mem));
	cout<<go(npair,0)<<endl;
}

int main() {
	run();
	return 0;
}