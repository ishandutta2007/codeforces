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
#include <functional>
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

const int MAXN = 32;

int n, nq;

vector<int> gen(int first) {
	vector<int> lst;
	int next = first;
	while (SZ(lst) < n - 1) {
		vector<int> nlst = lst; nlst.PB(next); for (int x : lst) nlst.PB(x);
		lst = nlst, next *= 4;
	}
	while (SZ(lst) > n - 1) lst.pop_back();
	return lst;
}

int rt[MAXN][MAXN - 1];
int dn[MAXN - 1][MAXN];

int val[MAXN][MAXN];
map<int, pair<int, int>> pos;

void gen() {
	vector<int> hor = gen(1);
	assert(SZ(hor) == n - 1);
	REP(i, n) REPSZ(j, hor) rt[i][j] = hor[j];
	vector<int> vert = gen(2);
	assert(SZ(vert) == n - 1);
	REPSZ(i, vert) REP(j, n) dn[i][j] = vert[i];
	int sum = 0;
	REP(i, n) REP(j, n - 1) sum += rt[i][j];
	REP(i, n - 1) REP(j, n) sum += dn[i][j];
	//printf("sum=%d\n", sum);
	val[0][0] = 0;
	FOR(i, 1, n) val[i][0] = val[i - 1][0] ^ dn[i - 1][0];
	REP(i, n) FOR(j, 1, n) val[i][j] = val[i][j - 1] ^ rt[i][j - 1];
	set<int> have;
	pos.clear();
	REP(i, n) REP(j, n) { assert(have.count(val[i][j]) == 0); have.insert(val[i][j]); pos[val[i][j]] = MP(i, j); }
}


void run() {
	scanf("%d%d", &n, &nq);
	gen();
	REP(i, n) { REP(j, n - 1) { if (j != 0) printf(" "); printf("%d", rt[i][j]); } puts(""); }
	REP(i, n - 1) { REP(j, n) { if (j != 0) printf(" "); printf("%d", dn[i][j]); } puts(""); }
	fflush(stdout);
	int x = 0, y = 0;
	REP(i, nq) {
		int input; scanf("%d", &input);
		int search = val[x][y] ^ input;
		//printf("search=%d\n", search);
		assert(pos.count(search));
		int nx, ny; tie(nx, ny) = pos[search];
		printf("%d %d\n", nx + 1, ny + 1); fflush(stdout);
		x = nx, y = ny;
	}

}

void research() {
	n = 32;
	FORE(first, 1, 2) {
		vector<int> lst = gen(first);
		int sum = 0; for (int x : lst) sum += x;
		sum *= n;
		printf("first=%d sum=%d\n", first, sum);
	}
}

int main() {
	//research();
	run();
	return 0;
}