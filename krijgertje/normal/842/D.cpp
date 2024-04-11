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

const int MAXBIT=18;

int n,nq;

int cnt[2<<MAXBIT];
int sum[(2<<MAXBIT)+1];


void run() {
	scanf("%d%d",&n,&nq);
	memset(cnt,0,sizeof(cnt)); REP(i,n) { int x; scanf("%d",&x); cnt[x]=1; }
	sum[0]=0; REP(i,2<<MAXBIT) sum[i+1]=sum[i]+cnt[i];

	int tot=0;
	REP(i,nq) {
		int q; scanf("%d",&q); tot^=q;
		int off=0;
		for(int k=MAXBIT;k>=0;--k) {
			int bit=(tot>>k)&1,cur=sum[off+((bit+1)<<k)]-sum[off+(bit<<k)];
			if(cur!=(1<<k)) off+=bit<<k; else off+=(1-bit)<<k;
		}
		printf("%d\n",tot^off);
	}
}

int main() {
	run();
	return 0;
}