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
const int MAXX=100000;

int n,nx;
int l[MAXN],r[MAXN];

int cnt[MAXX+1];

int lis[MAXX],nlis;
void calc(int *res) {
	nlis=0;
	REP(i,nx) {
		int l=-1,r=nlis; while(l+1<r) { int m=l+(r-l)/2; if(cnt[i]>=lis[m]) l=m; else r=m; }
		res[i]=l+2; lis[l+1]=cnt[i]; nlis=max(nlis,l+2);
	}
}

int a[MAXX],b[MAXX];

void run() {
	scanf("%d%d",&n,&nx); REP(i,n) scanf("%d%d",&l[i],&r[i]),--l[i],--r[i];
	REPE(i,nx) cnt[i]=0; REP(i,n) ++cnt[l[i]],--cnt[r[i]+1]; REP(i,nx) cnt[i+1]+=cnt[i];
	//printf("cnt:"); REP(i,nx) printf(" %d",cnt[i]); puts("");

	calc(a); reverse(cnt,cnt+nx); calc(b); reverse(cnt,cnt+nx); reverse(b,b+nx);
	//printf("a:"); REP(i,nx) printf(" %d",a[i]); puts("");
	//printf("b:"); REP(i,nx) printf(" %d",b[i]); puts("");
	int ret=0; REP(i,nx) ret=max(ret,a[i]+b[i]-1); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}