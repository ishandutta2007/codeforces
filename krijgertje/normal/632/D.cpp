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

const int MAXN=1000000;
const int MAXVAL=1000000;

int n,lim;
int x[MAXN];
int cnt[MAXVAL+1];
int dv[MAXVAL+1];
int retval[MAXN],nretval;

int calc(int x,int cur) {
	if(x==1) return cnt[cur];
	int ret=0;
	int y=x,nr=0; while(dv[y]==dv[x]) y/=dv[x],++nr;
	REPE(i,nr) {
		ret+=calc(y,cur);
		cur*=dv[x];
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d",&x[i]);
	memset(cnt,0,sizeof(cnt));
	REP(i,n) if(x[i]<=MAXVAL) ++cnt[x[i]];

	memset(dv,-1,sizeof(dv));
	FORE(i,2,MAXVAL) if(dv[i]==-1) for(int j=i;j<=MAXVAL;j+=i) dv[j]=i;

	int ret=-1,reti=-1;
	FORE(i,1,lim) { int cur=calc(i,1); if(cur>ret) ret=cur,reti=i; }
	nretval=0; REP(i,n) if(reti%x[i]==0) retval[nretval++]=i+1;
	printf("%d %d\n",reti,ret);
	REP(i,nretval) { if(i!=0) printf(" "); printf("%d",retval[i]); } puts("");
	
}

int main() {
	run();
	return 0;
}