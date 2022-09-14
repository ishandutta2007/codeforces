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

const int MAXN=500000;
const int MOD=1000000007;
const int MAXVAL=10000000;
const int MAXP=8;

void inc(int &a,const int &b) { if((a+=b)>=MOD) a-=MOD; }
void sub(int &a,const int &b) { if((a-=b)<0) a+=MOD; }

int n;
int a[MAXN];
int p[MAXN][MAXP]; int np[MAXN];

int p2[MAXN+1];
int mu[MAXVAL+1];
int cnt[MAXVAL+1];


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);

	


	memset(cnt,0,sizeof(cnt));
	memset(mu,0,sizeof(mu));
	REP(i,n) {
		np[i]=0;
		int x=a[i];
		for(int j=2;j*j<=x;++j) if(x%j==0) { p[i][np[i]++]=j; while(x%j==0) x/=j; }
		if(x!=1) p[i][np[i]++]=x;
		REP(j,1<<np[i]) { int cur=1,cmu=+1; REP(k,np[i]) if(j&(1<<k)) cur*=p[i][k],cmu=-cmu; ++cnt[cur]; mu[cur]=cmu; }
	}
	//REP(i,n) { printf("%d:",a[i]); REP(j,np[i]) printf(" %d",p[i][j]); puts(""); }

	// ways to choose J such that gcd(J)!=1 -> p2[cnt[2]]+p2[cnt[3]]-p2[cnt[6]]...
	p2[0]=1; REP(i,n) { p2[i+1]=p2[i]; inc(p2[i+1],p2[i]); }
	REPE(i,n) sub(p2[i],1);
	int all=0; FORE(j,2,MAXVAL) if(cnt[j]!=0&&mu[j]!=0) if(mu[j]<0) inc(all,p2[cnt[j]]); else sub(all,p2[cnt[j]]);
	//printf("all: %d\n",all);

	// ways to choose i, J such that gcd(J)!=1 && gcd(i,gcd(J))==1
	// -> sum(#(choose J such that gcd(J)!=1 && gcd(i,gcd(J)) is a multiple of d)*mu(d))
	// -> sum(#(choose J such that gcd(J)!=1 && i is a multiple of d and gcd(J) is a multiple of d)*mu(d))
	// -> #(choose J such that gcd(J)!=1)+sum(#(choose J such that i is a multiple of d and gcd(J) is a multiple of d)*mu(d),d>1)
	int ret=0;
	REP(i,n) {
		int now=all;
		FOR(j,1,1<<np[i]) {
			int cur=1; REP(k,np[i]) if(j&(1<<k)) cur*=p[i][k];
			if(mu[cur]<0) sub(now,p2[cnt[cur]]); else inc(now,p2[cnt[cur]]);
		}
		//printf("diff from %d: %d\n",a[i],now);
		inc(ret,now);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}