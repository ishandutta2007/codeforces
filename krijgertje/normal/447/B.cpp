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

int slen,nadd;
char s[1001];
int val[26];

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%d",&nadd);
	REP(i,26) scanf("%d",&val[i]);
	int maxval=val[0]; FOR(i,1,26) if(val[i]>maxval) maxval=val[i];
	ll ret=0;
	REP(i,slen) ret+=(ll)(i+1)*val[s[i]-'a'];
	REP(i,nadd) ret+=(ll)(slen+i+1)*maxval;
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}