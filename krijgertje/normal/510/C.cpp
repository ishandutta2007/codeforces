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
char name[100][101];

bool e[26][26];
bool done[26];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",name[i]);

	REP(i,26) REP(j,26) e[i][j]=false;
	REP(i,n-1) {
		for(int j=0;true;++j) {
			if(name[i][j]=='\0') break;
			if(name[i+1][j]=='\0') { printf("Impossible\n"); return; }
			if(name[i][j]!=name[i+1][j]) {
				e[name[i][j]-'a'][name[i+1][j]-'a']=true;
				break;
			}
		}
	}
	REP(k,26) REP(i,26) REP(j,26) if(e[i][k]&&e[k][j]) e[i][j]=true;
	//REP(i,26) { REP(j,26) printf("%c",e[i][j]?'V':'.'); puts(""); }
	REP(i,26) if(e[i][i]) { printf("Impossible\n"); return; }

	REP(i,26) done[i]=false;
	REP(i,26) {
		char c='?';
		REP(j,26) if(!done[j]) {
			bool ok=true;
			REP(k,26) if(!done[k]&&e[k][j]) { ok=false; break; }
			if(ok) { c='a'+j; break; }
		}
		assert(c!='?');
		printf("%c",c); done[c-'a']=true;
	}
	puts("");
}

int main() {
	run();
	return 0;
}