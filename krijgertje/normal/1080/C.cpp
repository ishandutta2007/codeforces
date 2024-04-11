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

int R,C;
int c[4],r[4];

int rr[6],nrr;
int cc[6],ncc;
int col[5][5];

pair<ll,ll> calc(int a,int b) {
	ll tot=(ll)a*b;
	return MP((tot+1)/2,tot/2);
}

pair<ll,ll> solve() {
	nrr=0; rr[nrr++]=0,rr[nrr++]=R; REP(i,4) rr[nrr++]=r[i]; sort(rr,rr+nrr); nrr=unique(rr,rr+nrr)-rr; REP(i,4) r[i]=lower_bound(rr,rr+nrr,r[i])-rr;
	ncc=0; cc[ncc++]=0,cc[ncc++]=C; REP(i,4) cc[ncc++]=c[i]; sort(cc,cc+ncc); ncc=unique(cc,cc+ncc)-cc; REP(i,4) c[i]=lower_bound(cc,cc+ncc,c[i])-cc;
	REP(i,nrr-1) REP(j,ncc-1) col[i][j]=2;
	FOR(i,r[0],r[1]) FOR(j,c[0],c[1]) col[i][j]=0;
	FOR(i,r[2],r[3]) FOR(j,c[2],c[3]) col[i][j]=1;
	//for(int i=nrr-2;i>=0;--i) { REP(j,ncc-1) printf("%d",col[i][j]); puts(""); }

	pair<ll,ll> ret=MP(0,0);
	REP(i,nrr-1) REP(j,ncc-1) {
		pair<ll,ll> cur=calc(rr[i+1]-rr[i],cc[j+1]-cc[j]);
		if((rr[i]+cc[j])%2==1) swap(cur.first,cur.second);
		//printf("\t(%lld,%lld)\n",cur.first,cur.second);
		if(col[i][j]==0) ret.first+=cur.first+cur.second;
		if(col[i][j]==1) ret.second+=cur.first+cur.second;
		if(col[i][j]==2) ret.first+=cur.first,ret.second+=cur.second;
	}
	return ret;
}

void run() {
	scanf("%d%d",&R,&C);
	scanf("%d%d%d%d",&c[0],&r[0],&c[1],&r[1]); --c[0],--r[0];
	scanf("%d%d%d%d",&c[2],&r[2],&c[3],&r[3]); --c[2],--r[2];
	pair<ll,ll> ans=solve();
	printf("%lld %lld\n",ans.first,ans.second);

}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}