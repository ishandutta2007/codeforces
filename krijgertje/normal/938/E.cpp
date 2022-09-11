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

const int MAXN=1000000;
const int MOD=1000000007;

int n;
int a[MAXN];

int inv[MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	//printf("inv:"); FORE(i,1,n) printf(" %d",inv[i]); puts("");
	int nfac=1; FORE(i,1,n) nfac=(ll)nfac*i%MOD;

	int ret=0;
	sort(a,a+n);
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		int small=l,eq=r-l,large=n-r;
		if(large==0) continue;
		int cur=(1+MOD-(ll)large*inv[eq+large]%MOD)*nfac%MOD*a[l]%MOD;
		if((ret+=cur)>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}