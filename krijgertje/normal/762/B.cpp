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

const int MAXN=300000;

int needa,needb,needc,n;
int a[MAXN],na;
int b[MAXN],nb;
int c[MAXN],nc;

void run() {
	scanf("%d%d%d%d",&needa,&needb,&needc,&n);
	na=nb=0;
	REP(i,n) {
		int x; char s[10]; scanf("%d%s",&x,s);
		if(strcmp(s,"USB")==0) a[na++]=x;
		if(strcmp(s,"PS/2")==0) b[nb++]=x;
	}
	int cnt=0; ll ret=0;
	sort(a,a+na); REP(i,min(na,needa)) ++cnt,ret+=a[i];
	sort(b,b+nb); REP(i,min(nb,needb)) ++cnt,ret+=b[i];
	nc=0; FOR(i,min(na,needa),na) c[nc++]=a[i]; FOR(i,min(nb,needb),nb) c[nc++]=b[i]; sort(c,c+nc);
	REP(i,min(nc,needc)) ++cnt,ret+=c[i];
	printf("%d %lld\n",cnt,ret);
}

int main() {
	run();
	return 0;
}