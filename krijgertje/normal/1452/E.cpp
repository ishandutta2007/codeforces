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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXPROB = 2000;
const int MAXSTUD = 2000;

int nprob, nstud, tutlen;
int l[MAXSTUD], r[MAXSTUD]; // [l..r)

int solve() {
	int ret = 0;
	REPE(i, nprob - tutlen) {
		int start = 0;
		vector<int> delta(nprob + 1, 0);
		REP(j, nstud) {
			if (r[j] <= i) continue;
			if (l[j] >= i + tutlen) {
				// l[j]-tutlen:0, ..., l[j]:tutlen, ..., r[j]-tutlen:tutlen, ..., r[j]:0
				// l[j]-tutlen:0, ..., r[j]-tutlen:r[j]-l[j], ..., l[j]:r[j]-l[j], ..., r[j]:0
				++delta[l[j] - tutlen];
				--delta[l[j]];
				--delta[r[j] - tutlen];
				++delta[r[j]];
			} else {
				int overlap = min(i + tutlen, r[j]) - max(i, l[j]);
				start += overlap;
				if (l[j] > i && r[j] > i + tutlen) {
					// i:overlap, ..., l[j]:tutlen, ..., r[j]-tutlen:tutlen, ..., ?:overlap
					// i:overlap, ..., r[j]-tutlen:r[j]-l[j], ..., l[j]:overlap, ..., ?:overlap
					++delta[i];
					--delta[l[j]];
					--delta[r[j] - tutlen];
					++delta[r[j] - tutlen + l[j] - i];
				}
			}
		}
		int cur = start, diff = 0;
		FOR(j, i, nprob) {
			cur += diff;
			diff += delta[j];
			//printf("[%d..%d] [%d..%d]: %d\n", i, i + tutlen - 1, j, j + tutlen - 1, cur);
			ret = max(ret, cur);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &nprob, &nstud, &tutlen);
	REP(i, nstud) scanf("%d%d", &l[i], &r[i]), --l[i];
	printf("%d\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}