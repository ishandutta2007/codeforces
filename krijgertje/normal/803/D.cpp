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
#include <random>
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

const int MAXLEN=1000000;

int mxlines;
char s[MAXLEN+1]; int len;

bool can(int mxw) {
	int at=0; int w=0; int lst=-1; int need=1;
	while(at<len) {
		if(w==mxw) {
			if(lst==-1) return false;
			++need; w=at-lst-1; lst=-1;
		}
		++w;
		if(s[at]==' '||s[at]=='-') lst=at;
		++at;
	}
	return need<=mxlines;
}

void run() {
	gets(s); sscanf(s,"%d",&mxlines);
	gets(s); len=strlen(s);
	int l=0,h=len;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(m)) h=m; else l=m;
	}
	printf("%d\n",h);
}

int main() {
	run();
	return 0;
}