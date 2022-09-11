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

const int MAXP = 1000; // MINP=5
const int MAXT = 1000; // MINT=7

int np, nt;
int pos[MAXT][MAXP];
int anst, anspos;

ll sumpos[MAXT];
ll sumsq[MAXT];
bool tok[MAXT];

void solve() {
	REP(i, nt) { sumpos[i] = 0; REP(j, np) sumpos[i] += pos[i][j]; }
	REP(i, nt) { sumsq[i] = 0; REP(j, np) sumsq[i] += (ll)pos[i][j] * pos[i][j]; }
	map<ll, int> diffcnt; REP(i, nt - 1) diffcnt[sumpos[i + 1] - sumpos[i]]++;
	ll sumv = -1; int mxdiffcnt = -1; for (auto z : diffcnt) if (z.second > mxdiffcnt) mxdiffcnt = z.second, sumv = z.first;
	//printf("sumv=%lld\n", sumv);
	
	REP(i, nt) tok[i] = false;
	REP(i, nt - 1) if (sumpos[i + 1] - sumpos[i] == sumv) tok[i] = tok[i + 1] = true;
	//printf("tok: "); REP(i, nt) printf("%c", tok[i] ? 'V' : 'x'); puts("");

	int st = 0;
	while (st <= nt - 3 && (!tok[st] || !tok[st + 1] || !tok[st + 2])) ++st;
	assert(st <= nt - 3);
	ll a = sumsq[st], b = sumsq[st + 1], c = sumsq[st + 2];
	// a=sum((xj+st*vj)^2)=sum(xj^2+2*st*xj*vj+st^2*vj^2)
	// b=sum((xj+(st+1)*vj)^2)=sum(xj^2+2*(st+1)*xj*vj+(st+1)^2*vj^2)
	// c=sum((xj+(st+2)*vj)^2)=sum(xj^2+2*(st+2)*xj*vj+(st+2)^2*vj^2)
	// b-a=sum(2*xj*vj+(2*st+1)*vj^2)
	// c-b=sum(2*xj*vj+(2*st+3)*vj^2)
	// (c-b)-(b-a)=sum(2*vj^2)
	ll sumvv = (c - b) - (b - a); assert(sumvv % 2 == 0); sumvv /= 2;
	//printf("sumvv=%lld\n", sumvv);
	// b-a-(2*st+1)*sumvv=sum(2*xj*vj)
	ll sumxv = (b - a) - (2 * st + 1) * sumvv; assert(sumxv % 2 == 0); sumxv /= 2;
	//printf("sumxv=%lld\n", sumxv);
	// sumpos[st]=sum(xj+st*vj)
	ll sumx = sumpos[st] - st * sumv;
	//printf("sumx=%lld\n", sumx);
	ll sumxx = a - 2 * st * sumxv - (ll)st * st * sumvv;
	//printf("sumxx=%lld\n", sumxx);
	REP(i, nt) if (sumpos[i] != sumx + i * sumv) {
		ll delta = sumpos[i] - (sumx + i * sumv);
		assert(delta != 0);
		anst = i;
		//printf("delta=%lld\n", delta);
		//sum((xj + i * vj) ^ 2)-(xk+i*vk)^2+(xk+i*vk+delta)^2=sumxx+2*i*sumxv+i*i*sumvv+delta*delta+2*delta*(xk+i*vk)
		ll ans = sumsq[i] - sumxx - 2 * i * sumxv - (ll)i * i * sumvv - delta * delta; assert(ans % (2 * delta) == 0); ans /= 2 * delta;
		anspos = ans;
		return;
	}
	assert(false);
}

void run() {
	scanf("%d%d", &np, &nt);
	REP(i, nt) REP(j, np) scanf("%d", &pos[i][j]);
	solve();
	printf("%d %d\n", anst, anspos);
}

int main() {
	run();
	return 0;
}