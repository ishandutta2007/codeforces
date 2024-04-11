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

const int MAXN=200000;
const int MAXM=MAXN-1;

int n,x,y;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

pair<int,int> go(int at,int par) {
	int none=0,one=0,two=0;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		pair<int,int> cur=go(to,at);
		two=min(two+cur.first,one+cur.second);
		one=min(one+cur.first,none+cur.second);
		none+=cur.first;
	}
	//printf("%d -> %d,%d\n",at+1,two+1,one);
	return MP(two+(par==-1?0:1),one);
}

bool isstar() {
	REP(i,n) { int cnt=0; for(int x=ghead[i];x!=-1;x=gnxt[x]) ++cnt; if(cnt!=1&&cnt!=n-1) return false; } return true;
}

void run() {
	scanf("%d%d%d",&n,&x,&y);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	ll ret;
	if(x<y) ret=(ll)x*(n-1)+(ll)(y-x)*go(0,-1).first;
	else if(isstar()) ret=x+(ll)y*(n-2);
	else ret=(ll)y*(n-1);
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}