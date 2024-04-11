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

const int MAXD=300;

int nd;
int d[MAXD];
int cnt[MAXD];
int sum[MAXD+1];

priority_queue<pair<int,int> > pq;
vector<pair<int,int> > toadd;

void run() {
	scanf("%d",&nd); REP(i,nd) scanf("%d",&d[i]);

	reverse(d,d+nd);
	REP(i,nd) cnt[i]=1;
	int nn=d[0]+1;
	cnt[nd-1]+=nn-nd;
	int dsum=0; REP(i,nd) dsum+=d[i]*cnt[i];
	if(dsum%2==1) { int oth=-1; for(int i=nd-1;i>=0;--i) if(d[i]%2!=d[nd-1]%2) { oth=i; break; } assert(oth!=-1); ++cnt[oth],--cnt[nd-1],dsum+=d[oth]-d[nd-1]; }

	FORE(k,1,nn) {
		int rem=k,a=0,b=k*(k-1);
		REP(i,nd) {
			int cur=min(rem,cnt[i]);
			rem-=cur; a+=cur*d[i]; b+=(cnt[i]-cur)*min(d[i],k);
		}
		//printf("%d: a=%d b=%d\n",k,a,b);
		for(int i=nd-1;i>=1&&d[i]<k&&a>b;--i) {
			int delta=min(k,d[i-1])-d[i];
			int need=(a-b+delta-1)/delta;
			int now=min(need,cnt[i]-1);
			if(now%2==1&&d[i]%2!=d[i-1]%2) if(now==cnt[i]-1) --now; else ++now;
			//if(now>0) printf("\t%d from %d to %d\n",now,d[i],d[i-1]);
			cnt[i]-=now; cnt[i-1]+=now; b+=now*delta; dsum+=(d[i-1]-d[i])*now;
		}
		for(int i=nd-1;i>=1&&d[i]<k&&a>b;--i) if(cnt[i]>1) {
			int j=i-1; while(j>=0&&d[i]%2!=d[j]%2) --j; if(j<0) continue;
			//printf("\t%d from %d to %d\n",1,d[i],d[j]);
			cnt[i]-=1; cnt[j]+=1; b+=min(k,d[j])-d[i]; dsum+=d[j]-d[i];
		}
		assert(a<=b);
	}
	//printf("cnt:"); REP(i,nd) printf(" %d*%d",cnt[i],d[i]); puts("");

	printf("%d\n",dsum/2);
	pq=priority_queue<pair<int,int> >();
	sum[0]=0; REP(i,nd) sum[i+1]=sum[i]+cnt[i];
	REP(i,nd) REP(j,cnt[i]) pq.push(MP(d[i],-(sum[i]+j)));
	while(!pq.empty()) {
		int id=-pq.top().second,rem=pq.top().first; pq.pop();
		assert(SZ(pq)>=rem);
		REP(i,rem) {
			pair<int,int> o=pq.top(); pq.pop();
			printf("%d %d\n",id+1,-(o.second)+1);
			if(o.first>1) toadd.PB(MP(o.first-1,o.second));
		}
		REPSZ(i,toadd) pq.push(toadd[i]); toadd.clear();
	}





}

int main() {
	run();
	return 0;
}