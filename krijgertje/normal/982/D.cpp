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

const int MAXN=100000;

int n;
int a[MAXN];

pair<int,int> o[MAXN];

int par[MAXN],sz[MAXN];
int cnt[MAXN+1],ncnt;
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
void unite(int a,int b) { a=find(a),b=find(b); if(a==b) return; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; }

int solve() {
	REP(i,n) o[i]=MP(a[i],i); sort(o,o+n);

	REP(i,n) par[i]=-1;
	REPE(i,n) cnt[i]=0; ncnt=0;

	int mxloc=-1,bestk=-1;
	REP(i,n) {
		int idx=o[i].second;

		assert(par[idx]==-1);
		par[idx]=idx; sz[idx]=1;

		if(idx-1>=0&&par[idx-1]!=-1) {
			int z=find(idx-1);
			if(--cnt[sz[z]]==0) --ncnt;
			unite(idx,z);
		}
		if(idx+1<n&&par[idx+1]!=-1) {
			int z=find(idx+1);
			if(--cnt[sz[z]]==0) --ncnt;
			unite(idx,z);
		}
		{
			int z=find(idx);
			if(++cnt[sz[z]]==1) ++ncnt;
			int curk=a[idx]+1;
			//printf("%d: ncnt=%d\n",curk,ncnt);
			if(ncnt==1) {
				int cur=cnt[sz[z]];
				if(cur>mxloc||cur==mxloc&&curk<bestk) mxloc=cur,bestk=curk;
			}
		}
	}
	return bestk;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}