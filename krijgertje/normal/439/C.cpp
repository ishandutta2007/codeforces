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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n,nparts,nevenparts,noddparts;
int a[100000];
int part[100000];

int cnt[100000];
int fst[100000];
int nxt[100000];

void run() {
	scanf("%d%d%d",&n,&nparts,&nevenparts); noddparts=nparts-nevenparts;
	REP(i,n) scanf("%d",&a[i]);

	int nodd=0,neven=0; REP(i,n) if(a[i]%2==0) ++neven; else ++nodd;
	if(nodd<noddparts||(nodd-noddparts)%2!=0||neven+(nodd-noddparts)/2<nevenparts) { printf("NO\n"); return; }

	memset(part,-1,sizeof(part));
	int haveodd=0,haveeven=0,spareodd=-1;
	REP(i,n) if(a[i]%2==0) {
		if(haveeven<nevenparts) { part[i]=noddparts+haveeven; ++haveeven; }
		else { part[i]=0; }
	} else {
		if(haveodd<noddparts) { part[i]=haveodd; ++haveodd; }
		else if(spareodd==-1) { spareodd=i; }
		else if(haveeven<nevenparts) { part[i]=part[spareodd]=noddparts+haveeven; ++haveeven; spareodd=-1; }
		else { part[i]=part[spareodd]=0; spareodd=-1; }
	}
	assert(spareodd==-1&&haveodd==noddparts&&haveeven==nevenparts);

	REP(i,nparts) cnt[i]=0,fst[i]=-1;
	REP(i,n) { nxt[i]=fst[part[i]]; fst[part[i]]=i; ++cnt[part[i]]; }

	printf("YES\n");
	REP(i,nparts) { printf("%d",cnt[i]); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",a[x]); puts(""); }
}

int main() {
	run();
	return 0;
}