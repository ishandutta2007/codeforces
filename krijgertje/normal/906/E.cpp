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
const int MAXN=2*MAXLEN;
const int MAXPAL=2+MAXN;
const int ALPH=26;


char a[MAXLEN+1],b[MAXLEN+1],s[MAXN+1]; int alen,blen,n;

int dp[MAXN+1],act[MAXN+1]; // dp[i] is INT_MAX for odd i and minimum # disjoint reverses to make a[0..i/2)=b[0..i/2) (only counting length>1, the last having length act[i]/2)

int npal;
int plen[MAXPAL];
int pto[MAXPAL][ALPH];
int plink[MAXPAL];
int plast;
int pdiff[MAXPAL];
int pdifflink[MAXPAL];
int pdp[MAXPAL];
int pact[MAXPAL];


void pinit() { npal=2; plen[0]=0; plen[1]=-1; REP(i,ALPH) pto[0][i]=-1,pto[1][i]=-1; plink[0]=plink[1]=1; plast=1; }
void padd(int idx) {
	int x=s[idx]-'a';
	int at=plast; while(idx-plen[at]-1<0||s[idx-plen[at]-1]!=s[idx]) at=plink[at];
	if(pto[at][x]==-1) {
		plen[npal]=plen[at]+2;
		if(plen[npal]==1) plink[npal]=0; else { int tmp=plink[at]; while(idx-plen[tmp]-1<0||s[idx-plen[tmp]-1]!=s[idx]) tmp=plink[tmp]; plink[npal]=pto[tmp][x]; }
		REP(i,ALPH) pto[npal][i]=-1; pto[at][x]=npal;
		pdiff[npal]=plen[npal]-plen[plink[npal]];
		pdifflink[npal]=pdiff[npal]==pdiff[plink[npal]]?pdifflink[plink[npal]]:plink[npal];
		++npal;
	}
	plast=pto[at][x];
}
void pprint(int at,int d=0) { REP(i,ALPH) if(pto[at][i]!=-1) { int to=pto[at][i]; printf("%2d:",to); REP(j,d) printf("  "); printf("%c (link=%d,diff=%d,difflink=%d)\n",'a'+i,plink[to],pdiff[to],pdifflink[to]);  pprint(to,d+1); } }
void pprint() { printf("even\n"); pprint(0); printf("odd\n"); pprint(1); }



void upd(int &val,int &act,int idx,int len) { if(len%2==1) return; int j=idx+1-len/2; if(dp[j]<val) val=dp[j],act=len/2; }
void run() {
	scanf("%s%s",a,b); alen=strlen(a),blen=strlen(b); assert(alen==blen); REP(i,alen) s[2*i+0]=a[i],s[2*i+1]=b[i]; n=alen+blen; s[n]='\0';
	//printf("%s\n",s);

	pinit();
	dp[0]=0,act[0]=0;
	REP(i,n) {
		padd(i);
		dp[i+1]=INT_MAX,act[i+1]=-1;
		if(i%2==1&&a[i/2]==b[i/2]&&dp[i-1]!=INT_MAX) dp[i+1]=dp[i-1],act[i+1]=2;
		for(int v=plast;plen[v]>0;v=pdifflink[v]) {
			pdp[v]=INT_MAX,pact[v]=-1;
			if(dp[i+1-plen[pdifflink[v]]-pdiff[v]]!=INT_MAX) pdp[v]=dp[i+1-plen[pdifflink[v]]-pdiff[v]],pact[v]=plen[pdifflink[v]]+pdiff[v];
			if(pdiff[v]==pdiff[plink[v]]&&pdp[plink[v]]<pdp[v]) pdp[v]=pdp[plink[v]],pact[v]=pact[plink[v]]+pdiff[v];
			if(i%2==1&&pdp[v]!=INT_MAX&&pdp[v]+1<dp[i+1]) dp[i+1]=pdp[v]+1,act[i+1]=pact[v];
			/*
			upd(pdp[v],pact[v],i,pdifflink[v]+pdiff[v]);
			if(pdiff[v]==pdiff[plink[v]]&&pdp[plink[v]]<pdpv[v]) pdp[v]=pdp[plink[v]],pact[v]=*/
			/*for(int u=v;plen[u]>plen[pdifflink[v]];u=plink[u]) {
				printf("i=%d plen=%d (%d)\n",i,plen[u],plen[v]);
				int k=i+1-plen[u]; if(dp[k]!=INT_MAX&&dp[k]+1<dp[i+1]) dp[i+1]=dp[k]+1,act[i+1]=plen[u]/2;
			}*/
		}
	}
	//pprint();

	if(dp[n]==INT_MAX) { printf("-1\n"); return; }
	printf("%d\n",dp[n]);
	for(int i=n;i!=0;i-=act[i]) if(act[i]!=2) printf("%d %d\n",i/2-act[i]/2+1,i/2);


}

int main() {
	run();
	return 0;
}