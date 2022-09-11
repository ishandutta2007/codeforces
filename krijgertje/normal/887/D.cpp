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

const int MAXN=300000;
typedef struct QueueMinPrefSum {
	ll sum,sub;
	int lst[MAXN],head,tail;
	pair<ll,int> mn[MAXN]; int mnhead,mntail;

	void init() {
		sum=sub=0; head=tail=0; mnhead=mntail=0; mn[mnhead++]=MP(sum,head);
	}
	void print() {
		printf("sum=%lld sub=%lld lst=",sum,sub); FOR(i,tail,head) printf("%d ",lst[i]); printf("mn="); FOR(i,mntail,mnhead) printf(" %lld(%d)",mn[i].first,mn[i].second); puts("");
	}
	void push(int val) {
		sum+=val;
		lst[head++]=val;
		while(mntail<mnhead&&sum<=mn[mnhead-1].first) --mnhead;
		mn[mnhead++]=MP(sum,head);
		//print();
	}
	void pop() {
		sub+=lst[tail];
		++tail;
		while(mntail<mnhead&&mn[mntail].second<tail) ++mntail;
		//print();
	}
	ll val() {
		assert(mntail<mnhead); return mn[mntail].first-sub;
	}
} QueuePrefMin;

int n,gain1,lose0,talkgain1,talklose0,srating,len;
int et[MAXN],ekind[MAXN];

QueueMinPrefSum qmps;


void run() {
	scanf("%d%d%d%d%d%d%d",&n,&gain1,&lose0,&talkgain1,&talklose0,&srating,&len);
	REP(i,n) scanf("%d%d",&et[i],&ekind[i]);

	int t=0,head=0,tail=0; ll rating=srating; qmps.init();
	while(true) {
		while(head<n&&et[head]<t+len) qmps.push(ekind[head]==0?-talklose0:talkgain1),++head;
		while(tail<head&&et[tail]<t) rating+=ekind[tail]==0?-lose0:gain1,qmps.pop(),++tail;
		//printf("[%d..%d) rating=%lld qmps.val=%lld\n",t,t+len,rating,qmps.val());
		if(rating<0) { printf("-1\n"); return; }
		if(rating+qmps.val()>=0) { printf("%d\n",t); return; }
		assert(tail<n&&et[tail]>=t);
		t=et[tail]+1;
	}
}

int main() {
	run();
	return 0;
}