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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN=100000;
const int MAXA=10000000;

int n,want;
int a[MAXN];
vector<int> ans;

int pmn[MAXA+1];
vector<int> p[MAXN];

int cnt[MAXA+1];

bool alive[MAXN];
vector<int> special;

void upd(int idx) {
	vector<int> prod(1<<SZ(p[idx])); prod[0]=1; cnt[1]++;
	REPSZ(bit,p[idx]) REP(pmask,1<<bit) { int mask=pmask|(1<<bit); prod[mask]=prod[pmask]*p[idx][bit]; cnt[prod[mask]]++; }
}

int calc(int idx) {
	int ret=0; vector<int> prod(1<<SZ(p[idx])); prod[0]=1; ret+=cnt[1]; 
	REPSZ(bit,p[idx]) REP(pmask,1<<bit) { int mask=pmask|(1<<bit); int z=prod[mask]=-prod[pmask]*p[idx][bit]; if(z<0) ret-=cnt[-z]; else ret+=cnt[z]; }
	return ret; 
}


void solve() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXA) if(pmn[i]==-1) for(int j=i;j<=MAXA;j+=i) if(pmn[j]==-1) pmn[j]=i;
	REP(i,n) { p[i].clear(); int x=a[i]; while(x!=1) { if(SZ(p[i])==0||pmn[x]!=p[i][SZ(p[i])-1]) p[i].PB(pmn[x]); x/=pmn[x]; } }
	//REP(i,n) { printf("p%d:",i); REPSZ(j,p[i]) printf(" %d",p[i][j]); puts(""); }
	
	memset(cnt,0,sizeof(cnt));
	REP(i,n) upd(i);
	//REPE(i,MAXA) if(cnt[i]!=0) printf("%d: %d\n",i,cnt[i]);
	
	int specialroot=-1;
	REP(i,n) if(calc(i)>=2) { specialroot=i; break; }
	//REP(i,n) printf("%d: %d\n",i,calc(i));
	
	REP(i,n) alive[i]=true;
	if(specialroot==-1) {
		//printf("no special\n");
		memset(cnt,0,sizeof(cnt));
		vector<int> clique,skipped;
		REP(i,n) if(calc(i)==0) { clique.PB(i); upd(i); } else { skipped.PB(i); }
		//printf("clique:"); REPSZ(i,clique) printf(" %d",clique[i]); puts("");
		//printf("skipped:"); REPSZ(i,skipped) printf(" %d",skipped[i]); puts("");
		assert(SZ(skipped)<=SZ(clique));
		assert(want<=SZ(clique));
		ans.clear(); REP(i,want) ans.PB(clique[i]);
	} else {
		special.clear(); special.PB(specialroot); REP(i,n) if(i!=specialroot&&gcd(a[i],a[specialroot])==1&&SZ(special)<3) special.PB(i);
		assert(SZ(special)>=3);
		REPSZ(i,special) alive[special[i]]=false;

		memset(cnt,0,sizeof(cnt));
		REP(i,n) if(alive[i]) upd(i);
		vector<int> clique;
		REP(i,n) if(alive[i]&&calc(i)==0) clique.PB(i);
		REPSZ(i,clique) alive[clique[i]]=false;
		vector<int> unfair; REP(i,n) if(alive[i]) unfair.PB(i);
		//printf("nspecial=%d nclique=%d nunfair=%d\n",SZ(special),SZ(clique),SZ(unfair));
		
		if(want<=SZ(clique)) {
			ans.clear(); REP(i,want) ans.PB(clique[i]);
		} else if(want<=SZ(special)) {
			ans.clear(); REP(i,want) ans.PB(special[i]);
		} else {
			assert(SZ(special)<want&&want<=SZ(special)+SZ(unfair));
			int lo=0,hi=SZ(unfair),hicnt=SZ(unfair);
			while(lo+1<hi) {
				int mi=lo+(hi-lo)/2;
				memset(cnt,0,sizeof(cnt));
				REP(i,mi) upd(unfair[i]);
				int micnt=0; REP(i,mi) if(calc(unfair[i])>=1) ++micnt;
				if(want<=SZ(special)+micnt) hi=mi,hicnt=micnt; else lo=mi;
			}
			int nrem=SZ(special)+hicnt-want;
			vector<int> remopt;
			memset(cnt,0,sizeof(cnt));
			REP(i,hicnt-1) upd(unfair[i]);
			REP(i,hicnt-1) if(calc(unfair[i])==0&&gcd(a[unfair[i]],a[unfair[hicnt-1]])==1) remopt.PB(unfair[i]);
			assert(nrem<=SZ(remopt));
			REP(i,nrem) if(i!=SZ(remopt)-1) alive[remopt[i]]=false;
			//printf("nrem=%d SZ(remopt)=%d\n",nrem,SZ(remopt));
			
			ans.clear();
			REPSZ(i,special) if(nrem==0||nrem<SZ(remopt)||i!=SZ(special)-1) ans.PB(special[i]);
			memset(cnt,0,sizeof(cnt));
			REP(i,hicnt) upd(unfair[i]);
			REP(i,hicnt) if(alive[unfair[i]]&&calc(unfair[i])>=1) ans.PB(unfair[i]);
			assert(SZ(ans)==want);
		}
	}
}

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	REPSZ(i,ans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}