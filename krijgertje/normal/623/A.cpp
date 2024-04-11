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

const int MAXN=500;
const int MAXM=MAXN*(MAXN-1)/2;

int n,m;
bool adj[MAXN][MAXN];

char ret[MAXN+1];
bool test() {
	ret[n]='\0';
	REP(a,n) REP(c,n) if(!adj[a][c]) {
		ret[a]='a'; ret[c]='c';
		REP(i,n) if(i!=a&&i!=c) if(adj[i][a]&&adj[i][c]) ret[i]='b'; else if(adj[i][a]) ret[i]='a'; else if(adj[i][c]) ret[i]='c'; else return false;
		REP(i,n) REP(j,n) if(adj[i][j]!=!(ret[i]=='a'&&ret[j]=='c'||ret[i]=='c'&&ret[j]=='a')) return false;
		return true;
	}
	REP(i,n) ret[i]='a'; return true;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,n) adj[i][j]=i==j;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a][b]=adj[b][a]=true; }
	if(test()) printf("Yes\n%s\n",ret); else printf("No\n");
}

int main() {
	run();
	return 0;
}