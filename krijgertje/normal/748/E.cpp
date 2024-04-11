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
const int MAXVAL=10000000;

int n,want;
int x[MAXN];

ll cnt[MAXVAL+1];



void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d",&x[i]);
	memset(cnt,0,sizeof(cnt));
	REP(i,n) ++cnt[x[i]];
	int l=1,r=1; ll have=cnt[1];
	while(r<MAXVAL) have+=cnt[++r];
	while(have-cnt[l]>=want) have-=cnt[l++];
	while(have>=want&&cnt[l]==0) ++l;
	while(cnt[r]==0) --r;
	int ret=0;
	while(true) {
		//printf("%d..%d = %d\n",l,r,have);
		if(have>=want) { int cur=l; if(cur>ret) ret=cur; }
		if(r==1) break;
		int a=r/2,b=(r+1)/2;
		have-=cnt[r];
		cnt[a]+=cnt[r]; if(a>=l) have+=cnt[r];
		cnt[b]+=cnt[r]; if(b>=l) have+=cnt[r];
		--r;
		while(cnt[r]==0) --r;
		while(have-cnt[l]>=want) have-=cnt[l++];
		while(l>=2&&have<want) have+=cnt[--l];
		while(have>=want&&cnt[l]==0) ++l;
	}
	printf("%d\n",ret==0?-1:ret);
}

int main() {
	run();
	return 0;
}