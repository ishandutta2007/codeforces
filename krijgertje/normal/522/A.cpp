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

int nq;
char buff[25];

int n;
char names[400][25];
int d[200];

int getid(char s[25]) {
	REP(i,n) {
		bool ok=true;
		for(int j=0;;++j) {
			if(s[j]=='\0'&&names[i][j]=='\0') break;
			if(tolower(s[j])!=names[i][j]) { ok=false; break; }
		}
		if(ok) return i;
	}
	for(int j=0;;++j) { names[n][j]=tolower(s[j]); if(s[j]=='\0') break; }
	return n++;
}

void run() {
	scanf("%d",&nq);
	int root=getid("Polycarp");
	d[root]=0;
	int ret=0;
	REP(qi,nq) {
		scanf("%s",buff); int a=getid(buff);
		scanf("%s",buff);
		scanf("%s",buff); int b=getid(buff);
		d[a]=d[b]+1;
		if(d[a]>ret) ret=d[a];
	}
	printf("%d\n",ret+1);
}

int main() {
	run();
	return 0;
}