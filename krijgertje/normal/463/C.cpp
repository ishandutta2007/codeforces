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

int n;
int a[2000][2000];

ll diag[2][3999]; //x+y,x-y+n-1

void run() {
	scanf("%d",&n);
	REP(x,n) REP(y,n) scanf("%d",&a[x][y]);

	REP(i,2*n+1) diag[0][i]=diag[1][i]=0;
	REP(x,n) REP(y,n) {
		int d0=x+y,d1=x-y+n-1;
		diag[0][d0]+=a[x][y]; diag[1][d1]+=a[x][y];
	}

	int rx[2],ry[2]; ll rval[2]; rx[0]=rx[1]=ry[0]=ry[1]=rval[0]=rval[1]=-1;
	REP(x,n) REP(y,n) {
		int i=(x+y)%2,d0=x+y,d1=x-y+n-1;
		ll cur=diag[0][d0]+diag[1][d1]-a[x][y];
		if(cur>rval[i]) rval[i]=cur,rx[i]=x,ry[i]=y;
	}
	cout<<rval[0]+rval[1]<<endl;
	printf("%d %d %d %d\n",rx[0]+1,ry[0]+1,rx[1]+1,ry[1]+1);
}

int main() {
	run();
	return 0;
}