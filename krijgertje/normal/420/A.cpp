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

char s[100001]; int n;

bool ismirror(char a,char b) {
	if(a!=b) return false;
	return a=='A'||a=='H'||a=='I'||a=='M'||a=='O'||a=='T'||a=='U'||a=='V'||a=='W'||a=='X'||a=='Y';
}

void run() {
	scanf("%s",s); n=strlen(s);
	bool ok=true;
	REP(i,n) if(!ismirror(s[i],s[n-i-1])) ok=false;
	printf("%s\n",ok?"YES":"NO");
	
}

int main() {
	run();
	return 0;
}