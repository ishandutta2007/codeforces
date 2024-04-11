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

int n1,n2,x1,x2;

void run() {
	scanf("%d%d%d%d",&n1,&n2,&x1,&x2);
	ll a=n1+n2-1,b=10*a+100; // (a,b]
	while(a+1<b) {
		ll c=a+(b-a)/2;
		bool ok=true;
		if(c-c/x1<n1) ok=false;
		if(c-c/x2<n2) ok=false;
		if(c-c/x1/x2<n1+n2) ok=false;
		if(ok) b=c; else a=c;
	}
	cout<<b<<endl;
}

int main() {
	run();
	return 0;
}