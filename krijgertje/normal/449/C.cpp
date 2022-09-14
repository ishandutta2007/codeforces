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
bool isprime[100001];
bool done[100001];

int nres;
int res[50000][2];

void run() {
	scanf("%d",&n);
	REPE(i,n) isprime[i]=true; isprime[0]=isprime[1]=false;
	FORE(i,2,n) if(isprime[i]) for(int j=i+i;j<=n;j+=i) isprime[j]=false;
	FORE(i,1,n) done[i]=false;

	nres=0;
	for(int i=n;i>=1;--i) if(isprime[i]) {
		int x=-1;
		for(int j=i;j<=n;j+=i) if(j!=i+i&&!done[j]) {
			if(x!=-1) {
				res[nres][0]=x; res[nres][1]=j; ++nres;
				done[x]=done[j]=true; x=-1;
			} else {
				x=j;
			}
		}
		if(x!=-1&&i+i<=n&&!done[i+i]) {
			res[nres][0]=x; res[nres][1]=i+i; ++nres;
			done[x]=done[i+i]=true; x=-1;
		}
	}
	printf("%d\n",nres);
	REP(i,nres) printf("%d %d\n",res[i][0],res[i][1]);
}

int main() {
	run();
	return 0;
}