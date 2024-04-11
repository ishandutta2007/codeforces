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
const int MAXVAL=100000;
const int MAXLOGVAL=20;


int n;
int a[MAXN];
int b[MAXN];

int cnt[MAXLOGVAL+1];
int lcum[MAXLOGVAL+1];
int rcum[MAXLOGVAL+1];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);

	REP(i,n) { b[i]=a[i]; while(b[i]<(1<<MAXLOGVAL)) b[i]*=2; }
	sort(b,b+n);
	int l=b[0],h=b[n-1];
	while(l!=h) l/=2,h/=2;
	int base=l; while(base%2==0) base/=2;

	int ret=0;
	memset(cnt,0,sizeof(cnt));
	REP(i,n) {
		int cur=a[i],now=0;
		while(cur!=base) { ++now; if(cur%2==1) ret+=now,now=0; cur/=2; }
		cnt[now]++;
	}

	{ lcum[0]=0; int sum=0; FORE(i,1,MAXLOGVAL) sum+=cnt[i-1],lcum[i]=lcum[i-1]+sum; }
	{ rcum[MAXLOGVAL]=0; int sum=0; for(int i=MAXLOGVAL-1;i>=0;--i) sum+=cnt[i+1],rcum[i]=rcum[i+1]+sum; }
	//REPE(i,MAXLOGVAL) printf("%d: %d (%d,%d)\n",i,cnt[i],lcum[i],rcum[i]);
	int mincum=lcum[0]+rcum[0];
	FORE(i,1,MAXLOGVAL) if(lcum[i]+rcum[i]<mincum) mincum=lcum[i]+rcum[i];
	ret+=mincum;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}