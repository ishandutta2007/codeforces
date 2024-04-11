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

const int MAXLEN=5000;

char s[MAXLEN+1]; int n;
int want;

int len[4][MAXLEN];
int can[MAXLEN][MAXLEN],ncan[MAXLEN],at[MAXLEN];

bool match(int a,int b) { return 0<=a&&a<n&&0<=b&&b<n&&s[a]==s[b]; }
void sol(int a,int b ) { can[a][ncan[a]++]=b; }
void run() {
	scanf("%s%d",s,&want); n=strlen(s); --want;

	REP(j,n) ncan[j]=at[j]=0;
	REP(i,4) {
		int dboth=i==0||i==3?1:0,dright=i%2==0?1:0;
		REP(j,n) {
			len[i][j]=0;
			while(match(j-2*len[i][j]-dboth,j+2*len[i][j]+dright+dboth)) {
				sol(j-2*len[i][j]-dboth,j+2*len[i][j]+dright+dboth);
				++len[i][j];
			}
		}
	}
	REP(j,n) sort(can[j],can[j]+ncan[j]);
	//REP(j,n) { printf("%d:",j); REP(i,4) printf(" %d",len[i][j]); puts(""); }

	for(int pos=0;;++pos) {
		int na=0,nb=0,nc=0;
		REP(j,n) {
			while(at[j]<ncan[j]&&j+pos>can[j][at[j]]) ++nc,++at[j];
			if(at[j]<ncan[j]) (s[j+pos]=='a'?na:nb)+=ncan[j]-at[j];
		}
		//printf("(%d->%d,%d,%d)",want,nc,na,nb); printf("["); REP(j,n) FOR(k,at[j],ncan[j]) printf("%d-%d ",j,can[j][k]); printf("]");
		if(want<nc) { puts(""); break; } want-=nc;
		if(want<na) { printf("a"); REP(j,n) if(at[j]<ncan[j]&&s[j+pos]!='a') at[j]=ncan[j]; continue; } want-=na;
		if(want<nb) { printf("b"); REP(j,n) if(at[j]<ncan[j]&&s[j+pos]!='b') at[j]=ncan[j]; continue; } want-=nb;
		printf("err\n"); break;
	}
}

int main() {
	run();
	return 0;
}