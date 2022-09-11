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

const int MOD=998244353;
const int MAXLEN=20;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

ll l,r; int mxdig;



int d[MAXLEN+1]; int nd;
int bcnt[1<<10];
int p10[MAXLEN+1];

bool done[MAXLEN][1<<10][2];
pair<int,int> mem[MAXLEN][1<<10][2];

pair<int,int> go(int at,int mask,bool eq) { // (cnt,sum)
	if(bcnt[mask]>mxdig) return MP(0,0);
	if(at==nd) return mask==0?MP(0,0):MP(1,0);
	if(done[at][mask][eq?1:0]) return mem[at][mask][eq?1:0]; else done[at][mask][eq?1:0]=true;
	pair<int,int> ret=MP(0,0);
	REP(i,10) {
		if(eq&&i>d[at]) continue;
		int nmask=mask; if(mask!=0||i!=0) nmask|=1<<i;
		pair<int,int> cur=go(at+1,nmask,eq&&i==d[at]);
		inc(ret.first,cur.first);
		inc(ret.second,(cur.second+(ll)cur.first*i%MOD*p10[nd-at-1])%MOD);
	}
	//printf("go(%d,%d,%d)=(%d,%d)\n",at,mask,eq?1:0,ret.first,ret.second);
	return mem[at][mask][eq?1:0]=ret;
}

int calc(ll lim) {
	if(lim==0) return 0;
	nd=0; for(ll x=lim;x!=0;x/=10) d[nd++]=x%10; reverse(d,d+nd);
	
	REP(i,1<<10) { bcnt[i]=0; REP(j,10) if(i&(1<<j)) ++bcnt[i]; }
	p10[0]=1; FORE(i,1,nd) p10[i]=(ll)10*p10[i-1]%MOD;

	memset(done,false,sizeof(done));
	return go(0,0,true).second;
}

int solve() {
	int ret=calc(r)-calc(l-1); if(ret<0) ret+=MOD; return ret;
}

void run() {
	scanf("%lld%lld%d",&l,&r,&mxdig);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}