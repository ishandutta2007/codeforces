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

int a,b;
const int MOD=1000000007;

void run() {
	scanf("%d%d",&a,&b);
	ll ret=0;
	FOR(den,1,b) {
		// x=?*b+den, ?=den,2*den,...,a*den
		ll sum=(ll)(1+a)*a/2%MOD;
		ll cur=sum*den%MOD*b+(ll)den*a;
		//printf("%d: sum=%lld, cur=%lld\n",den,sum,cur);
		ret=(ret+cur)%MOD;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}