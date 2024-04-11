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

const int MAXN=5000;

int n,shave;

int cost[MAXN],have[MAXN+1],use[MAXN],pay[MAXN];

void run() {
	scanf("%d%d",&n,&shave); REP(i,n) scanf("%d",&cost[i]);
	have[0]=shave;
	REP(i,n) {
		if(cost[i]<10||i==n-1) {
			use[i]=min(have[i],cost[i]/2);
		} else {
			use[i]=min(have[i],cost[i]%10);
		}
		pay[i]=cost[i]-use[i];
		have[i+1]=have[i]-use[i]+pay[i]/10;
	}
	//printf("init: "); REP(i,n) printf("(%d,%d)",have[i],use[i]); puts(""); puts("");
	for(int step=10;step>=1;--step) {
		int bound=INT_MAX;
		for(int i=n-1;i>=0;--i) {
			int pen=i==n-1?0:1;
			if(have[i]-use[i]>=step&&bound>=step+pen&&pay[i]%10==0&&2*(use[i]+step)<=cost[i]) {
				int cur=min(min((have[i]-use[i])/step,bound==INT_MAX?bound:bound/(step+pen)),(cost[i]-2*use[i])/(2*step));
				//printf("bound=%d step=%d cost=%d use=%d -> cur=%d\n",bound,step,cost[i],use[i],cur);
				use[i]+=cur*step;
				bound-=cur*(step+pen);
			}
			bound=min(bound,have[i]-use[i]);
		}
		REP(i,n) pay[i]=cost[i]-use[i],have[i+1]=have[i]-use[i]+pay[i]/10;
		//printf("after %d: ",step); REP(i,n) printf("(%d,%d)",have[i],use[i]); puts(""); puts("");
	}
	int ret=0; REP(i,n) ret+=pay[i]; printf("%d\n",ret);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",use[i]); } puts("");
}

int main() {
	run();
	return 0;
}