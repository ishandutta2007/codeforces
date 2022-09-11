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

const int MOD=1000000007;
const int INV2=(MOD+1)/2;
const int MAXK=5000;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n,k;

vector<int> pol[MAXK+1];
int polval[MAXK+1];
int pwval[MAXK+1];

void run() {
	scanf("%d%d",&n,&k);

	pol[0]=vector<int>(1,1);
	FORE(i,1,k) { pol[i]=pol[i-1]; pol[i].insert(pol[i].begin(),0); REPSZ(j,pol[i-1]) pol[i][j]=(pol[i][j]+MOD-(ll)(i-1)*pol[i-1][j]%MOD)%MOD; }
	polval[0]=pw(2,n); FORE(i,1,k) polval[i]=(ll)polval[i-1]*INV2%MOD*(n-i+1)%MOD;
	REPE(i,k) { pwval[i]=polval[i]; REP(j,SZ(pol[i])-1) pwval[i]=(pwval[i]+MOD-(ll)pol[i][j]*pwval[j]%MOD)%MOD; }
	//REPE(i,k) { printf("pol%d:",i); REPSZ(j,pol[i]) printf(" %d",pol[i][j]); printf(" = %d -> %d\n",polval[i],pwval[i]); }
	printf("%d\n",pwval[k]);
}

int main() {
	run();
	return 0;
}