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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int ncube,nmark; ll want;
int have[25];

int n1;
ll fac[20]; int maxfac;
int ncan[13]; ll can[13][531441];

void gen1(int at,ll chave,int cmark) {
	if(chave>want||cmark>nmark) return;
	if(at>=n1) { can[cmark][ncan[cmark]++]=chave; return; }
	gen1(at+1,chave,cmark);
	gen1(at+1,chave+have[at],cmark);
	if(have[at]<=maxfac) gen1(at+1,chave+fac[have[at]],cmark+1);
}

ll ret;
void inc(ll left,int markleft) {
	REPE(i,min(markleft,n1)) {
		int l=-1,h=ncan[i]; // (]
		while(l+1<h) {
			int m=l+(h-l)/2;
			if(can[i][m]>=left) h=m; else l=m;
		}
		if(h>=ncan[i]||can[i][h]!=left) continue;
		int fst=h;
		l=h,h=ncan[i]; // [)
		while(l+1<h) {
			int m=l+(h-l)/2;
			if(can[i][m]<=left) l=m; else h=m;
		}
		int lst=l;
		ret+=lst-fst+1;
		//printf("%lld %d: %d -> %d..%d\n",left,markleft,i,fst,lst);
	}
}
void gen2(int at,ll chave,int cmark) {
	if(chave>want||cmark>nmark) return;
	if(at>=ncube) { inc(want-chave,nmark-cmark); return; }
	gen2(at+1,chave,cmark);
	gen2(at+1,chave+have[at],cmark);
	if(have[at]<=maxfac) gen2(at+1,chave+fac[have[at]],cmark+1);
}

void run() {
	cin>>ncube>>nmark>>want; REP(i,ncube) cin>>have[i];
	fac[0]=1; maxfac=0; while(fac[maxfac]*(maxfac+1)<=want) fac[maxfac+1]=fac[maxfac]*(maxfac+1),++maxfac;
	n1=ncube/2;
	REPE(i,n1) ncan[i]=0;
	gen1(0,0,0);
	REP(i,n1) sort(can[i],can[i]+ncan[i]);
	//REPE(i,n1) { printf("%d:",i); REP(j,ncan[i]) printf(" %lld",can[i][j]); puts(""); }
	ret=0;
	gen2(n1,0,0);
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}