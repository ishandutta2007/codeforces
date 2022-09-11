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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 200000;

int n, nbit;
int a[MAXN];

int sum[MAXN + 1];

int lst[MAXN + 1], nlst;


ll solve() {
	sum[0] = 0; REP(i, n) sum[i + 1] = sum[i] ^ a[i];

	nlst = 0; REPE(i, n) lst[nlst++] = min(sum[i], (1 << nbit) - sum[i] - 1); sort(lst, lst + nlst);
	//printf("lst:"); REP(i, nlst) printf(" %d", lst[i]); puts("");

	ll ret = (ll)(n + 1)*n / 2;
	for (int l = 0, r = l; l < nlst; l = r) {
		while (r < nlst && lst[l] == lst[r]) ++r;
		int cnt = r - l;
		int n1 = cnt / 2, n2 = cnt - n1;
		ret -= (ll)n1*(n1 - 1) / 2;
		ret -= (ll)n2*(n2 - 1) / 2;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &nbit);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}