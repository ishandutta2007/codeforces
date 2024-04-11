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

const int MAXN=22;
struct Trip { ll l,r,t; int id; };
bool operator<(const Trip &a,const Trip &b) { return a.l<b.l; }

int n,npass;
Trip trip[MAXN];
pair<int,int> ans[MAXN];

pair<ll,int> byt[MAXN];

ll dp[1<<MAXN]; // dp[mask] = min day at which we can acquire all visas in mask in one passport (acquiring each of those visas in time), assuming we only need this passport for visas in mask
pair<int,int> act[1<<MAXN];

void rec(int mask,int cpass) { while(mask!=0) { int i=act[mask].first; ans[trip[i].id]=MP(cpass,act[mask].second); mask-=1<<i; } }

bool upd(int mask,ll val,int i,int l) { if(val>=dp[mask]) return false; dp[mask]=val,act[mask]=MP(i,l); return true; }
bool solve() {
	sort(trip,trip+n);
	REP(i,n) byt[i]=MP(trip[i].t,i); sort(byt,byt+n);
	//REP(i,n) printf("trip%d: [%lld..%lld) {%lld} (id=%d)\n",i,trip[i].l,trip[i].r,trip[i].t,trip[i].id);

	REP(i,1<<n) dp[i]=LLONG_MAX,act[i]=MP(-2,-2); dp[0]=0,act[0]=MP(-1,-1);
	REP(mask,1<<n) if(dp[mask]!=LLONG_MAX) {
		//printf("%x: %lld (%x)\n",mask,dp[mask],mask-(1<<act[mask].first));
		int at=0; ll l=dp[mask]; if(l%2==0) ++l; ll r=l;
		REP(i,n) {
			int cur=byt[i].second;
			if(mask&(1<<cur)) continue;
			r=max(r,l+trip[cur].t);
			while(at<n&&r>trip[at].l) {
				if((mask&(1<<at))!=0||l>trip[at].l) {
					l=max(l,trip[at].r+1);
					r=max(r,l+trip[cur].t);
				} else {
					r=max(r,trip[at].r);
				}
				++at;
			}
			if(r>trip[cur].l) continue;
			if(upd(mask|(1<<cur),r,cur,(l+1)/2)) {
				//printf("->%x %lld\n",mask|(1<<cur),l);
			}
		}
	}
	if(npass==1) {
		if(dp[(1<<n)-1]!=LLONG_MAX) {
			rec((1<<n)-1,1);
			return true;
		}
	} else {
		REP(i,1<<n) if(dp[i]!=LLONG_MAX&&dp[(1<<n)-1-i]!=LLONG_MAX) {
			//printf("%x %x\n",i,(1<<n)-1-i);
			rec(i,1);
			rec((1<<n)-1-i,2);
			return true;
		}
	}
	return false;
}


void run() {
	scanf("%d%d",&n,&npass);
	REP(i,n) { int len; scanf("%lld%d%lld",&trip[i].l,&len,&trip[i].t); --trip[i].l,trip[i].l*=2,trip[i].r=trip[i].l+2*len,trip[i].t*=2,trip[i].id=i; }

	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) printf("%d %d\n",ans[i].first,ans[i].second);
}

int main() {
	run();
	return 0;
}