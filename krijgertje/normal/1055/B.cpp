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

int n,nq,want;
ll a[MAXN];

int par[MAXN],sz[MAXN];
int find(int x) { if(par[x]==x) return x; return par[x]=find(par[x]); }
bool unite(int a,int b) { a=find(a),b=find(b); if(a==b) return false; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; return true; }

void run() {
	scanf("%d%d%d",&n,&nq,&want);
	REP(i,n) scanf("%lld",&a[i]);

	REP(i,n) par[i]=i,sz[i]=1;
	int ret=0; REP(i,n) if(a[i]>want) ++ret;
	REP(i,n-1) if(a[i]>want&&a[i+1]>want&&unite(i,i+1)) --ret;
	
	REP(i,nq) {
		int kind; scanf("%d",&kind);
		if(kind==0) {
			printf("%d\n",ret);
		}
		if(kind==1) {
			int idx,delta; scanf("%d%d",&idx,&delta); --idx;
			if(a[idx]>want) --ret;
			a[idx]+=delta;
			if(a[idx]>want) ++ret;
			if(a[idx]>want&&idx-1>=0&&a[idx-1]>want&&unite(idx,idx-1)) --ret;
			if(a[idx]>want&&idx+1<n&&a[idx+1]>want&&unite(idx,idx+1)) --ret;
		}
	}
}

int main() {
	run();
	return 0;
}