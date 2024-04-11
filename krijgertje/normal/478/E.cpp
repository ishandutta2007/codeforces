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

ll MOD,pos;
ll p10[15];

#define SEARCHLIM 101000
bool debug=false;

// returns number of wavy numbers x=[y][...z=len_numbers...] for which comp(y,bound)==dir?+1:-1 x%MOD=rem)
ll mem[14][10][2][SEARCHLIM];
ll calc(int len,int bound,int dir,int rem) {
	if(len==0) return rem==0?1:0;
	ll &ret=mem[len][bound][dir][rem];
	if(ret==-1) {
		ret=0;
		if(dir==1) {
			if(bound+1<=9) ret+=calc(len,bound+1,dir,rem);
			if(bound-1>=0) {
				int nrem=((rem-bound*p10[len-1])%MOD+MOD)%MOD;
				ret+=calc(len-1,bound-1,1-dir,nrem);
			}
		} else {
			if(bound-1>=0) ret+=calc(len,bound-1,dir,rem);
			if(bound+1<=9) {
				int nrem=((rem-bound*p10[len-1])%MOD+MOD)%MOD;
				ret+=calc(len-1,bound+1,1-dir,nrem);
			}
		}
		//if(ret>0) printf("%d %d %d %d = %lld\n",len,bound,dir,rem,ret);
	}
	return ret;
}

bool iswavy(ll x) {
	if(x<=0) return false;
	if(x<=99) return true;
	int a=x%10; x/=10; int b=x%10; x/=10;
	while(x>0) {
		int c=x%10; x/=10;
		if(!(b<a&&b<c||b>a&&b>c)) return false;
		a=b,b=c;
	}
	return true;
}

void search() {
	ll pos=::pos;
	memset(mem,-1,sizeof(mem));
	if(MOD!=22) FORE(ret,10,99) if(ret%MOD==0) { if(pos--==0) { cout<<ret<<endl; return; } }
	FORE(len,3,14) {
		FORE(first,1,9) REP(dir,2) {
			debug=len<3||len==3&&(first<4||first==4&&(dir<1||dir==1));
			int bound=first+(dir==0?-1:+1); if(bound<0||bound>9) continue;
			int rem=((-p10[len-1]*first)%MOD+MOD)%MOD;
			ll cur=calc(len-1,bound,dir,rem);
			//printf("\t%d%c",first,dir==0?'V':'^'); REP(i,len-2) printf("?"); printf(" = %lld\n",cur);
			if(pos>=cur) { pos-=cur; continue; }
			//printf("\t%d%c",first,dir==0?'V':'^'); REP(i,len-2) printf("?"); printf("\n");
			ll ret=p10[len-1]*first;
			int clen=len-1,cbound=bound,cdir=dir,crem=rem;
			while(clen>0) {
				//printf("%d %d %d %d (%lld)\n",clen,cbound,cdir,crem,ret);
				if(cdir==1) {
					if(cbound-1>=0) {
						int nrem=((crem-cbound*p10[clen-1])%MOD+MOD)%MOD;
						cur=calc(clen-1,cbound-1,1-cdir,nrem);
						if(pos>=cur) { pos-=cur; } else {
							ret+=p10[clen-1]*cbound; clen--; cbound--; cdir=1-cdir; crem=nrem; continue;
						}
					}
					assert(cbound+1<=9);
					++cbound; continue;
				} else {
					if(cbound-1>=0) {
						cur=calc(clen,cbound-1,cdir,crem);
						if(pos>=cur) { pos-=cur; } else {
							--cbound; continue;
						}
					}
					assert(cbound+1<=9);
					int nrem=((crem-cbound*p10[clen-1])%MOD+MOD)%MOD;
					ret+=p10[clen-1]*cbound; clen--; cbound++; cdir=1-cdir; crem=nrem; continue;
				}
			}
			printf("%lld\n",ret);
			return;
		}
	}
	printf("-1\n");
}

#define TAILDIG 6
#define TAILMOD 1000000
bool tailok[TAILMOD];
ll mintimes[TAILMOD]; //mintimes[x] -> for a number y=aaaaaxxxxxx the minimum number of times needed to add MOD so that for y+mintimes[x] the last 6 digits wave
int q[TAILMOD],qhead,qtail;

int dig[20];
void test() {
	//98979382406484
	{
		memset(mintimes,-1,sizeof(mintimes));
		memset(tailok,false,sizeof(tailok));
		qhead=qtail=0;
		REP(i,TAILMOD) {
			for(int x=i,j=0;j<TAILDIG;x/=10,++j) dig[j]=x%10;
			bool ok=true; FORE(j,1,TAILDIG-2) if(!(dig[j]>dig[j-1]&&dig[j]>dig[j+1]||dig[j]<dig[j-1]&&dig[j]<dig[j+1])) ok=false; if(!ok) continue;
			int at=((i-MOD)%TAILMOD+TAILMOD)%TAILMOD; tailok[i]=true;
			if(mintimes[at]==-1) { mintimes[at]=1; q[qhead++]=at; }
		}
		while(qtail<qhead) {
			int at=q[qtail++];
			int to=((at-MOD)%TAILMOD+TAILMOD)%TAILMOD;
			if(mintimes[to]==-1) { mintimes[to]=mintimes[at]+1; q[qhead++]=to; }
		}
	}

	ll pos=::pos;
	ll ret=MOD; ll debug=0;
	while(ret<=100000000000000L) {
		++debug;
		int tail=-1;
		if(ret>=TAILMOD) {
			tail=ret%TAILMOD;
			if(!tailok) { ret+=MOD*mintimes[tail]; }
		}
		//printf("%lld\n",ret);
		int len=0; for(ll x=ret;x>0;x/=10) dig[len++]=x%10;
		//printf("%d: ",len); REP(i,len) printf("%d",dig[i]); puts("");
		bool change=false;
		for(int at=len-2;at>=1;--at) {
			if(dig[at]==dig[at+1]||dig[at]>dig[at+1]&&dig[at]<=dig[at-1]) {
				ll times=((ret/p10[at]+1)*p10[at]-ret+MOD-1)/MOD;
				if(tail!=-1) { ll times2=mintimes[tail]; if(times2>times) times=times2; }
				ret+=times*MOD; change=true; break;
			}
			if(dig[at]<dig[at+1]&&dig[at]>=dig[at-1]) {
				ll times=((ret/p10[at]*10+dig[at]+1)*p10[at-1]-ret+MOD-1)/MOD;
				if(tail!=-1) { ll times2=mintimes[tail]; if(times2>times) times=times2; }
				ret+=times*MOD; change=true; break;
			}
		}
		if(change)  continue;
		if(pos--==0) { cout<<ret<<endl; return; }
		{
			ll times=1;
			if(tail!=-1) { ll times2=mintimes[tail]; if(times2>times) times=times2; }
			ret+=times*MOD;
		}
	}
/*	for(ll ret=MOD;ret<=;ret+=MOD) {
		if(!iswavy(ret)) continue;
		//cout<<"\t"<<pos<<" "<<ret<<endl;
		if(pos--==0) { cout<<ret<<endl; return; }
	} */
	printf("-1\n");
}

void run() {
	cin>>MOD>>pos; --pos;
	p10[0]=1; FORE(i,1,14) p10[i]=p10[i-1]*10;
	if(MOD<=SEARCHLIM) {
		search();
	} else {
		test();
	}
}

int main() {
	run();
	return 0;
}