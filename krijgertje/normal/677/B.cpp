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

int n,mx,step;
int x[MAXN];

void run() {
	scanf("%d%d%d",&n,&mx,&step); REP(i,n) scanf("%d",&x[i]);
	ll ret=0; int cur=0,at=0;
	while(cur>0||at<n) {
		while(at<n&&cur+x[at]<=mx) cur+=x[at++];
		int dt=at>=n?(cur+step-1)/step:(cur+x[at]-mx+step-1)/step;
		ret+=dt; cur-=dt*step; if(cur<0) cur=0;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}