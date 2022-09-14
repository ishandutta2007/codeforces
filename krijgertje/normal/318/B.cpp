#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
char s[1000001];
bool heavy[1000000];
bool metal[1000000];

void run(int casenr) {
	scanf("%s",s);
	n=strlen(s);
	REP(i,n) heavy[i]=strncmp("heavy",s+i,5)==0;
	REP(i,n) metal[i]=strncmp("metal",s+i,5)==0;

	ll rght=0; REP(i,n) rght+=metal[i]?1:0;
	ll ret=0;
	REP(i,n) if(heavy[i]) ret+=rght; else if(metal[i]) --rght;
	cout<<ret<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}