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

const int MAXN=300000;
struct Op { int x,y,cnt; Op() {} Op(int x,int y,int cnt):x(x),y(y),cnt(cnt) {} };

int n;
int a[MAXN];
int b[MAXN];
int nans;
Op ans[5*MAXN];

pair<int,int> cur[MAXN];

bool solve() {
	sort(b,b+n);
	REP(i,n) cur[i]=MP(a[i],i); sort(cur,cur+n);
	int at=0; nans=0;
	REP(i,n) if(cur[i].first!=b[i]) {
		if(cur[i].first>b[i]) return false;
		while(cur[i].first<b[i]) {
			while(at<n&&cur[at].first<=b[at]) ++at;
			if(at>=n) return false;
			assert(i<at);
			assert(cur[i].first<cur[at].first);
			int cnt=min(b[i]-cur[i].first,cur[at].first-b[at]);
			cur[i].first+=cnt,cur[at].first-=cnt;
			ans[nans++]=Op(cur[i].second,cur[at].second,cnt);
		}
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n",nans);
	REP(i,nans) printf("%d %d %d\n",ans[i].x+1,ans[i].y+1,ans[i].cnt);
}

int main() {
	run();
	return 0;
}