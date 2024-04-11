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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n;
int id[100000],by[100000];

int lastid[100001];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&id[i],&by[i]);

	memset(lastid,-1,sizeof(lastid));
	bool ok=true;
	REP(i,n) {
		if(id[i]>lastid[by[i]]+1) ok=false;
		if(id[i]>lastid[by[i]]) lastid[by[i]]=id[i];
	}
	printf("%s\n",ok?"YES":"NO");

}

int main() {
	run();
	return 0;
}