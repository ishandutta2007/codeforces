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

const int MAXCOLOR=1000;
const int MAXSUM=1000;
const int MOD=1000000007;

int ncolor;
int cnt[MAXCOLOR];
int choose[MAXSUM+1][MAXSUM+1];

void run() {
	scanf("%d",&ncolor); REP(i,ncolor) scanf("%d",&cnt[i]);

	int sum=0; REP(i,ncolor) sum+=cnt[i];
	REPE(i,sum) { choose[i][0]=choose[i][i]=1; FOR(j,1,i) if((choose[i][j]=choose[i-1][j-1]+choose[i-1][j])>=MOD) choose[i][j]-=MOD; }

	int ret=1;
	for(int i=ncolor-1;i>=0;--i) {
		ret=(ll)ret*choose[sum-1][cnt[i]-1]%MOD;
		sum-=cnt[i];
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}