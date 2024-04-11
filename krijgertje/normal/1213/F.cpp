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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n,need;
int p[MAXN];
int q[MAXN];
char ans[MAXN+1];

int rp[MAXN];
int upto[MAXN];
bool canlast[MAXN];
bool islast[MAXN];

bool solve() {
	REP(i,n) rp[p[i]]=i;
	REP(i,n) upto[i]=i;
	REP(i,n-1) {
		int a=rp[q[i]],b=rp[q[i+1]];
		if(a>b) upto[b]=max(upto[b],a);
	}
	FOR(i,1,n) upto[i]=max(upto[i-1],upto[i]);
	REP(i,n) canlast[i]=upto[i]==i;
	int ncanlast=0; REP(i,n) if(canlast[i]) ++ncanlast;
	if(ncanlast<need) return false;
	int havelast=ncanlast; REP(i,n) islast[i]=canlast[i]; REP(i,n) if(islast[i]&&havelast>need) islast[i]=false,--havelast;
	char c='a'; REP(i,n) { ans[p[i]]=c; if(islast[i]) ++c; } ans[n]='\0'; return true;
}

void run() {
	scanf("%d%d",&n,&need);
	REP(i,n) scanf("%d",&p[i]),--p[i];
	REP(i,n) scanf("%d",&q[i]),--q[i];
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}