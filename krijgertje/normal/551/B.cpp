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

const int MAXLEN=100000;

char shave[MAXLEN+1]; int havelen;
char sa[MAXLEN+1]; int alen;
char sb[MAXLEN+1]; int blen;

int have[26];
int a[26];
int b[26];



void run() {
	memset(have,0,sizeof(have)); memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
	scanf("%s",shave); havelen=strlen(shave); REP(i,havelen) have[shave[i]-'a']++;
	scanf("%s",sa); alen=strlen(sa); REP(i,alen) a[sa[i]-'a']++;
	scanf("%s",sb); blen=strlen(sb); REP(i,blen) b[sb[i]-'a']++;

	int maxa=0,maxb=0;
	for(int na=0;;++na) {
		bool ok=true;
		int nb=INT_MAX;
		REP(i,26) if(na*a[i]>have[i]) ok=false; else if(b[i]>0) nb=min(nb,(have[i]-na*a[i])/b[i]);
		if(!ok) break;
		if(na+nb>maxa+maxb) maxa=na,maxb=nb;
	}
	REP(i,maxa) printf("%s",sa); REP(i,maxb) printf("%s",sb); REP(i,26) REP(j,have[i]-maxa*a[i]-maxb*b[i]) printf("%c",'a'+i); puts("");
}

int main() {
	run();
	return 0;
}