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

char s[101]; int slen;

bool ok() {
	for(int i=1;4*i<slen;++i) for(int j=0;j+4*i<slen&&j<i;++j) {
		int k=j,cnt=0;
		while(k<slen) {
			if(s[k]=='*') ++cnt; else cnt=0;
			if(cnt>=5) return true;
			k+=i;
		}
	}
	return false;
}

void run() {
	scanf("%d%s",&slen,s);
	printf("%s\n",ok()?"yes":"no");
}

int main() {
	run();
	return 0;
}