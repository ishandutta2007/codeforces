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

const int MAXN=100;

int n;
int a[MAXN];

map<int,int> have;

map<int,int> mem;
int calc(int mask) {
	if(mask==1) return 0;
	if(mem.count(mask)) return mem[mask];
	int opt=0;
	for(int i=1;(1<<i)<=mask;++i) {
		int nmask=(mask&((1<<i)-1))|(mask>>i);
		int cur=calc(nmask); opt|=1<<cur;
	}
	int ret=0; while((opt>>ret)&1) ++ret;
	//for(int i=1;(1<<i)<=mask;++i) printf("%d",(mask>>i)&1); printf(" -> "); for(int i=0;(1<<i)<=opt;++i) printf("%d",(opt>>i)&1); printf(" -> %d\n",ret);
	return mem[mask]=ret;
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	have.clear();
	REP(i,n) { int rem=a[i]; for(int j=2;j*j<=rem;++j) if(rem%j==0) { int cnt=0; while(rem%j==0) rem/=j,++cnt; have[j]|=1<<cnt; } if(rem!=1) have[rem]|=1<<1; }
	//for(auto it=have.begin();it!=have.end();++it) { printf("%d:",it->first); for(int i=0;(1<<i)<=it->second;++i) if((it->second>>i)&1) printf(" %d",i); puts(""); }

	int res=0; mem.clear();
	for(auto it=have.begin();it!=have.end();++it) res^=calc(it->second|1);
	printf("%s\n",res==0?"Arpa":"Mojtaba");
}

int main() {
	run();
	return 0;
}