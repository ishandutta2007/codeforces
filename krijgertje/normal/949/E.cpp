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
const int MAXK=20;

int n;
int a[MAXN];

int b[MAXK+1][MAXN],nb[MAXK+1];
int cur[MAXK+1],ncur;
int ret[MAXK+1],nret;

void normalize(int k) {
	int ocnt=nb[k]; nb[k]=0; REP(i,ocnt) if(b[k][i]!=0&&(nb[k]==0||b[k][i]!=b[k][nb[k]-1])) b[k][nb[k]++]=b[k][i];
}

void rec(int k) {
	//printf("rec(%d) -> %d:",k,nb[k]); REP(i,nb[k]) printf(" %d",b[k][i]); puts("");
	if(nb[k]==0) {
		//printf("cur:"); REP(i,ncur) printf(" %d",cur[i]); puts("");
		if(nret==-1||ncur<nret) { nret=ncur; REP(i,ncur) ret[i]=cur[i]; }
		return;
	}
	if(nb[k]==1&&(b[k][0]==-1||b[k][0]==+1)) {
		cur[ncur++]=b[k][0]*(1<<k);
		nb[k+1]=0; rec(k+1);
		--ncur;
		return;
	}
	bool anyodd=false; REP(i,nb[k]) if(b[k][i]%2!=0) anyodd=true;
	if(!anyodd) {
		nb[k+1]=0; REP(i,nb[k]) b[k+1][nb[k+1]++]=b[k][i]/2;
		rec(k+1);
	} else {
		for(int mn=-1;mn<=+1;mn+=2) {
			cur[ncur++]=mn*(1<<k);
			nb[k+1]=0; REP(i,nb[k]) b[k+1][nb[k+1]++]=b[k][i]%2==0?b[k][i]/2:(b[k][i]-mn)/2;
			normalize(k+1);
			rec(k+1);
			--ncur;
		}
	}
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	nb[0]=n; REP(i,n) b[0][i]=a[i]; sort(b[0],b[0]+n); normalize(0);
	nret=-1; rec(0);
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}