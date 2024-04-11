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

int n;
int x[100000];
int y[100000];

inline void setmax(int &ref,const int val) { if(val>ref) ref=val; }

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);
	for(int i=n-1;i>=0;--i) y[i]=i+1<n&&x[i+1]>x[i]?y[i+1]:i;

	int ret=0;
	REP(i,n) {
		int a=i,b=y[a];
		setmax(ret,b-a+1);
		if(b+1>=n) continue;
		int c=b+1,d=y[c];
		if(a==b||x[c]-x[b-1]>=2) setmax(ret,d-a+1);
		setmax(ret,c-a+1);
		if(c+1>=n) continue;
		int e=c+1,f=y[e];
		if(x[e]-x[b]>=2) setmax(ret,f-a+1);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}