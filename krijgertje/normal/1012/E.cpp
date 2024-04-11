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

const int MAXN=200000;

int n,lim;
int a[MAXN];

int b[MAXN];
bool isfixed[MAXN];

pair<int,int> o[MAXN]; int no;
int dst[MAXN];

int cyc[MAXN],ncyc;
int par[MAXN],sz[MAXN];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
bool unite(int a,int b) { a=find(a),b=find(b); if(a==b) return false; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; return true; }

bool done[MAXN];
vector<vector<int>> ans;

bool solve() {
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");

	REP(i,n) b[i]=a[i];
	sort(b,b+n);
	//printf("b:"); REP(i,n) printf(" %d",b[i]); puts("");

	int nfixed=0; REP(i,n) { isfixed[i]=a[i]==b[i]; if(isfixed[i]) ++nfixed; }
	if(n-nfixed>lim) return false;
	//printf("fix:"); REP(i,n) printf(" %c",isfixed[i]?'V':'x'); puts("");

	no=0; REP(i,n) if(!isfixed[i]) o[no++]=MP(a[i],i);
	sort(o,o+no);
	//printf("o:"); REP(i,no) printf(" (%d,%d)",o[i].first,o[i].second); puts("");
	REP(i,n) dst[i]=isfixed[i]?i:-1;
	{ int at=0; REP(i,no) { while(at<n&&isfixed[at]) ++at; dst[o[i].second]=at++; } }
	//printf("dst:"); REP(i,n) printf(" %d",dst[i]); puts("");

	REP(i,n) cyc[i]=-1; ncyc=0;
	REP(i,n) if(cyc[i]==-1&&dst[i]!=i) {
		int at=i; while(cyc[at]==-1) { cyc[at]=ncyc; at=dst[at]; } ++ncyc;
	}
	
	int expect=ncyc;
	REP(i,ncyc) par[i]=i,sz[i]=1;
	for(int l=0,r=l;l<no;l=r) {
		while(r<no&&o[l].first==o[r].first) ++r;
		int cur=o[l].second;
		FOR(i,l+1,r) {
			int oth=o[i].second;
			if(unite(cyc[cur],cyc[oth])) {
				//printf("merged cycles of %d and %d\n",cur,oth);
				swap(dst[cur],dst[oth]);
				--expect;
			}
		}
	}

	REP(i,n) done[i]=false; ans.clear();
	REP(i,n) if(!done[i]&&dst[i]!=i) {
		ans.PB(vector<int>());
		int at=i; while(!done[at]) { done[at]=true; ans.back().PB(at); at=dst[at]; }
	}
	assert(SZ(ans)==expect);

	int rem=lim-(n-nfixed);
	if(SZ(ans)>=3&&rem>=3) {
		int cnt=min(rem,SZ(ans));
		vector<int> fst(cnt); REP(i,cnt) fst[i]=ans[i][0]; reverse(fst.begin(),fst.end());
		vector<int> snd; REP(i,cnt) { snd.PB(ans[i][0]); int j=(i+1)%cnt; FORSZ(k,1,ans[j]) snd.PB(ans[j][k]); }
		vector<vector<int>> nans; nans.PB(fst); nans.PB(snd); FORSZ(i,cnt,ans) nans.PB(ans[i]); ans=nans;
	}

	return true;
}

bool verify(vector<vector<int>> ans) {
	vector<int> cur(n); REP(i,n) cur[i]=a[i];
	REPSZ(i,ans) {
		int val=cur[ans[i][0]];
		FORSZ(j,1,ans[i]) swap(val,cur[ans[i][j]]);
		cur[ans[i][0]]=val;
		//printf("cur:"); REP(i,n) printf(" %d",cur[i]); puts("");
	}
	FORSZ(i,1,cur) if(cur[i]<cur[i-1]) return false;
	return true;
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) { printf("%d\n",SZ(ans[i])); REPSZ(j,ans[i]) { if(j!=0) printf(" "); printf("%d",ans[i][j]+1); } puts(""); }
	assert(verify(ans));
}

int main() {
	run();
	return 0;
}