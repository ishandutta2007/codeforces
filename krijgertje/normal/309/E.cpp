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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n;
int l[2000],r[2000];
bool tied[2000][2000];

bool can[2000];
int pos[2000];
int maxpos[2000];
int cnt[2000];

bool go(int maxdiff) {
//	printf("%d:\n",maxdiff);
	REP(i,n) { can[i]=true; pos[i]=-1; maxpos[i]=n-1; }
	REP(i,n) {
//		printf("\t%d:\n",i);
//		printf("\t"); REP(j,n) if(pos[j]==-1) printf("[%d-%d,%d,%c]",l[j],r[j],maxpos[j],can[j]?'V':'.'); puts("");
		int now=-1; REP(j,n) if(can[j]&&(now==-1||r[j]<r[now])) now=j;
		assert(now!=-1);
		pos[now]=i;
		REP(j,n) if(pos[j]==-1&&tied[now][j]) maxpos[j]=min(maxpos[j],i+maxdiff);
		memset(cnt,0,sizeof(cnt));
		REP(j,n) if(pos[j]==-1) cnt[maxpos[j]-i]++;
		FOR(j,1,n) cnt[j]+=cnt[j-1];
//		printf("\t"); REP(j,n) if(cnt[j]>0&&(j==0||cnt[j]>cnt[j-1])) printf("(%d=%d)",j,cnt[j]); puts("");
		REP(j,n) if(cnt[j]>j) return false;
		int firstbound=INT_MAX; FOR(j,1,n) if(cnt[j]==j) { firstbound=j; break; }
		REP(j,n) can[j]=pos[j]==-1&&maxpos[j]<=i+firstbound;
	}
	return true;
}

int ans[2000];

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&l[i],&r[i]);
	REP(i,n) REP(j,n) tied[i][j]=i!=j&&l[i]<=r[j]&&l[j]<=r[i];
	
	int ll=-1,rr=n-1; // (ll,rr]
	while(ll+1<rr) {
		int mm=ll+(rr-ll+1)/2;
		if(go(mm)) rr=mm; else ll=mm;
	}

	go(rr);
	REP(i,n) ans[pos[i]]=i+1;
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}