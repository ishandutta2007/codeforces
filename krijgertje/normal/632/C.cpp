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

const int MAXN=50000;
const int MAXLEN=50000;

int n;
char s[MAXLEN+1];
int off[MAXN+1];
int p[MAXN];

bool cmp(const int &a,const int &b) {
	int asz=off[a+1]-off[a],bsz=off[b+1]-off[b];
	REP(i,asz+bsz) {
		char ca=i<asz?s[off[a]+i]:s[off[b]+i-asz];
		char cb=i<bsz?s[off[b]+i]:s[off[a]+i-bsz];
		if(ca!=cb) return ca<cb;
	}
	return false;
}


void run() {
	scanf("%d",&n);
	off[0]=0; REP(i,n) { scanf("%s",s+off[i]); off[i+1]=off[i]+strlen(s+off[i]); }
	REP(i,n) p[i]=i; sort(p,p+n,cmp);
	REP(i,n) FOR(j,off[p[i]],off[p[i]+1]) printf("%c",s[j]); puts("");
}

int main() {
	run();
	return 0;
}