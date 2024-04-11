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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXID=200000;

int nq;

int l,r;
int pos[MAXID+1];

void run() {
	scanf("%d",&nq);
	REP(i,nq) {
		char kind; int id; scanf(" %c%d",&kind,&id);
		if(i==0) assert(kind=='L'||kind=='R');
		if(kind=='L'||kind=='R') {
			if(i==0) {
				l=r=0; pos[id]=0;
			} else if(kind=='L') {
				--l; pos[id]=l;
			} else {
				++r; pos[id]=r;
			}
		}
		if(kind=='?') {
			int ans=min(pos[id]-l,r-pos[id]);
			printf("%d\n",ans);
		}
	}

}

int main() {
	run();
	return 0;
}