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
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

void run() {
	int a1,b1,c1; scanf("%d%d%d",&a1,&b1,&c1);
	int a2,b2,c2; scanf("%d%d%d",&a2,&b2,&c2);
	if(a1==0) { swap(a1,a2); swap(b1,b2); swap(c1,c2); }
	if(a1!=0) {
		if(a2!=0) {
			int x=a1,y=-a2;
			a2=x*a2+y*a1,b2=x*b2+y*b1,c2=x*c2+y*c1;
			assert(a2==0);
		}
		printf("%d\n",b2==0&&c2==0?-1:b2==0?0:1);
	} else {
		if(b1==0) { swap(b1,b2); swap(c1,c2); }
		if(b1!=0) {
			if(b2!=0) {
				int x=b1,y=-b2;
				a2=x*a2+y*a1,b2=x*b2+y*b1,c2=x*c2+y*c1;
				assert(b2==0);
			}
			printf("%d\n",c2==0?-1:0);
		} else {
			printf("%d\n",c1==0&&c2==0?-1:0);
		}
	}
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}