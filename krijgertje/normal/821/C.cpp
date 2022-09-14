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

const int MAXN=300000;

int n;
char s[100];

set<int> sorted;
int stck[MAXN]; int nstck;

void run() {
	scanf("%d",&n);
	sorted.clear(); nstck=0; int ret=0;
	int nxt=1;
	REP(i,2*n) {
		scanf("%s",s);
		if(strcmp(s,"add")==0) {
			int x; scanf("%d",&x); stck[nstck++]=x;
		} else if(strcmp(s,"remove")==0) {
			if(nstck>0&&stck[nstck-1]==nxt) {
				--nstck;
				++nxt;
			} else {
				if(nstck>0) {
					++ret;
					REP(j,nstck) sorted.insert(stck[j]); nstck=0;
				}
				//printf("sorted:"); for(auto it=sorted.begin();it!=sorted.end();++it) printf(" %d",*it); printf(" (want=%d)\n",nxt);
				assert(sorted.count(nxt));
				sorted.erase(nxt);
				++nxt;
			}
		} else assert(false);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}