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

const int MAXN=100;
const int MAXVAL=100;
const int MAXSUM=MAXN*MAXVAL;

int n,a[MAXN],b[MAXN],asum,bsum;
int mncnt[MAXSUM+1];
int mxa[MAXSUM+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]);
	asum=bsum=0; REP(i,n) asum+=a[i],bsum+=b[i];
	REPE(i,bsum) mncnt[i]=INT_MAX; mncnt[0]=0; mxa[0]=0;
	REP(i,n) for(int j=bsum;j>=b[i];--j) if(mncnt[j-b[i]]!=INT_MAX&&(mncnt[j-b[i]]+1<mncnt[j]||mncnt[j-b[i]]+1==mncnt[j]&&mxa[j-b[i]]+a[i]>mxa[j])) mncnt[j]=mncnt[j-b[i]]+1,mxa[j]=mxa[j-b[i]]+a[i];
	//REPE(j,bsum) if(mncnt[j]!=INT_MAX) printf("%d: %d %d\n",j,mncnt[j],mxa[j]);
	int retcnt=INT_MAX,reta=0; FORE(j,asum,bsum) if(mncnt[j]!=INT_MAX&&(mncnt[j]<retcnt||mncnt[j]==retcnt&&mxa[j]>reta)) retcnt=mncnt[j],reta=mxa[j];
	printf("%d %d\n",retcnt,asum-reta);
}

int main() {
	run();
	return 0;
}