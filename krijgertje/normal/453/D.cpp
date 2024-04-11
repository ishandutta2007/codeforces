#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int m; ll t; int MOD;
int e0[1<<20];
vector<int> b;

int choose[21][21];
int ways[21][21][21];

int sumdist[21][1<<20];
int ret[1<<20];

vector<int> mymult(const vector<int> &a,const vector<int> &b) {
	vector<int> c(m+1,0);
	REPE(x,m) REPE(y,m) REPE(z,m) if(ways[x][y][z]>0) {
		c[z]=(c[z]+(ll)a[x]*b[y]%MOD*ways[x][y][z])%MOD;
	}
	return c;
}

vector<int> mypow(const vector<int> &a,ll n) {
	if(n==0) { vector<int> ret(m+1,0); ret[0]=1; return ret; }
	if(n%2==1) return mymult(mypow(a,n-1),a);
	return mypow(mymult(a,a),n/2);
}

void run() {
	cin>>m>>t>>MOD;
	REP(i,1<<m) scanf("%d",&e0[i]);
	b=vector<int>(m+1); REP(i,m+1) { scanf("%d",&b[i]); b[i]%=MOD; }

	memset(choose,0,sizeof(choose));
	REPE(i,m) { choose[i][0]=choose[i][i]=1%MOD; FOR(j,1,i) choose[i][j]=(choose[i-1][j-1]+choose[i-1][j])%MOD; }
	memset(ways,0,sizeof(ways));
	REPE(xy,m) REPE(xz,m-xy) REPE(yz,m-xy-xz) {
		ways[xy+xz][xy+yz][xz+yz]=(ways[xy+xz][xy+yz][xz+yz]+(ll)choose[xz+yz][xz]*choose[m-xz-yz][xy])%MOD;
	}
//	REPE(x,m) REPE(y,m) REPE(z,m) if(ways[x][y][z]!=0) printf("%d %d %d: %d\n",x,y,z,ways[x][y][z]);

	b=mypow(b,t);
//	REPE(i,m) printf("%d ",b[i]); puts("");

	memset(sumdist,0,sizeof(sumdist));
	REP(i,1<<m) sumdist[0][i]=e0[i]%MOD;
	REP(i,m) for(int j=m-1;j>=0;--j) REP(k,1<<m) if(sumdist[j][k]!=0) {
		int nk=k^(1<<i);
		sumdist[j+1][nk]+=sumdist[j][k];
		if(sumdist[j+1][nk]>=MOD) sumdist[j+1][nk]-=MOD;
	}
//	REP(i,1<<m) { printf("%4x:",i); REPE(j,m) printf(" %d",sumdist[j][i]); puts(""); }

	memset(ret,0,sizeof(ret));
	REP(i,1<<m) REPE(j,m) ret[i]=(ret[i]+(ll)sumdist[j][i]*b[j])%MOD;
	REP(i,1<<m) printf("%d\n",ret[i]);
}


int main() {
	run();
	return 0;
}