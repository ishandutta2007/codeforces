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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXENEMY=1000000;

int nsoldier,nenemy;
int a[MAXENEMY];
vector<vector<int>> ans;

int rem[MAXENEMY];
int split[MAXENEMY],nsplit;

void solve() {
	nsplit=0;
	int at=0,t=0; REP(i,nenemy) rem[i]=a[i];
	while(at<nenemy) {
		int sofar=0,left=nsoldier;
		while(left>0&&at<nenemy) {
			int cur=min(left,rem[at]);
			if(cur<left&&at+1<nenemy) split[nsplit++]=sofar+cur;
			sofar+=cur; left-=cur; rem[at]-=cur; if(rem[at]==0) ++at;
		}
		++t;
	}
	split[nsplit++]=nsoldier; sort(split,split+nsplit); nsplit=unique(split,split+nsplit)-split;
	//printf("split:"); REP(i,nsplit) printf(" %d",split[i]); puts("");
	
	ans=vector<vector<int>>(t,vector<int>(nenemy,0));
	at=0,t=0; REP(i,nenemy) rem[i]=a[i];
	while(at<nenemy) {
		int sofar=0,left=nsoldier,idx=0;
		while(left>0&&at<nenemy) {
			int cur=min(left,rem[at]);
			while(idx==0||split[idx-1]<sofar+cur) ans[t][idx]=at,++idx;
			sofar+=cur; left-=cur; rem[at]-=cur; if(rem[at]==0) ++at;
		}
		++t;
	}
}

void run() {
	scanf("%d%d",&nsoldier,&nenemy);
	REP(i,nenemy) scanf("%d",&a[i]);
	solve();
	printf("%d\n",SZ(ans));
	REP(i,nenemy) { if(i!=0) printf(" "); printf("%d",(i<nsplit?split[i]:nsoldier)-(i-1<0?0:i-1<nsplit?split[i-1]:nsoldier)); } puts("");
	REPSZ(i,ans) { REPSZ(j,ans[i]) { if(j!=0) printf(" "); printf("%d",ans[i][j]+1); } puts(""); }	
}

int main() {
	run();
	return 0;
}