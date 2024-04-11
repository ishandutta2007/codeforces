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

const int MAXPROPS=100000;
const int MAXN=12;
const int MAXQ=100000;
const int MAXNN=MAXN+MAXQ;

int nprop,n,nq;
int prop[MAXN][MAXPROPS];
int qkind[MAXQ],qx[MAXQ],qy[MAXQ];

int a[MAXNN],b[MAXNN],c[MAXNN],nn;
char res[MAXNN][1<<MAXN];

pair<int,int> o[MAXN];

void run() {
	scanf("%d%d%d",&nprop,&n,&nq);
	REP(i,n) REP(j,nprop) scanf("%d",&prop[i][j]);
	REP(i,nq) scanf("%d%d%d",&qkind[i],&qx[i],&qy[i]),--qx[i],--qy[i];

	nn=n; REP(i,nn) a[i]=b[i]=-1; REP(i,nq) if(qkind[i]!=3) a[nn]=qx[i],b[nn]=qy[i],c[nn]=qkind[i],++nn;
	REP(i,n) REP(mask,1<<n) res[i][mask]=mask&(1<<i)?1:0;
	FOR(i,n,nn) REP(mask,1<<n) if(c[i]==1) res[i][mask]=max(res[a[i]][mask],res[b[i]][mask]); else res[i][mask]=min(res[a[i]][mask],res[b[i]][mask]);

	REP(i,nq) if(qkind[i]==3) {
		REP(j,n) o[j]=MP(prop[j][qy[i]],j); sort(o,o+n); reverse(o,o+n);
		int mask=0,cnt=0; while(cnt<n&&res[qx[i]][mask]==0) mask|=1<<o[cnt++].second; assert(res[qx[i]][mask]==1);
		printf("%d\n",o[cnt-1].first);
	}
}

int main() {
	run();
	return 0;
}