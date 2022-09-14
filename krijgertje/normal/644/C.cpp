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

const int MAXN=100000;

int n;
char s[7+20+21+1];
char hostname[MAXN][20+1];
char pathname[MAXN][21+1];

int p[MAXN];
bool pcmp(const int &a,const int &b) { int ret=strcmp(hostname[a],hostname[b]); if(ret!=0) return ret<0; ret=strcmp(pathname[a],pathname[b]); return ret<0; }

char allpaths[MAXN*22+1];
int hfst[MAXN],hidx[MAXN+1],nh;
int ph[MAXN];
bool hcmp(const int &a,const int &b) { int ret=strcmp(allpaths+hidx[a],allpaths+hidx[b]); return ret<0; }

int retfst[MAXN],retlen[MAXN],nret;

void run() {
	scanf("%d",&n);
	REP(i,n) {
		scanf("%s",s); int len=strlen(s),at=7,hi=0,pi=0;
		while(at<len&&s[at]!='/') hostname[i][hi++]=s[at++]; hostname[i][hi]='\0';
		while(at<len) pathname[i][pi++]=s[at++]; pathname[i][pi]='\0';
	}
	
	REP(i,n) p[i]=i; sort(p,p+n,pcmp);
	{ int nn=0; REP(i,n) if(nn==0||strcmp(hostname[p[i]],hostname[p[nn-1]])!=0||strcmp(pathname[p[i]],pathname[p[nn-1]])!=0) p[nn++]=p[i]; n=nn; }
	//REP(i,n) printf("'%s' '%s'\n",hostname[p[i]],pathname[p[i]]);

	nh=0,hidx[nh]=0;
	REP(i,n) {
		if(nh==0||strcmp(hostname[p[i]],hostname[p[i-1]])!=0) {
			if(nh!=0) allpaths[hidx[nh]++]='\0';
			++nh,hidx[nh]=hidx[nh-1],hfst[nh-1]=p[i];
		} else {
			allpaths[hidx[nh]++]='|';
		}
		for(int j=0;pathname[p[i]][j]!='\0';++j) allpaths[hidx[nh]++]=pathname[p[i]][j];
	}
	allpaths[hidx[nh]++]='\0';
	//REP(i,nh) printf("%d: %d..%d = '%s'\n",i,hidx[i],hidx[i+1],allpaths+hidx[i]);

	REP(i,nh) ph[i]=i; sort(ph,ph+nh,hcmp);
	nret=0;
	for(int at=0,to=at;at<nh;at=to) {
		while(to<nh&&strcmp(allpaths+hidx[ph[to]],allpaths+hidx[ph[at]])==0) ++to;
		if(to-at<=1) continue;
		retfst[nret]=at,retlen[nret]=to-at,++nret;
	}
	printf("%d\n",nret);
	REP(i,nret) { REP(j,retlen[i]) { if(j!=0) printf(" "); printf("http://%s",hostname[hfst[ph[retfst[i]+j]]]); } puts(""); }
}

int main() {
	run();
	return 0;
}