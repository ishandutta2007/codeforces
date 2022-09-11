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

int n;
int a[MAXN];

int b[MAXN],nb;
int lis[MAXN],nlis;
int pinc[MAXN];
int pdec[MAXN];

bool dead[MAXN];
vector<vector<int>> ans;

void solve() {
	nb=0; REP(i,n) b[nb++]=a[i]; REP(i,n) dead[i]=false;
	ans.clear();
	while(true) {
		int lim=0; while(lim*(lim+1)/2+lim<nb) ++lim;
		//printf("nb=%d lim=%d\n",nb,lim);
		nlis=0;
		REP(i,nb) {
			int lo=-1,hi=nlis; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(b[i]<lis[mi]) hi=mi; else lo=mi; } int idx=hi;
			pinc[b[i]]=idx==0?-1:lis[idx-1];
			pdec[b[i]]=idx==nlis?-1:lis[idx];
			lis[idx]=b[i];
			nlis=max(nlis,idx+1);
		}
		//printf("lis:"); REP(i,nlis) printf(" %d",lis[i]+1); puts("");
		if(nlis<=lim) {
			REP(i,nlis) { vector<int> cur; for(int x=lis[i];x!=-1;x=pdec[x]) cur.PB(x); reverse(cur.begin(),cur.end()); ans.PB(cur); }
			break;
		} else {
			vector<int> cur; for(int x=lis[nlis-1];x!=-1;x=pinc[x]) cur.PB(x); reverse(cur.begin(),cur.end()); ans.PB(cur);
			REPSZ(i,cur) dead[cur[i]]=true; int nrem=0; REP(i,nb) if(!dead[b[i]]) b[nrem++]=b[i]; nb=nrem;
		}
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) { printf("%d",SZ(ans[i])); REPSZ(j,ans[i]) printf(" %d",ans[i][j]+1); puts(""); }
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}