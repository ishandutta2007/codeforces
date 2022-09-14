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
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n;
int a[100];

int pmask[61];
int p[61],np,np1,np2;

int order[100];
bool ordercmp(const int &p,const int &q) { return a[p]<a[q]; }

int b[100];


int dp[101][1<<10];
int act[101][1<<10];

int best;
int bret[100];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);

	np=0; memset(pmask,0,sizeof(pmask));
	FORE(i,2,60) if(pmask[i]==0) { p[np++]=i; for(int j=i;j<=60;j+=i) pmask[j]|=1<<(np-1); }
	np1=0; while(np1<np&&p[np1]<=30) ++np1; np2=np-np1;
	//printf("%d (%d,%d)\n",np,np1,np2); REP(i,np) printf("%d\n",p[i]);

	REP(i,n) order[i]=i; sort(order,order+n,ordercmp);
	//REP(i,n) printf("%d ",order[i]); puts("");

	REPE(i,np2) {
		if(i>n) continue;
		memset(b,-1,sizeof(b));
		REP(j,i) b[order[n-j-1]]=p[np1+i-j-1];
		//printf("%d:",i); REP(j,n) printf(" %d",b[j]); puts("");

		REP(mask,1<<10) dp[n][mask]=0;
		for(int at=n-1;at>=0;--at) REP(mask,1<<10) {
			if(b[at]!=-1) {
				dp[at][mask]=dp[at+1][mask]+abs(a[at]-b[at]);
				act[at][mask]=b[at];
			} else {
				dp[at][mask]=dp[at+1][mask]+abs(a[at]-1);
				act[at][mask]=1;
				FORE(val,2,60) if(pmask[val]<(1<<10)&&(mask&pmask[val])==0) {
					int cur=abs(val-a[at])+dp[at+1][mask|pmask[val]];
					if(cur<dp[at][mask]) dp[at][mask]=cur,act[at][mask]=val;
				}
			}
		}
		for(int at=0,mask=0;at<n;++at) {
			b[at]=act[at][mask];
			mask|=pmask[b[at]]&((1<<10)-1);
		}
		//printf("%d\n",dp[0][0]); printf("%d:",i); REP(j,n) printf(" %d",b[j]); puts("");
		if(i==0||dp[0][0]<best) { best=dp[0][0]; REP(i,n) bret[i]=b[i]; }
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",bret[i]); } puts("");
}


int main() {
	run();
	return 0;
}