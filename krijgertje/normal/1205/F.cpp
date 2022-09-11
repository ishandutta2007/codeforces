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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100;
const int MAXWANT=MAXN*(MAXN+1)/2;

int prv[MAXN+1][MAXWANT+1];
int lst[MAXN+1][MAXWANT+1];


void precalc() {
	REPE(i,MAXN) REPE(j,MAXWANT) prv[i][j]=-2;
	prv[0][0]=-1;
	REPE(i,MAXN) REPE(j,MAXWANT) if(prv[i][j]!=-2) FORE(k,1,MAXN-i) {
		int ni=i+k,nj=j+k*(k+1)/2; if(prv[ni][nj]==-2) prv[ni][nj]=k;
	}
	REPE(i,MAXN) REPE(j,MAXWANT) {
		lst[i][j]=-2;
		if(i-1>=0&&prv[i-1][j]!=-2) lst[i][j]=1;
		if(lst[i][j]==-2&&j>=1) FORE(k,4,i) if(prv[i-k][j-1]!=-2) { lst[i][j]=k; break; }
	}
	//REPE(i,MAXN) REPE(j,MAXWANT) if(prv[i][j]!=-2) printf("prv %d %d: %d\n",i,j,prv[i][j]);
	//REPE(i,MAXN) REPE(j,MAXWANT) if(lst[i][j]!=-2) printf("lst %d %d: %d\n",i,j,lst[i][j]);
}

int n,want;
vector<int> ans;

bool solve() {
	if(want<n) return false;
	int x=n,y=want-n;
	if(lst[x][y]==-2) return false;

	int fin=lst[x][y];
	x-=fin; if(fin!=1) y-=1;
	vector<int> parts;
	while(x!=0||y!=0) { int k=prv[x][y]; parts.PB(k+1); x-=k; y-=k*(k+1)/2; }
	//printf("fin=%d parts=",fin); REPSZ(i,parts) { if(i!=0) printf(","); printf("%d",parts[i]); } puts("");

	int rem=0; REPSZ(i,parts) rem+=parts[i]-1;
	vector<int> pref,rsuff;
	REPSZ(i,parts) {
		int cnt=parts[i]; rem-=cnt-1;
		if(i%2==0) {
			for(int j=cnt;j>=2;--j) rsuff.PB(rem+j);
		} else {
			for(int j=cnt;j>=2;--j) pref.PB(rem+j);
		}
	}
	ans.clear(); REPSZ(i,pref) ans.PB(pref[i]); ans.PB(1); REPSZ(i,rsuff) ans.PB(rsuff[SZ(rsuff)-i-1]);
	//printf("ans:"); REPSZ(i,ans) printf(" %d",ans[i]); puts("");
	if(fin!=1) {
		REPSZ(i,ans) ++ans[i];
		for(int i=4;i<=fin;i+=2) ans.PB(n-(fin-i));
		ans.PB(1); for(int i=3;i<=fin;i+=2) ans.PB(n-(fin-i));
		if(fin%2==1) swap(ans[SZ(ans)-2],ans[SZ(ans)-1]);
	}
	//printf("ans:"); REPSZ(i,ans) printf(" %d",ans[i]); puts("");
	return true;
}

void run() {
	scanf("%d%d",&n,&want);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i,ans) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

void verify() {
	assert(SZ(ans)==n); vector<bool> seen(n,false);
	int have=0;
	REP(i,n) {
		int x=ans[i]-1; assert(x>=0&&x<n&&!seen[x]); seen[x]=true;
		int mn=x,mx=x,len=1; ++have;
		FOR(j,i+1,n) {
			int y=ans[j]-1;
			mn=min(mn,y),mx=max(mx,y),++len; if(mx-mn+1==len) ++have;
		}
	}
	assert(have==want);
}

void stress() {
	for(n=1;n<=MAXN;++n) {
		for(want=1;want<=n*(n+1)/2;++want) {
			bool res=solve();
			if(res) verify();
		}
		printf("done %d\n",n);
	}
}


int main() {
	precalc();
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	//stress();
	return 0;
}