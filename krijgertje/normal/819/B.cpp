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

const int MAXN=1000000;

int n;
int p[MAXN];

int cnt[MAXN+1];

void upd(int val,int by) {
	if(val<0||val>n) return;
	cnt[val]+=by;
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&p[i]),--p[i];
	//n=MAXN; REP(i,n) p[i]=i; random_shuffle(p,p+n);
	memset(cnt,0,sizeof(cnt));
	int zero=0; ll sumabs=0; int cntneg=0,cntzero=0,cntpos=0;
	REP(i,n) {
		int cur=p[i]-i;
		upd(cur,+1);
		if(cur<0) ++cntneg; else if(cur==0) ++cntzero; else if(cur>0) ++cntpos;
		sumabs+=abs(cur);
	}
	ll ret=sumabs; int retshifts=0;
	//printf("%d shifts: %lld (%d,%d,%d) zero=%d\n",0,sumabs,cntneg,cntzero,cntpos,zero);
	//for(auto it=cnt.begin();it!=cnt.end();++it) if(it->second!=0) printf(" %d times %d,",it->second,it->first-zero); puts("");
	REP(i,n) {
		int idx=n-i-1; int oval=p[idx]-idx-zero;
		sumabs-=abs(oval); upd(oval+zero,-1); if(oval<0) --cntneg; else if(oval==0) --cntzero; else if(oval>0) --cntpos;
		int nval=oval+n;
		sumabs+=abs(nval); upd(nval+zero,+1); if(nval<0) ++cntneg; else if(nval==0) ++cntzero; else if(nval>0) ++cntpos;
		int cntone=cnt[zero+1]; sumabs+=cntneg+cntzero-cntpos; cntneg+=cntzero,cntzero=cntone,cntpos-=cntone; ++zero;
		if(sumabs<ret) ret=sumabs,retshifts=i+1;
		//printf("%d shifts: %lld (%d,%d,%d) zero=%d [oval=%d,nval=%d]\n",i+1,sumabs,cntneg,cntzero,cntpos,zero,oval,nval);
		//for(auto it=cnt.begin();it!=cnt.end();++it) if(it->second!=0) printf(" %d times %d,",it->second,it->first-zero); puts("");
	}
	printf("%lld %d\n",ret,retshifts);
}

int main() {
	run();
	return 0;
}