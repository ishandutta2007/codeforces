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

int A,B,nq;
int offset,times,each;

bool ok(int cnt) {
	if(A+(ll)B*(offset+cnt-1)>times) return false;
//	if(sum(A+B*offset,A+B*(offset+1),...,A+B*(offset+cnt-1))>times*each) return false;
	if((ll)A*cnt+(ll)B*(offset+offset+cnt-1)*cnt/2>(ll)times*each) return false;
	return true;
}

void run() {
	scanf("%d%d%d",&A,&B,&nq);
	REP(qi,nq) {
		scanf("%d%d%d",&offset,&times,&each); --offset;
		int l=0,r=1;
		while(ok(r)) l=r,r*=2;
		while(l+1<r) {
			int m=l+(r-l)/2;
			if(ok(m)) l=m; else r=m;
		}
		printf("%d\n",l==0?-1:offset+l);
	}
}

int main() {
	run();
	return 0;
}