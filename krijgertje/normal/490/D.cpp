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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int dim[2][2];
int n2[2][2];
int n3[2][2];

void run() {
	REP(i,2) REP(j,2) scanf("%d",&dim[i][j]);
	memset(n2,0,sizeof(n2));
	memset(n3,0,sizeof(n3));
	REP(i,2) REP(j,2) while(dim[i][j]%2==0) { ++n2[i][j]; dim[i][j]/=2; }
	REP(i,2) REP(j,2) while(dim[i][j]%3==0) { ++n3[i][j]; dim[i][j]/=3; }
	ll rem0=(ll)dim[0][0]*dim[0][1],rem1=(ll)dim[1][0]*dim[1][1];
	if(rem0!=rem1) { printf("-1\n"); return; }
	
	int ret=0;
	while(n3[0][0]+n3[0][1]>n3[1][0]+n3[1][1]) {
		++ret; if(n3[0][0]>0) --n3[0][0],++n2[0][0]; else --n3[0][1],++n2[0][1];
	}
	while(n3[0][0]+n3[0][1]<n3[1][0]+n3[1][1]) {
		++ret; if(n3[1][0]>0) --n3[1][0],++n2[1][0]; else --n3[1][1],++n2[1][1];
	}
	while(n2[0][0]+n2[0][1]>n2[1][0]+n2[1][1]) {
		++ret; if(n2[0][0]>0) --n2[0][0]; else --n2[0][1];
	}
	while(n2[0][0]+n2[0][1]<n2[1][0]+n2[1][1]) {
		++ret; if(n2[1][0]>0) --n2[1][0]; else --n2[1][1];
	}
	REP(i,2) REP(j,2) while(n2[i][j]>0) { --n2[i][j]; dim[i][j]*=2; }
	REP(i,2) REP(j,2) while(n3[i][j]>0) { --n3[i][j]; dim[i][j]*=3; }
	printf("%d\n",ret);
	printf("%d %d\n",dim[0][0],dim[0][1]);
	printf("%d %d\n",dim[1][0],dim[1][1]);
}

int main() {
	run();
	return 0;
}