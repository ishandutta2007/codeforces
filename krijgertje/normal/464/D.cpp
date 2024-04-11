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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXZ=1000;

// E(n,z)=1/k*(1/(z+1)*sum(i=1..z+1,min(i,z)+E(n-1,max(i,z))))+(k-1)/k*E(n-1,z)
// E(n,z)=1/k/(z+1)*(z*(z+1)/2+z*E(n-1,z)+z+E(n-1,z+1))+(k-1)/k*E(n-1,z)
// E(n,z)=1/k/(z+1)*(z*(z+1)/2+z+E(n-1,z+1)-E(n-1,z))+E(n-1,z)

int nwin,ntype;

double E[2][MAXN+1];

void run() {
	scanf("%d%d",&nwin,&ntype);

	int at=0;
	E[at][0]=0; FORE(i,1,nwin) E[at][i]=1.0*(MAXZ*(MAXZ+1)/2+MAXZ)/ntype/(MAXZ+1)+E[at][i-1];
	for(int z=MAXZ-1;z>=1;--z) {
		at=1-at;
		E[at][0]=0; FORE(i,1,nwin) E[at][i]=1.0*(z*(z+1)/2+z+E[1-at][i-1]-E[at][i-1])/ntype/(z+1)+E[at][i-1];
	}
	printf("%.9lf\n",ntype*E[at][nwin]);
}

int main() {
	run();
	return 0;
}