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

const int MAXA=1000000;
const int MAXB=1000000;

int na,nb,lim;
int a[MAXA];
pair<int,int> b[MAXB];
int c[MAXA],nc;

int ret[MAXB],nret;

void run() {
	scanf("%d%d%d",&na,&nb,&lim);
	REP(i,na) scanf("%d",&a[i]); sort(a,a+na);
	REP(i,nb) scanf("%d",&b[i].first),b[i].second=i; sort(b,b+nb);

	//printf("a: "); REP(i,na) printf("%d ",a[i]); puts("");
	//printf("b: "); REP(i,nb) printf("%d ",b[i].first); puts("");

	{
		nc=0; int t=INT_MAX,cnt=0,idx=na-1;
		while(cnt>0||idx>=0) {
			if(cnt==0) t=a[idx--],cnt=1;
			while(idx>=0&&a[idx]==t) --idx,++cnt;
			int now=min(cnt,lim);
			//printf("t=%d cnt=%d now=%d idx=%d\n",t,cnt,now,idx);
			REP(i,now) c[nc++]=t;
			cnt-=now; --t;
		}
		reverse(c,c+nc); if(c[0]<0) { printf("-1\n"); return; }
	}
	//printf("c: "); REP(i,nc) printf("%d ",c[i]); puts("");
	{
		int bi=0,ci=0,t=0;
		while(bi<nb) {
			int cnt=0; while(ci<nc&&c[ci]==t) ++ci,++cnt; assert(cnt<=lim);
			int rem=lim-cnt;
			while(b[bi].first<t) ++bi;
			while(bi<nb&&rem>0) ret[nret++]=b[bi++].second,--rem;
			++t;
		}
		sort(ret,ret+nret);
		printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
	}
}

int main() {
	run();
	return 0;
}