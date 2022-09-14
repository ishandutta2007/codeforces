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

int n;
int x[4];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	if(n==0) {
		printf("YES\n%d\n%d\n%d\n%d\n",1,1,3,3);
	}
	if(n==1) {
		printf("YES\n%d\n%d\n%d\n",x[0],3*x[0],3*x[0]);
	}
	if(n==2) {
		if((x[0]+x[1])%4==0) { // smaller+larger
			//A=P+x[0]+x[1]+Q,B=2*(x[0]+x[1]),C=4*(Q-P);
			//P+Q=x[0]+x[1], Q=3P, P=(x[0]+x[1])/4
			int P=(x[0]+x[1])/4,Q=3*P;
			if(P<=x[0]&&x[1]<=Q) { printf("YES\n%d\n%d\n",P,Q); return; }
		}
		if(x[1]%3==0) { // smaller
			//A=P+Q+x[0]+x[1],B=2*(Q+x[0]),C=4*(x[1]-P);
			//P+x[1]=Q+x[0], P=x[1]/3, Q=x[1]-x[0]+P
			int P=x[1]/3,Q=x[1]-x[0]+P;
			if(P<=x[0]&&Q<=x[1]) { printf("YES\n%d\n%d\n",P,Q); return; }
		}
		{ // larger
			//A=x[0]+x[1]+P+Q,B=2*(x[1]+P),C=4*(Q-x[0]);
			//x[0]+Q=x[1]+P, Q=3x[0], P=4x[0]-x[1]
			int P=4*x[0]-x[1],Q=3*x[0];
			if(x[0]<=P&&P<=Q&&x[1]<=Q) { printf("YES\n%d\n%d\n",P,Q); return; }
		}
		{ // neither
			//A=x[0]+P+Q+x[1],B=2*(P+Q),C=4*(x[1]-x[0])
			//x[0]+x[1]=P+Q
			int P=x[0],Q=x[1];
			if(4*(x[1]-x[0])==x[0]+P+Q+x[1]) { printf("YES\n%d\n%d\n",P,Q); return; }
		}
		printf("NO\n");
	}
	if(n==3) {
		{ // between
			// A=x[0]+x[1]+Q+x[2],B=2*(x[1]+Q),C=4*(x[2]-x[0])
			int Q=x[0]+x[2]-x[1];
			if(x[0]<=Q&&Q<=x[2]&&4*(x[2]-x[0])==x[0]+x[1]+Q+x[2]) { printf("YES\n%d\n",Q); return; }
		}
		{ // smaller
			// A=Q+x[0]+x[1]+x[2],B=2*(x[0]+x[1]),C=4*(x[2]-Q)
			int Q=x[0]+x[1]-x[2];
			if(Q>=1&&Q<=x[0]&&4*(x[2]-Q)==Q+x[0]+x[1]+x[2]) { printf("YES\n%d\n",Q); return; }
		}
		{ // larger
			// A=x[0]+x[1]+x[2]+Q,B=2*(x[1]+x[2]),C=4*(Q-x[0])
			int Q=x[1]+x[2]-x[0];
			if(Q>=x[2]&&4*(Q-x[0])==x[0]+x[1]+x[2]+Q) { printf("YES\n%d\n",Q); return; }
		}
		printf("NO\n");
	}
	if(n==4) {
		int a=x[0]+x[1]+x[2]+x[3],b=2*(x[1]+x[2]),c=4*(x[3]-x[0]);
		printf("%s\n",a==b&&b==c?"YES":"NO");
	}
}

int main() {
	run();
	return 0;
}