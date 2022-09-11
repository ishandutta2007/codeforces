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

const int MAXN=200000;
const int MAXQ=50000;
const int MAXSUMQLEN=200000;

int n;
char s[MAXN+1];
int nq;
int qoff[MAXQ+1],qlen[MAXQ];
char q[MAXSUMQLEN+1];
int qans[MAXQ];

vector<int> pos[26];

void solve() {
	REP(i,26) pos[i].clear();
	REP(i,n) pos[s[i]-'a'].PB(i);
	REP(i,nq) {
		vector<int> cnt(26,0);
		REP(j,qlen[i]) ++cnt[q[qoff[i]+j]-'a'];
		qans[i]=0; REP(k,26) if(cnt[k]>0) { assert(cnt[k]<=SZ(pos[k])); qans[i]=max(qans[i],pos[k][cnt[k]-1]+1); }
	}
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	scanf("%d",&nq);
	qoff[0]=0; REP(i,nq) { scanf("%s",q+qoff[i]); qlen[i]=strlen(q+qoff[i]); qoff[i+1]=qoff[i]+qlen[i]; }
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}