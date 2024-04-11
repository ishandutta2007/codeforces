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

int ncol,rad;

void run(int casenr) {
	scanf("%d%d",&ncol,&rad);
	double diag=sqrt(2.0*rad*rad);

	double sum=0;
	REP(i,ncol) {
		//bottom
		sum+=rad;
		sum+=(ncol-1)*(rad+diag);
		//top
		sum+=rad;
		if(i-1>=0) sum+=rad;
		if(i+1<ncol) sum+=rad;
		if(i-1>=1) sum+=1.0*(i-1)*(rad+diag)+1.0*(i-1)*(i-2)*rad;
		if(ncol-i-2>=1) sum+=1.0*(ncol-i-2)*(rad+diag)+1.0*(ncol-i-2)*(ncol-i-3)*rad;
	}
	double ret=sum/ncol/ncol;
	printf("%.9lf\n",ret);
}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}