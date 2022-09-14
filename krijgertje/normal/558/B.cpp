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
const int MAXVAL=1000000;

int n;
int a[MAXN];

int l[MAXVAL],r[MAXVAL],cnt[MAXVAL];

void run() {
	scanf("%d",&n);
	REP(i,n) { scanf("%d",&a[i]); --a[i]; }

	memset(cnt,0,sizeof(cnt));
	REP(i,n) if(++cnt[a[i]]==1) l[a[i]]=r[a[i]]=i; else r[a[i]]=i;
	int maxcnt=0,ret[2]; REP(i,MAXVAL) if(cnt[i]>maxcnt||cnt[i]==maxcnt&&r[i]-l[i]<ret[1]-ret[0]) maxcnt=cnt[i],ret[0]=l[i],ret[1]=r[i];
	printf("%d %d\n",ret[0]+1,ret[1]+1);
}

int main() {
	run();
	return 0;
}