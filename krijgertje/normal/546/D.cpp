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

const int MAXVAL=5000000;

int dv[MAXVAL+1];
int cnt[MAXVAL+1];
int sum[MAXVAL+2];

void run() {
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b);
		int ret=sum[a+1]-sum[b+1]; printf("%d\n",ret);
	}
}

void precalc() {
	memset(cnt,0,sizeof(cnt));
	FORE(i,2,MAXVAL) if(dv[i]==0) for(int j=i;j<=MAXVAL;j+=i) dv[j]=i;
	FORE(i,2,MAXVAL) cnt[i]=cnt[i/dv[i]]+1;
	sum[0]=0; REPE(i,MAXVAL) sum[i+1]=sum[i]+cnt[i];
	//REPE(i,20) printf("%3d",dv[i]); puts("");
	//REPE(i,20) printf("%3d",cnt[i]); puts("");
	//REPE(i,20) printf("%3d",sum[i]); puts("");
}


int main() {
	precalc();
	run();
	return 0;
}