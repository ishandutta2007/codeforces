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

ll ans[36]={1LL,
2LL,
4LL,
8LL,
16LL,
32LL,
64LL,
128LL,
256LL,
512LL,
1024LL,
2048LL,
4096LL,
8092LL,
16184LL,
32368LL,
64736LL,
129472LL,
258944LL,
517888LL,
1035776LL,
2071552LL,
4143104LL,
8286208LL,
16572416LL,
33144832LL,
66289664LL,
132579328LL,
265158656LL,
530317312LL,
1060634624LL,
2121269248LL,
4242538496LL,
8485076992LL,
16970153984LL,
33940307968LL};

void run() {
	int n; scanf("%d",&n); printf("%I64d\n",ans[n]);
}

int main() {
	run();
	return 0;
}