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

void run() {
	int n; scanf("%d",&n);
	int l=-2000000000,h=2000000000;
	REP(i,n) {
		char op[3]; int val; char ans; scanf(" %s%d %c",op,&val,&ans);
		if(ans=='N') {
			op[0]=op[0]=='<'?'>':'<';
			op[1]=op[1]=='='?'\0':'=';
			op[2]='\0';
		}
		if(op[0]=='<') {
			if(op[1]!='=') --val;
			h=min(h,val);
//			printf("\t -> <= %d\n",val);
		}
		if(op[0]=='>') {
			if(op[1]!='=') ++val;
			l=max(l,val);
//			printf("\t -> >= %d\n",val);
		}
	}
	if(l<=h) printf("%d\n",l);
	else printf("Impossible\n");
}

int main() {
	run();
	return 0;
}