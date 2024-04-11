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
const int MAXVAL=1000000000;

int n,k;
int x[MAXN];
ll xs[MAXN+1];

void run() {
	scanf("%d%d",&n,&k); REP(i,n) scanf("%d",&x[i]);
	//n=MAXN; k=2; REP(i,n) x[i]=i==0?1:0;
	xs[0]=0; REP(i,n) xs[i+1]=xs[i]+x[i];
	ll mx=(ll)n*MAXVAL;
	vector<ll> want;
	{
		ll cur=1; 
		for(int p=0;abs(cur)<=mx;++p,cur*=k) {
			if(k==1&&p>=1||k==-1&&p>=2) break;
			//printf("%d -> %lld\n",p,cur);
			want.PB(cur);
		}
	}
	map<ll,int> have;
	ll ret=0;
	REP(i,n) {
		have[xs[i]]++;
		REPSZ(j,want) ret+=have[xs[i+1]-want[j]];
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}