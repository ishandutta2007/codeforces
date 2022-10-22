#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

struct pos {
	ll num;
	int lst, st;
	ll need[2];
	pos(ll num = 0ll, int lst = 0, int st = 0, ll need0 = 0, ll need1 = 0):
		num(num), lst(lst), st(st) { need[0] = need0; need[1] = need1; }
};

const int Maxd = 10;
const int Maxc = 8;
const int Maxp = 14;
const ll lim = 100000000000000ll;
const int Maxl = 300000;

ll n, k;
vector <pos> P[Maxc]; 
int hasmem[Maxc][Maxd][2][Maxl];
map <ll, int> has[Maxc][Maxd][2];
ll res;

void Insert(int c, int d, int f, ll md)
{
	if (md < Maxl) hasmem[c][d][f][md]++;
	else has[c][d][f][md]++; 
}

int Get(int c, int d, int f, ll md)
{
	if (md < Maxl) return hasmem[c][d][f][md];
	map <ll, int>::iterator it = has[c][d][f].find(md);
	return it == has[c][d][f].end()? 0: it->second;
}

void genBegs(int len, ll num, int lst, int st)
{
	if (len >= Maxc) return;
	ll md = num % n;
	for (int i = 0; i < len; i++)
		md = 10ll * md % n;
	ll need0 = (n - md) % n;
	md = 10ll * md % n;
	ll need1 = (n - md) % n;
	P[len].push_back(pos(num, lst, st, need0, need1));
	if (st >= 0)
		for (int i = 0; i < lst; i++)
			genBegs(len + 1, 10ll * num + i, i, -1);
	if (st <= 0)
		for (int i = lst + 1; i < Maxd; i++)
			genBegs(len + 1, 10ll * num + i, i, 1);
}

void genEnds(int len, int f, int s, int lst, int st, ll mod)
{
	if (len >= Maxc) return;
	Insert(len, f, s == 1? 1: 0, mod);
	if (st == 1)
		for (int i = 0; i < lst; i++)
			genEnds(len + 1, f, s, i, -1, (10ll * mod + i) % n);
	else for (int i = lst + 1; i < Maxd; i++)
			genEnds(len + 1, f, s, i, 1, (10ll * mod + i) % n);
}

void Gen(int len, int needlen, ll num, int lst, int st, ll &k)
{
	if (len == needlen) {
		if (num % n == 0) {
			k--;
			if (k == 0) res = num;
		}
	} else {
		if (st >= 0)
			for (int j = 0; j < lst && k > 0; j++)
				Gen(len + 1, needlen, 10ll * num + j, j, -1, k);
		if (st <= 0)
			for (int j = lst + 1; j < Maxd && k > 0; j++)
				Gen(len + 1, needlen, 10ll * num + j, j, 1, k);
	}
}

bool Solve(int digs, ll &k)
{
	if (digs == 1) {
		for (int i = 1; i < Maxd; i++)
			if (i % n == 0) {
				k--;
				if (k == 0) { res = i; return true; }
			}
	} else if (digs == 2) {
		for (int i = 10; i < 100; i++)
			if (i % 11 > 0 && i % n == 0) {
				k--;
				if (k == 0) { res = i; return true; }
			}
	} else {
		int p1 = digs / 2;
		int p2 = digs - p1;
		int f = p2 - p1;
		pos p;
		for (int i = 0; i < P[p1].size(); i++) {
			p = P[p1][i];
			ll got = 0;
			if (p.st >= 0)
				for (int j = 0; j < p.lst; j++) {
					ll g = Get(p2, j, 0, p.need[f]);
					if (g >= k) { Gen(p1 + 1, digs, p.num * 10ll + j, j, -1, k); return true; }
					else k -= g;
				}
			if (p.st <= 0)
				for (int j = p.lst + 1; j < Maxd; j++) {
					ll g = Get(p2, j, 1, p.need[f]);
					if (g >= k) { Gen(p1 + 1, digs, p.num * 10ll + j, j, 1, k); return true; }
					else k -= g;
				}
		}
	}
	return false;
}

int main()
{
	scanf("%I64d %I64d", &n, &k);
	if (n > lim / k) { printf("-1\n"); return 0; }
	for (int i = 1; i < Maxd; i++)
		genBegs(1, i, i, 0);
	for (int i = 0; i < Maxd; i++) {
		genEnds(1, i, -1, i, -1, i);
		genEnds(1, i, 1, i, 1, i);
	}
	for (int i = 1; i <= Maxp; i++)
		if (Solve(i, k)) {
			printf("%I64d\n", res);
			return 0;
		}
	printf("-1\n");
	return 0;
}