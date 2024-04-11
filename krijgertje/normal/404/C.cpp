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

int n,k;
int d[100000];
int first[100000];
int nxt[100000];
int cnt[100000];

void run() {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&d[i]);

	memset(first,-1,sizeof(first));
	REP(i,n) { nxt[i]=first[d[i]]; first[d[i]]=i; ++cnt[d[i]]; }

	bool ok=true;
	if(cnt[0]!=1) ok=false;
	FOR(i,1,n) { int ck=i==1?k:k-1; if(ck==0&&cnt[i]>0||ck>0&&(cnt[i]+ck-1)/ck>cnt[i-1]) ok=false; }
	if(!ok) { printf("-1\n"); return; }

	printf("%d\n",n-1);
	FOR(i,1,n) {
		int ck=i==1?k:k-1;
		int a=first[i-1],rem=ck;
		for(int b=first[i];b!=-1;b=nxt[b]) {
			if(rem==0) { a=nxt[a]; assert(a!=-1); rem=ck; }
			printf("%d %d\n",a+1,b+1); --rem;
		}
	}
}

int main() {
	run();
	return 0;
}