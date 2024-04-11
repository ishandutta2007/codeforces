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

int bases[4]={33,37,39,41};

int val[300001];

int fenwick[2][(1<<19)+1];

void update(int id,int a) {
	int by=val[a];
	while(a<=(1<<19)) {
		fenwick[id][a]+=by;
		a+=a&-a;
	}
}

int read(int id,int a) {
	int ret=0;
	while(a>0) {
		ret+=fenwick[id][a];
		a-=a&-a;
	}
	return ret;
}

int n;

int get(int id,int a,int b) {
	int ret=read(id,b)-read(id,a-1);
	return ret*val[n-a];
}

int p[300000];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&p[i]);
	REP(x,4) {
		val[0]=1; FORE(i,1,n) val[i]=val[i-1]*bases[x];
		memset(fenwick,0,sizeof(fenwick));
		REP(i,n) {
			// if i is the middle element of a 3term, there is some value x such that only one of i-x and i+x occur before i (with 1<=i-x and i+x<=n)
			// iow, if there is no 3term, [i,i-1,i-2,...,i-cnt] should be the same as [i,i+1,i+2,...,i+cnt]
			int cnt=min(p[i]-1,n-p[i]);
			int inc=get(0,p[i],p[i]+cnt);
			int dec=get(1,n-p[i]+1,n-p[i]+1+cnt);
			if(inc!=dec) {
				printf("YES\n");
				fprintf(stderr,"%d\n",bases[x]);
				return;
			}
			update(0,p[i]);
			update(1,n-p[i]+1);
		}
	}
	printf("NO\n");
}


int main() {
	run();
	return 0;
}