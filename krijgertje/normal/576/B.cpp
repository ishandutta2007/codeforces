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

const int MAXN=100000;

int n;
int p[MAXN];
bool done[MAXN];

int ret[MAXN-1][2],nret;

void star(int a) {
	printf("YES\n");
	REP(i,n) if(i!=a) printf("%d %d\n",a+1,i+1);
}

void bridge(int a,int b) {
	REP(i,n) done[i]=false;
	nret=0; ret[nret][0]=a,ret[nret][1]=b,++nret; done[a]=done[b]=true;
	REP(i,n) if(!done[i]) {
		int x=i;
		while(!done[x]) {
			if(done[p[x]]) { printf("NO\n"); return; }
			ret[nret][0]=a,ret[nret][1]=x,++nret;
			ret[nret][0]=b,ret[nret][1]=p[x],++nret;
			done[x]=done[p[x]]=true; x=p[p[x]];
		}
	}
	printf("YES\n");
	REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
}



void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&p[i]),--p[i];

	REP(i,n) if(p[i]==i) { star(i); return; }
	REP(i,n) if(p[p[i]]==i) { bridge(i,p[i]); return; }
	printf("NO\n");
}

int main() {
	run();
	return 0;
}