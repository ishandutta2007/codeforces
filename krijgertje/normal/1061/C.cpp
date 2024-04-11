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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MOD=1000000007;
const int MAXVAL=1000000;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n;
int a[MAXN];

int pmn[MAXVAL+1];

int cnt[MAXN+1];
pair<int,int> cur[MAXN+1]; int ncur=0;

void rec(int x,int y) {
	if(x==1) {
		if(y<=n) {
			//printf("processing %d\n",y);
			int ways=1; if(y+1<=n) inc(ways,cnt[y+1]);
			cur[ncur++]=MP(y,ways);
		}
	} else {
		int p=pmn[x],cnt=0; while(x%p==0) x/=p,++cnt;
		REPE(i,cnt) {
			rec(x,y);
			if(i!=cnt) y*=p;
		}
	}
}


int solve() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;

	REPE(i,n) cnt[i]=0;
	for(int i=n-1;i>=0;--i) {
		ncur=0;
		rec(a[i],1);
		REP(j,ncur) inc(cnt[cur[j].first],cur[j].second);
	}

	return cnt[1];
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}