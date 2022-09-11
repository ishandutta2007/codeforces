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

const int MAXQ=200000;
const int MAXID=2*MAXQ;

int nq;

int nid;
map<int,int> mp;
int par[MAXID],sz[MAXID],dst[MAXID];

int makeid(int x) {
	if(mp.count(x)) return mp[x];
	int ret=mp[x]=nid++;
	par[ret]=ret,sz[ret]=1,dst[ret]=0;
	return ret;
}
void compress(int x) {
	if(par[x]==x) return;
	compress(par[x]);
	dst[x]^=dst[par[x]]; par[x]=par[par[x]];
}


void run() {
	nid=0; mp.clear();

	scanf("%d",&nq);
	int last=0;
	REP(qi,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int l,r,x; scanf("%d%d%d",&l,&r,&x); l^=last,r^=last,x^=last; if(l>r) swap(l,r);
			int lid=makeid(l),rid=makeid(r+1);
			compress(lid); compress(rid);
			int lroot=par[lid],rroot=par[rid];
			if(lroot!=rroot) {
				if(sz[lroot]<sz[rroot]) swap(lid,rid),swap(lroot,rroot);
				par[rroot]=lroot; sz[lroot]+=sz[rroot]; dst[rroot]=x^(lid==lroot?0:dst[lid])^(rid==rroot?0:dst[rid]);
			}
		}
		if(kind==2) {
			int l,r; scanf("%d%d",&l,&r); l^=last; r^=last; if(l>r) swap(l,r);
			int lid=makeid(l),rid=makeid(r+1);
			compress(lid); compress(rid);
			int lroot=par[lid],rroot=par[rid];
			int ans=-1;
			if(lroot==rroot) {
				ans=(lid==lroot?0:dst[lid])^(rid==rroot?0:dst[rid]);
			}
			printf("%d\n",ans);
			last=ans==-1?1:ans;
		}
	}
}

int main() {
	run();
	return 0;
}