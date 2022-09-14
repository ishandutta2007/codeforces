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

const int MAXLEN=1000;

char s[MAXLEN+1]; int len;

bool ismirror(char a,char b) {
	if(a==b) return a=='A'||a=='H'||a=='I'||a=='M'||a=='O'||a=='o'||a=='T'||a=='U'||a=='V'||a=='v'||a=='W'||a=='w'||a=='X'||a=='x'||a=='Y';
	if(a>b) swap(a,b);
	return a=='b'&&b=='d'||a=='p'&&b=='q';
}

bool ok() {
	for(int i=0;2*i<len;++i) if(!ismirror(s[i],s[len-i-1])) return false;
	return true;
}

void run() {
	scanf("%s",s); len=strlen(s);
	printf("%s\n",ok()?"TAK":"NIE");
}

int main() {
	run();
	return 0;
}