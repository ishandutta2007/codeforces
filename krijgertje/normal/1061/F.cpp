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

const int MAXN=1500;

int n,k;

int cnt[MAXN];

bool local=false; int nq;
int locorder[MAXN];
int locidx[MAXN];
int locdep[MAXN];

char buff[20];
bool query(int a,int b,int c) {
	++nq;
	if(!local) {
		printf("? %d %d %d\n",a+1,b+1,c+1); fflush(stdout);
		scanf("%s",buff);
		return strcmp(buff,"Yes")==0;
	} else {
		while(true) {
			if(b==a||b==c) return true;
			if(a==c) return false;
			if(locdep[a]<locdep[c]) swap(a,c);
			a=locorder[(locidx[a]-1)/2];
		}
	}
}

int cur[MAXN],ncur;

int solve() {
	REP(i,n) cnt[i]=0;
	int h=1,expect=1; while(expect<n) { ++h; expect=expect*k+1; }
	//printf("h=%d\n",h);
	REP(i,60) {
		int a,c; while(true) { a=rand()%n,c=rand()%n; if(a!=c) break; }
		ncur=0;
		REP(b,n) if(query(a,b,c)) ++cnt[b],cur[ncur++]=b;
		if(ncur!=h+h-1) continue;
		REP(j,ncur) {
			int now=0;
			REP(k,ncur) if(query(a,cur[j],cur[k])) ++now;
			//printf("now=%d\n",now);
			if(now==h) return cur[j];
		}
		assert(false);
	}
	//printf("cnt:"); REP(i,n) printf(" %d",cnt[i]); puts("");
	int mx=0; REP(i,n) if(cnt[i]>cnt[mx]) mx=i; return mx;
}

void run() {
	scanf("%d%d",&n,&k);
	printf("! %d\n",solve()+1); fflush(stdout);
}

void test() {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&locorder[i]),--locorder[i];
	REP(i,n) locidx[locorder[i]]=i;
	locdep[locorder[0]]=0; FOR(i,1,n) locdep[locorder[i]]=locdep[locorder[(i-1)/2]]+1;
	REP(i,n) printf("%d: locdep=%d locidx=%d\n",i+1,locdep[i],locidx[i]);

	local=true; nq=0;
	int have=solve();
	int want=locorder[0];
	printf("%.2lf\n",100.0*nq/(60*n));
	if(have==want) { printf("ok\n"); return; }
	printf("err: have=%d want=%d\n",have+1,want+1);
}

int main() {
	srand(12312);
	run();
	//test();
	return 0;
}