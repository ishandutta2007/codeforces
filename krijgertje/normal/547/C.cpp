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

// #i<j : have[i]&&have[j]&&gcd(a[i],a[j])==1
// sum(x,(#i<j : have[i]&&have[j]&&gcd(a[i],a[j])==k*x)*(-1)^np(x) | x is squarefree)
// sum(x,(#i<j : have[i]&&have[j]&&a[i]==ki*x,a[j]==kj*x)*(-1)^np(x) | x is squarefree)
// sum(x,choose(#i:have[i]&&a[i]==k*x,2)*(-1)^np(x) | x is squarefree)

const int MAXN=200000;
const int MAXVAL=500000;
const int MAXCP=6;

int cur[MAXVAL+1];
int prv[MAXVAL+1];

int n,nq;
int a[MAXN];
bool have[MAXN];

ll ret;
int cnt[MAXVAL+1];
ll ways(ll n) { return n*(n-1)/2; }

int cp[MAXCP],ncp;

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	memset(have,false,sizeof(have));
	ret=0; memset(cnt,0,sizeof(cnt));
	REP(qi,nq) {
		int i; scanf("%d",&i); --i;
		// update cnt[x] and ret for all x such that a[i]==k*x
		{ ncp=0; for(int x=a[i];x!=1;x=prv[x]) cp[ncp++]=cur[x]; }
		//printf("processing %d\n",a[i]);
		REP(j,1<<ncp) {
			int x=1; int sgn=+1; REP(k,ncp) if(j&(1<<k)) x*=cp[k],sgn=-sgn;
			//printf("\tchanging %d\n",x);
			ret-=sgn*ways(cnt[x]);
			cnt[x]+=have[i]?-1:+1;
			ret+=sgn*ways(cnt[x]);
		}
		have[i]=!have[i];
		cout<<ret<<endl;
	}
}

void precalc() {
	memset(cur,-1,sizeof(cur));
	FORE(i,2,MAXVAL) if(cur[i]==-1) {
		cur[i]=i; prv[i]=1;
		for(int j=i+i;j<=MAXVAL;j+=i) { cur[j]=i; int k=j/i; prv[j]=cur[k]==i?prv[k]:k; }
	}
	//FORE(i,1,100) printf("%d: %d %d\n",i,cur[i],prv[i]);
}

int main() {
	precalc();
	run();
	return 0;
}