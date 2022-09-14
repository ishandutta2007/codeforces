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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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


int val[20][1<<17+1];
void update(int x,int at,int by) {
//	printf("update bit%d at=%d by=%d\n",x,at,by);
	while(true) {
		val[x][at]+=by;
		if(at==(1<<17)) break; else at+=at&-at;
	}
}
int get(int x,int at) {
	int ret=0;
	while(at>0) {
		ret+=val[x][at];
		at-=at&-at;
	}
	return ret;
}
int find(int x,int y) {
	if(y==0) return 0; else --y;
	int ret=0;
//	printf("find(%d,%d)\n",x,y);
	for(int i=16;i>=0;--i) {
		int at=ret+(1<<i);
//		printf("\t%d=%d (vs %d)\n",at,val[x][at],y);
		if(y>=val[x][at]) { y-=val[x][at]; ret=at; }
	}
	return ret+1;
}

ll calc(ll len,int pos) {
//	if(len!=0) printf("calc(%lld,%d)\n",len,pos);
	return (len+1)*len/2*(1<<pos);
}

int a[100001];

void run(int casenr) {
	int n,m;
	scanf("%d%d",&n,&m);
	FORE(i,1,n) scanf("%d",&a[i]);

	memset(val,0,sizeof(val));
	ll ans=0;
	REP(j,20) {
		int cnt=0;
		FORE(i,1,n) {
			if(a[i]&(1<<j)) { ++cnt; continue; }
			ans+=calc(cnt,j); cnt=0; update(j,i,+1);
		}
		ans+=calc(cnt,j);
		update(j,n+1,+1);
	}

	REP(i,m) {
		int p,v; scanf("%d%d",&p,&v);
		REP(j,20) if((a[p]&(1<<j))!=(v&(1<<j))) {
//			printf("q%d bit%d\n",i,j);
			if(v&(1<<j)) update(j,p,-1);
			int cur=get(j,p),prev=find(j,cur),next=find(j,cur+1);
			ll delta=(calc(next-prev-1,j)-calc(next-p-1,j)-calc(p-prev-1,j));
//			printf("\tcur=%d,prev=%d,next=%d,delta=%lld\n",cur,prev,next,delta);
			if(v&(1<<j)) ans+=delta; else ans-=delta;
			if(a[p]&(1<<j)) update(j,p,+1);
		}
		a[p]=v;
		cout<<ans<<endl;
	}
}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}