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

//const int MAXN=3;
//const int MAXX=MAXN*(MAXN-1)/2;
//int p[MAXN]; int n;

//pair<int,int> x[MAXX]; int nx;

// 0 1, 0 2, 1 3, 0 3, 1 2, 2 3
// 0 1, 0 2, 0 3, 1 2, 1 4, 2 4, 0 4, 2 3, 1 3, 3 4
// 0 2, 1 3, 0 3, 1 2

const int MAXN=1000;
const int MAXX=MAXN*(MAXN-1)/2;

int n;
int ret[MAXX][2],nret;
pair<int,int> x[MAXX]; int nx;

int p[MAXN];

void run() {
	/*n=6;
	nx=0; REP(i,n) FOR(j,i+1,n) x[nx++]=MP(i,j); printf("nx=%d\n",nx);
	//nx=0; FOR(i,n-4,n) REP(j,i) x[nx++]=MP(j,i); printf("nx=%d\n",nx);
	//nx=0; REP(i,2) FOR(j,2,4) x[nx++]=MP(i,j); printf("nx=%d\n",nx);
	int cnt=0;
	do {
		REP(i,n) p[i]=i;
		//swap(p[0],p[1]); swap(p[2],p[3]);
		REP(i,nx) swap(p[x[i].first],p[x[i].second]);
		bool ok=true; REP(i,n) if(p[i]!=i) ok=false;
		if(ok) {
			REP(i,nx) printf("%d %d\n",x[i].first,x[i].second);
			puts(""); if(++cnt>=10) break;
		}
	} while(next_permutation(x,x+nx));
	return; */

	scanf("%d",&n);
	if(n==1) { printf("YES\n"); return; }
	if(n==2||n==3) { printf("NO\n"); return; }
	int b=n%4+4;
	if(b==6||b==7) { printf("NO\n"); return; }
	printf("YES\n");
	nret=0;
	for(int i=b;i<n;i+=4) {
		REP(j,i) ret[nret][0]=j,ret[nret][1]=i,++nret;
		REP(j,i+1) ret[nret][0]=i-j,ret[nret][1]=i+1,++nret;
		REP(j,i) ret[nret][0]=j,ret[nret][1]=i+2,++nret;
		ret[nret][0]=i+2,ret[nret][1]=i+3,++nret;
		REP(j,i) ret[nret][0]=i-j-1,ret[nret][1]=i+3,++nret;
		ret[nret][0]=i+0,ret[nret][1]=i+2,++nret;
		ret[nret][0]=i+1,ret[nret][1]=i+3,++nret;
		ret[nret][0]=i+0,ret[nret][1]=i+3,++nret;
		ret[nret][0]=i+1,ret[nret][1]=i+2,++nret;
	}
	if(b==4) {
		ret[nret][0]=0,ret[nret][1]=1,++nret;
		ret[nret][0]=0,ret[nret][1]=2,++nret;
		ret[nret][0]=1,ret[nret][1]=3,++nret;
		ret[nret][0]=0,ret[nret][1]=3,++nret;
		ret[nret][0]=1,ret[nret][1]=2,++nret;
		ret[nret][0]=2,ret[nret][1]=3,++nret;
	}
	if(b==5) {
		ret[nret][0]=0,ret[nret][1]=1,++nret;
		ret[nret][0]=0,ret[nret][1]=2,++nret;
		ret[nret][0]=0,ret[nret][1]=3,++nret;
		ret[nret][0]=1,ret[nret][1]=2,++nret;
		ret[nret][0]=1,ret[nret][1]=4,++nret;
		ret[nret][0]=2,ret[nret][1]=4,++nret;
		ret[nret][0]=0,ret[nret][1]=4,++nret;
		ret[nret][0]=2,ret[nret][1]=3,++nret;
		ret[nret][0]=1,ret[nret][1]=3,++nret;
		ret[nret][0]=3,ret[nret][1]=4,++nret;
	}
	REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
	//assert(nret==n*(n-1)/2);

	/*REP(i,n) p[i]=i;
	REP(i,nret) swap(p[ret[i][0]],p[ret[i][1]]);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",p[i]); } puts(""); */
}

int main() {
	run();
	return 0;
}