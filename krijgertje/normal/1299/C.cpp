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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 1000000;
struct Block { int cnt; ll sum; Block() {} Block(int cnt, ll sum) :cnt(cnt), sum(sum) {} };

int n;
int a[MAXN];
double ans[MAXN];

vector<Block> blocks;


void solve() {
	blocks.clear();
	for (int i = n - 1; i >= 0; --i) {
		int cnt = 1; ll sum = a[i];
		while (true) {
			if (SZ(blocks) == 0) break;
			Block cur = blocks.back();
			if (sum * cur.cnt < cur.sum * cnt) break;
			blocks.pop_back(); cnt += cur.cnt, sum += cur.sum;
		}
		blocks.PB(Block(cnt, sum));
	}
	//printf("blocks:"); REPSZ(i, blocks) printf(" %lld/%d", blocks[i].sum, blocks[i].cnt); puts("");
	int at = 0;
	while (SZ(blocks) > 0) {
		Block cur = blocks.back(); blocks.pop_back();
		assert(at + cur.cnt <= n);
		REP(i, cur.cnt) ans[at++] = 1.0 * cur.sum / cur.cnt;
	}
	assert(at == n);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) printf("%.15lf\n", ans[i]);
}

int main() {
	run();
	return 0;
}