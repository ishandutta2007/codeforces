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
const int MAXK=1000;
const int MAXT=100;
const int MAXVAL=100;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int sa,sb,k,t;

int ways[2][MAXT*MAXK*2+1];

int sum[MAXT*MAXK*2+1];

void run() {
	scanf("%d%d%d%d",&sa,&sb,&k,&t);
	int at=0; memset(ways[at],0,sizeof(ways[at]));
	int off=t*k;
	ways[at][off]=1;
	REP(i,t) {
		memset(ways[1-at],0,sizeof(ways[1-at]));
		int cur=0; inc(cur,ways[at][off-i*k]);
		for(int j=off-(i+1)*k;j<=off+(i+1)*k;++j) {
			inc(ways[1-at][j],cur);
			if(j-k>=off-i*k) inc(cur,MOD-ways[at][j-k]);
			if(j+1+k<=off+i*k) inc(cur,ways[at][j+1+k]);
			//FORE(dj,-k,+k) if(off-i*k<=j-dj&&j-dj<=off+i*k) inc(ways[1-at][j],ways[at][j-dj]);
		}
		at=1-at;
	}
	sum[off-t*k]=ways[at][off-t*k]; FOR(j,off-t*k,off+t*k) sum[j+1]=sum[j],inc(sum[j+1],ways[at][j+1]);
	int ret=0; FORE(da,off-t*k,off+t*k) { int maxdb=min(sa-sb+da-1,off+t*k); if(maxdb>=off-t*k) inc(ret,(ll)ways[at][da]*sum[maxdb]%MOD); }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}