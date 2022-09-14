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
#include <random>
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

const int MAXMOD=200000;

int n,MOD;
bool forbidden[MAXMOD];

vector<int> nrs[MAXMOD+1];
vector<int> opt;
vector<int> dp;
vector<int> prv;

// a*x+b*y=g
int egcd(int a,int b,int &x,int &y) {
	if(b==0) { x=1,y=0; return a; }
	int ret=egcd(b,a%b,x,y);
	swap(x,y); y-=(a/b)*x; return ret;
}

int solve(int a,int b) {
	int x,y; int g=egcd(a,MOD,x,y); // x*a=g (mod MOD)
	if(b%g!=0) { printf("err: %d*x=%d (MOD=%d,g=%d)\n",a,b,MOD,g); exit(1); }
	if(x<0) x+=MOD; return (ll)x*(b/g)%MOD;
}

void run() {
	scanf("%d%d",&n,&MOD);
	memset(forbidden,false,sizeof(forbidden)); REP(i,n) { int x; scanf("%d",&x); forbidden[x]=true; }
	REPE(i,MOD) nrs[i].clear(); REP(i,MOD) if(!forbidden[i]) nrs[gcd(i,MOD)].PB(i);
	opt.clear(); REPE(i,MOD) if(SZ(nrs[i])>0) opt.PB(i);
	dp=vector<int>(SZ(opt),0),prv=vector<int>(SZ(opt),-1);
	REPSZ(i,opt) {
		dp[i]+=SZ(nrs[opt[i]]);
		FORSZ(j,i+1,opt) if(opt[j]%opt[i]==0&&dp[i]>dp[j]) dp[j]=dp[i],prv[j]=i;
	}
	vector<int> pref;
	int bst=0; FORSZ(i,1,opt) if(dp[i]>dp[bst]) bst=i;
	for(int at=bst;at!=-1;at=prv[at]) REPSZ(i,nrs[opt[at]]) pref.PB(nrs[opt[at]][i]);
	reverse(pref.begin(),pref.end());
	//printf("pref:"); REPSZ(i,pref) printf(" %d",pref[i]); puts("");
	vector<int> ret(SZ(pref));
	ret[0]=pref[0];
	FORSZ(i,1,ret) ret[i]=solve(pref[i-1],pref[i]);
	printf("%d\n",SZ(ret));
	REPSZ(i,ret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}