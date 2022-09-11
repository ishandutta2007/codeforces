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

const int MAXN=100;
typedef struct R { char c1,c2; int v1,v2; } R;

int n;
char s[MAXN+1];
int val[MAXN];

R r[MAXN/2]; int nr;
int have[26],tothave;
int opt[MAXN/2],nopt;

void run() {
	scanf("%d",&n); scanf("%s",s); REP(i,n) scanf("%d",&val[i]);

	nr=0; REP(i,n/2) { r[nr].c1=s[i],r[nr].v1=val[i],r[nr].c2=s[n-i-1],r[nr].v2=val[n-i-1]; ++nr; }
	//REP(i,nr) printf("%c %c %d %d\n",r[i].c1,r[i].c2,r[i].v1,r[i].v2);
	int sum=0; REP(i,n) sum+=val[i];
	REP(i,26) have[i]=0; tothave=0; int cost=0;
	REP(i,nr) if(r[i].c1==r[i].c2) ++have[r[i].c1-'a'],++tothave,cost+=min(r[i].v1,r[i].v2);
	//printf("tothave=%d\n",tothave); REP(i,26) if(have[i]>0) printf("%c=%d\n",'a'+i,have[i]);
	int idx=-1; REP(i,26) if(have[i]>tothave-have[i]) { assert(idx==-1); idx=i; }
	if(idx!=-1) {
		nopt=0; REP(i,nr) if(r[i].c1!='a'+idx&&r[i].c2!='a'+idx&&r[i].c1!=r[i].c2) opt[nopt++]=min(r[i].v1,r[i].v2);
		int need=2*have[idx]-tothave; assert(nopt>=need); sort(opt,opt+nopt);
		//printf("%c: need=%d\n",'a'+idx,need);
		REP(i,need) cost+=opt[i];
	}
	printf("%d\n",sum-cost);
}

int main() {
	run();
	return 0;
}