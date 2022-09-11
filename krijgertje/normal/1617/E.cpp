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

const int MAXN = 200000;

int n;
int a[MAXN];
int ansx, ansy, anscost;

int calczerocost(int v, bool canpoweroftwo = true, int use = 1) {
	if (v == 0) return 0;
	int ret = 0;
	if (use == 1) while (v % 2 == 0) v /= 2;
	for (int l = 0, r = l; (1LL << l) <= v; l = r) {
		while ((1LL << r) <= v && ((v >> r) & 1) == ((v >> l) & 1)) ++r;
		if (((v >> l) & 1) == use) ret += l == 0 && r - l == 1 && canpoweroftwo ? 1 : 2;
	}
	return ret;
}

void anytwo(const vector<int> &lst) {
	if (SZ(lst) >= 2) {
		int a = lst[0], b = lst[1];
		if (0 > anscost) ansx = a, ansy = b, anscost = 0;
	}
}

void receven(const vector<int> &lst, int shift) {
	if (SZ(lst) < 2) return;
	bool allzero = true;
	vector<int> zero, one;
	int bestzero = -1, bestzerocost = -1, bestone = -1, bestonecost = -1;
	for (int idx : lst) {
		int v = a[idx] >> shift;
		int cost = calczerocost(v, false);
		if (v != 0) allzero = false;
		if ((v & 1) == 0) {
			zero.PB(idx);
			if (cost > bestzerocost) bestzero = idx, bestzerocost = cost;
		} else {
			one.PB(idx);
			if (cost > bestonecost) bestone = idx, bestonecost = cost;
		}
	}
	if (bestzero != -1 && bestone != -1 && bestzerocost + bestonecost > anscost) {
		ansx = bestzero, ansy = bestone, anscost = bestzerocost + bestonecost;
	}
	if (allzero) {
		anytwo(lst);
		return;
	}

	receven(zero, shift + 1);
	receven(one, shift + 1);

}
void recodd(const vector<int> &alst, const vector<int> &blst, int shift) {
	if (SZ(alst) < 1 || SZ(blst) < 1) return;
	bool allzero = true;
	vector<int> azero, aone;
	int abestzero = -1, abestzerocost = -1, abestone = -1, abestonecost = -1;
	for (int idx : alst) {
		int v = a[idx] >> shift;
		int cost = calczerocost(v, false);
		if (v != 0) allzero = false;
		if ((v & 1) == 0) {
			azero.PB(idx);
			if (cost > abestzerocost) abestzero = idx, abestzerocost = cost;
		} else {
			aone.PB(idx);
			if (cost > abestonecost) abestone = idx, abestonecost = cost;
		}
	}
	vector<int> bzero, bone;
	int bbestzero = -1, bbestzerocost = -1, bbestone = -1, bbestonecost = -1;
	for (int idx : blst) {
		int v = a[idx] >> shift;
		int cost = calczerocost(v, false, 0);
		if (v != 0) allzero = false;
		if ((v & 1) == 0) {
			bzero.PB(idx);
			if (cost > bbestzerocost) bbestzero = idx, bbestzerocost = cost;
		} else {
			bone.PB(idx);
			if (cost > bbestonecost) bbestone = idx, bbestonecost = cost;
		}
	}
	if (abestzero != -1 && bbestzero != -1 && abestzerocost + bbestzerocost + 1 > anscost) {
		ansx = abestzero, ansy = bbestzero, anscost = abestzerocost + bbestzerocost + 1;
	}
	if (abestone != -1 && bbestone != -1 && abestonecost + bbestonecost + 1 > anscost) {
		ansx = abestone, ansy = bbestone, anscost = abestonecost + bbestonecost + 1;
	}
	if (allzero) {
		if (1 > anscost) {
			ansx = alst[0], ansy = blst[0], anscost = 1;
		}
		return;
	}
	recodd(azero, bone, shift + 1);
	recodd(aone, bzero, shift + 1);
}

void rec(const vector<int> &lst, int shift) {
	vector<int> zero, one;
	for (int idx : lst) {
		int v = a[idx] >> shift;
		if ((v & 1) == 0) zero.PB(idx); else one.PB(idx);
	}
	// even moves
	receven(zero, shift);
	receven(one, shift);
	// odd moves
	recodd(zero, one, shift);
	recodd(one, zero, shift);
}

void solve() {
	map<int, vector<int>> mp;
	REP(i, n) {
		if (a[i] == 0) { mp[-1].PB(i); continue; }
		int bit = 0;
		while ((a[i] & (1 << bit)) == 0) ++bit;
		mp[bit].PB(i);
	}
	ansx = ansy = anscost = -1;
	int gbestzero = -1, gbestzerocost = -1;
	for (auto z : mp) {
		int lbestzero = -1, lbestzerocost = -1;
		//printf("%d:", z.first); for (int idx : z.second) printf(" %d", idx); puts("");
		for (int idx : z.second) {
			int zerocost = calczerocost(a[idx]);
			//printf("zerocost[%d]=%d\n", a[idx], zerocost);
			if (zerocost > lbestzerocost) lbestzerocost = zerocost, lbestzero = idx;
		}
		if (gbestzerocost != -1 && lbestzerocost != -1 && gbestzerocost + lbestzerocost > anscost) {
			ansx = gbestzero, ansy = lbestzero, anscost = gbestzerocost + lbestzerocost;
		}
		if (lbestzerocost > gbestzerocost) {
			gbestzero = lbestzero, gbestzerocost = lbestzerocost;
		}
	}
	for (auto z : mp) {
		if (z.first == -1) {
			anytwo(z.second);
			continue;
		}
		rec(z.second, z.first + 1);
	}
	//if (ansx != -1) { string s; int z = a[ansx]; while (z != 0) s += string(1, '0' + z % 2), z /= 2; if (SZ(s) == 0) s = "0"; reverse(s.begin(), s.end()); printf("x =%s\n", s.c_str()); }
	//if (ansy != -1) { string s; int z = a[ansy]; while (z != 0) s += string(1, '0' + z % 2), z /= 2; if (SZ(s) == 0) s = "0"; reverse(s.begin(), s.end()); printf("y =%s\n", s.c_str()); }
	//if (ansy != -1) { string s; int z = a[ansy]; int k = 0; while ((1 << k) < z) ++k; z = (1 << k) - z; while (z != 0) s += string(1, '0' + z % 2), z /= 2; if (SZ(s) == 0) s = "0"; reverse(s.begin(), s.end()); printf("y'=%s\n", s.c_str()); }
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d %d %d\n", ansx + 1, ansy + 1, anscost);
}

int main() {
	run();
	return 0;
}