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

int dv[10000001];
ll cnt[10000001];
ll need[10000001];


void run(int casenr) {
	memset(dv,-1,sizeof(dv));
	FORE(i,2,10000000) if(dv[i]==-1) for(int j=i;j<=10000000;j+=i) if(dv[j]==-1) dv[j]=i;

	int k; scanf("%d",&k);
	REP(i,k) { int a; scanf("%d",&a); ++cnt[a]; }
//	memset(cnt,0,sizeof(cnt));
//	cnt[10000000]=1000000;
	
	ll ret=1;
	ll sum=0;
	for(int i=10000000;i>=2;--i) {
		sum+=cnt[i];
		ll cur=sum+need[i]; if(cur==0) continue;
		if(dv[i]!=i) {
			need[dv[i]]+=cur; need[i/dv[i]]+=cur;
		} else {
			ll now=0,left=cur,have=1,val=i; int exp=1;
			while(have<left) { have=have*i+1; val*=i; ++exp; }
			while(left>0) {
				if(have-exp>=left) { have=(have-1)/i; val/=i; --exp; continue; }
				ll times=(left+exp-have+have-1)/have;
				left-=times*have; now+=times*val;
			}
//			printf("%d^%lld -> %lld!\n",i,cur,now);
			if(now>ret) ret=now;
		}
	}
	cout<<ret<<endl;
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}