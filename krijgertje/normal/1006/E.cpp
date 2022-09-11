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

int n,nq;
int par[MAXN];

vector<int> ch[MAXN];
int pre[MAXN],npre;
int l[MAXN],r[MAXN];

void dfspre(int at) {
	l[at]=npre; pre[npre++]=at;
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		dfspre(to);
	}
	r[at]=npre;
}

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];

	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	npre=0; dfspre(0);

	REP(i,nq) {
		int u,off; scanf("%d%d",&u,&off); --u; --off;
		int ans=off>=r[u]-l[u]?-1:pre[l[u]+off]+1;
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}