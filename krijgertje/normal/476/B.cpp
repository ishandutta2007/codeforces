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
char orig[11];
char got[11];
int choose[11][11];

void run() {
	REPE(i,10) { choose[i][0]=choose[i][i]=1; FOR(j,1,i) choose[i][j]=choose[i-1][j-1]+choose[i-1][j]; }
	scanf("%s%s",orig,got); n=strlen(orig); assert(strlen(got)==n);
	int want=0; REP(i,n) if(orig[i]=='-') --want; else if(orig[i]=='+') ++want;
	int have=0,ntoss=0; REP(i,n) if(got[i]=='-') --have; else if(got[i]=='+') ++have; else if(got[i]=='?') ++ntoss;
	int diff=abs(want-have);
	// ntoss-diff=2a
	printf("%.9lf\n",diff>ntoss||(ntoss-diff)%2!=0?0:1.0*choose[ntoss][(ntoss-diff)/2]/(1<<ntoss));
}

int main() {
	run();
	return 0;
}