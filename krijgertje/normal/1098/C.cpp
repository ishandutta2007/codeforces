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

const int MAXN=100000;

int n; ll want;
int par[MAXN];

int h; // maximum index with cnt[i]>0
int cnt[MAXN]; // cnt[i] = number of nodes with d[x]=i

bool solve() {
	FORE(branch,1,n-1) {
		cnt[0]=1; h=0; int rem=n-1;
		while(rem>0) { int cur=min((ll)branch*cnt[h],(ll)rem); ++h; cnt[h]=cur; rem-=cur; }
		//printf("%d: h=%d\n",branch,h);
		ll have=0; REPE(i,h) have+=(ll)cnt[i]*(i+1); if(have>want) continue;
		for(int i=h;i>=0;--i) while(cnt[i]>=2&&have<want) {
			int cur=min((ll)h+1-i,want-have);
			int ni=i+cur; while(ni>h) ++h,cnt[h]=0;
			--cnt[i],++cnt[ni],have+=cur;
		}
		if(have!=want) return false;
		//printf("found with branch=%d (want=%lld have=%lld)\n",branch,want,have);
		par[0]=-1; int l=0,r=0;
		FORE(i,1,h) {
			int nl=r+1,nr=nl+cnt[i]-1;
			REP(j,cnt[i]) par[r+1+j]=l+j/branch;
			l=nl,r=nr;
		}
		return true;
	}
	return false;
}

void run() {
	scanf("%d%lld",&n,&want);
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	FOR(i,1,n) { if(i!=1) printf(" "); printf("%d",par[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}