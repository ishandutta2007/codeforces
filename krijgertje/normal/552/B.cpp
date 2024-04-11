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

const int MAXD=10;

ll p10[MAXD+1];
int d[MAXD],nd;
ll calc(int n) {
	nd=0; for(int x=n;x!=0;x/=10) d[nd++]=x%10;
	ll ret=0;
	FOR(i,1,nd) ret+=9*i*p10[i-1];
	ret+=(n-p10[nd-1]+1)*nd;
	return ret;
}

int n;

void run() {
	p10[0]=1; FORE(i,1,MAXD) p10[i]=p10[i-1]*10;
	scanf("%d",&n);
	cout<<calc(n)<<endl;
}

int main() {
	run();
	return 0;
}