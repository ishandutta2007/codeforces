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

const int MAXLEN=500000;
const int MOD=1000000007;

int slen,h,w;
char s[MAXLEN+1];

void run() {
	scanf("%d%d%d%s",&slen,&h,&w,s);
	int dx=0; REP(i,slen) if(s[i]=='U') --dx; else if(s[i]=='D') ++dx; if(dx>0) { REP(i,slen) if(s[i]=='U') s[i]='D'; else if(s[i]=='D') s[i]='U'; dx=-dx; }
	int dy=0; REP(i,slen) if(s[i]=='L') --dy; else if(s[i]=='R') ++dy; if(dy>0) { REP(i,slen) if(s[i]=='L') s[i]='R'; else if(s[i]=='R') s[i]='L'; dy=-dy; }
	//printf("delta=(%d,%d) %s\n",dx,dy,s);

	ll ret=0; int lx=0,hx=h-1,ly=0,hy=w-1;
	{
		int x=0,y=0;
		REP(i,slen) {
			ret+=(ll)(hx-lx+1)*(hy-ly+1)%MOD;
			if(s[i]=='U') --x; else if(s[i]=='D') ++x; else if(s[i]=='L') --y; else if(s[i]=='R') ++y;
			//printf("\t%lld (%d,%d)\n",ret,x,y);
			if(lx+x<0) ++lx; if(hx+x>=h) --hx; if(ly+y<0) ++ly; if(hy+y>=w) --hy;
			if(lx>hx||ly>hy) break;
		}
		ret%=MOD;
	}
	//printf("first step=(%d..%d)-(%d..%d) [%lld]\n",lx,hx,ly,hy,ret);
	if(lx>hx||ly>hy) { printf("%d\n",(int)ret); return; }
	if(dx==0&&dy==0) { printf("-1\n"); return; }
	int clx=lx+dx,chx=hx+dx,cly=ly+dy,chy=hy+dy;
	if(chx>=lx&&chy>=ly) {
		int x=0,y=0; ll up=0,left=0,diag=0;
		REP(i,slen) {
			if(s[i]=='U') --x; else if(s[i]=='D') ++x; else if(s[i]=='L') --y; else if(s[i]=='R') ++y;
			if(clx+x<0) diag+=(ll)(i+1)*(ly-cly)%MOD,up+=i+1,++clx;
			if(cly+y<0) diag+=(ll)(i+1)*(lx-clx)%MOD,left+=i+1,++cly;
		}
		//printf("each step: left=%lld, up=%lld, diag=%lld\n",left,up,diag);
		clx=lx+dx,cly=ly+dy;
		while(chx>=lx&&chy>=ly) {
			ret+=diag;
			ret+=(chx-lx+1)*left%MOD;
			ret+=(chy-ly+1)*up%MOD;
			ret+=(ll)(chx-lx+1)*(chy-ly+1)%MOD*slen%MOD;
			//printf("\t(%d..%d)-(%d..%d) [%lld]\n",clx,chx,cly,chy,ret);
			chx+=dx,chy+=dy;
		}
		ret%=MOD;
	}
	{
		int x=0,y=0;
		REP(i,slen) {
			ret+=(ll)(chx-clx+1)*(chy-cly+1)%MOD;
			if(s[i]=='U') --x; else if(s[i]=='D') ++x; else if(s[i]=='L') --y; else if(s[i]=='R') ++y;
			if(clx+x<0) ++clx; if(cly+y<0) ++cly;
			if(clx>chx||cly>chy) break;
		}
		ret%=MOD;
	}
	printf("%d\n",ret);
}


int main() {
	run();
	return 0;
}