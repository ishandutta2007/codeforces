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

int n,nq;
int a[100000],extra;

void run(int casenr) {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]); extra=0;
	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int pos,val; scanf("%d%d",&pos,&val); --pos;
			a[pos]=val-extra;
		} else if(type==2) {
			int val; scanf("%d",&val); extra+=val;
		} else if(type==3) {
			int pos; scanf("%d",&pos); --pos;
			printf("%d\n",a[pos]+extra);
		}
	}
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}