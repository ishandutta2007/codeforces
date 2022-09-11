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
const int MAXC=4*MAXN+2;
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int len,na,nb;
int al[MAXN],ar[MAXN];
int bl[MAXN],br[MAXN];

int c[MAXC],nc;

int amn[MAXC];
int bmn[MAXC];

int delta[MAXC+1][3];

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { if((a-=b)<0) a+=MOD; }
void run() {
	scanf("%d%d%d",&len,&na,&nb); REP(i,na) scanf("%d%d",&al[i],&ar[i]),--al[i]; REP(i,nb) scanf("%d%d",&bl[i],&br[i]),--bl[i];
	
	nc=0; c[nc++]=0,c[nc++]=len; REP(i,na) c[nc++]=al[i],c[nc++]=ar[i]; REP(i,nb) c[nc++]=bl[i],c[nc++]=br[i];
	sort(c,c+nc); nc=unique(c,c+nc)-c;
	REP(i,na) al[i]=lower_bound(c,c+nc,al[i])-c,ar[i]=lower_bound(c,c+nc,ar[i])-c-1; REP(i,nb) bl[i]=lower_bound(c,c+nc,bl[i])-c,br[i]=lower_bound(c,c+nc,br[i])-c-1;
	//printf("a:"); REP(i,na) printf(" %d..%d",al[i],ar[i]); puts("");
	//printf("b:"); REP(i,nb) printf(" %d..%d",bl[i],br[i]); puts("");

	REP(i,nc) amn[i]=nc-1; REP(i,na) amn[al[i]]=min(amn[al[i]],ar[i]); for(int i=nc-2;i>=0;--i) amn[i]=min(amn[i],amn[i+1]);
	REP(i,nc) bmn[i]=nc-1; REP(i,nb) bmn[bl[i]]=min(bmn[bl[i]],br[i]); for(int i=nc-2;i>=0;--i) bmn[i]=min(bmn[i],bmn[i+1]);
	//printf("amn:"); REP(i,nc-1) printf(" %d",amn[i]); puts("");
	//printf("bmn:"); REP(i,nc-1) printf(" %d",bmn[i]); puts("");

	REPE(i,nc) REP(j,3) delta[i][j]=0; delta[0][2]=1; delta[1][2]=-1;
	REP(i,nc) REP(j,3) {
		int cur=delta[i][j];
		inc(delta[i+1][j],delta[i][j]);
		//printf("%d %d: %d\n",i,j,cur);
		if(i==nc-1) continue;
		if(cur==0) continue;
		REP(k,3) {
			if(j==0&&k==0||j==1&&k==1) continue;
			if(k==0) { // b
				inc(delta[i+1][k],cur);
				dec(delta[amn[i]+1][k],cur);
			}
			if(k==1) { // a
				inc(delta[i+1][k],cur);
				dec(delta[bmn[i]+1][k],cur);
			}
			if(k==2) { // a+b
				int w=(pw(2,c[i+1]-c[i])+MOD-2)%MOD;
				int v=(ll)w*cur%MOD;
				inc(delta[i+1][k],v);
				dec(delta[i+2][k],v);
			}
		}
	}
	int ret=0; REP(j,3) inc(ret,delta[nc-1][j]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}