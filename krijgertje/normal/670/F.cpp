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

const int MAXSLEN=1000000;

char s[MAXSLEN+1]; int slen;
char p[MAXSLEN+1]; int plen;

int cnt[10];
char a[MAXSLEN+1];
char b[MAXSLEN+1];

int cntdig(int n) { int ret=1; for(int x=n;x>=10;x/=10) ++ret; return ret; }

bool createa() {
	int y=-1; FOR(i,1,10) if(cnt[i]>0) { y=i; break; } if(y==-1) return false;
	int at=0; a[at++]='0'+y;
	bool pstart=true; FOR(i,1,plen) if(p[i]!=p[0]) { if(p[i]>p[0]) pstart=false; break; }
	REP(i,10) {
		if(p[0]=='0'+i&&pstart) REP(j,plen) a[at++]=p[j];
		REP(j,cnt[i]-(i==y?1:0)) a[at++]='0'+i;
		if(p[0]=='0'+i&&!pstart) REP(j,plen) a[at++]=p[j];
	}
	a[at]='\0'; return true;
}

bool createb() {
	bool any=false; REP(i,10) if(cnt[i]) any=true;
	if(p[0]=='0'&&(plen!=1||any)) return false;
	int at=0; REP(j,plen) b[at++]=p[j];
	REP(i,10) REP(j,cnt[i]) b[at++]='0'+i;
	b[at]='\0'; return true;
}

void run() {
	scanf("%s%s",s,p); slen=strlen(s); plen=strlen(p);
	memset(cnt,0,sizeof(cnt)); REP(i,slen) ++cnt[s[i]-'0'];

	int nlen=1; while(nlen+cntdig(nlen)<slen) ++nlen;
	assert(nlen+cntdig(nlen)==slen); for(int x=nlen;x!=0;x/=10) { int y=x%10; assert(cnt[y]>0); --cnt[y]; }
	REP(i,plen) { int y=p[i]-'0'; assert(cnt[y]>0); --cnt[y]; }

	bool aok=createa();
	bool bok=createb();
	assert(aok||bok);
	printf("%s\n",!bok||aok&&strcmp(a,b)<=0?a:b);
}

int main() {
	run();
	return 0;
}