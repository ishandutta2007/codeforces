#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 200005;
const int Maxp = 320;

struct pos {
	int ind, siz, par, val;
	pos(int ind = 0, int siz = 0, int par = 0, int val = 0): ind(ind), siz(siz), par(par), val(val) {}
};

int n, m;
int a[Maxn], b[Maxn];
set <ii> In, Cur;
int siz[Maxn], par[Maxn], val[Maxn];
pos mem[Maxm];
int mlen;

ii getPar(int x) 
{
	if (x == par[x]) return ii(x, 0);
	ii got = getPar(par[x]);
	return ii(got.first, got.second ^ val[x]);
}

void Merge(int a, int b, int add, bool sav)
{
	if (sav) {
		mem[mlen++] = pos(a, siz[a], par[a], val[a]);
		mem[mlen++] = pos(b, siz[b], par[b], val[b]);
	}
	siz[a] += siz[b]; par[b] = a; val[b] = add;
}

bool Check(int a, int b, bool sav)
{
	ii para = getPar(a), parb = getPar(b);
	if (para.first == parb.first) return para.second != parb.second;
	if (siz[para.first] >= siz[parb.first]) Merge(para.first, parb.first, (para.second ^ parb.second ^ 1), sav);
	else Merge(parb.first, para.first, (para.second ^ parb.second ^ 1), sav);
	return true;
}

void Restore()
{
	while (mlen > 0) {
		mlen--;
		siz[mem[mlen].ind] = mem[mlen].siz;
		par[mem[mlen].ind] = mem[mlen].par;
		val[mem[mlen].ind] = mem[mlen].val;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i += Maxp) {
		int to = min(i + Maxp, m);
		Cur.clear();
		for (int j = i; j < to; j++) {
			scanf("%d %d", &a[j], &b[j]);
			Cur.insert(ii(a[j], b[j]));
		}
		for (int l = 1; l <= n; l++)
			siz[l] = 1, par[l] = l, val[l] = 0;
		mlen = 0;
		bool ok = true;
		for (set <ii>::iterator it = In.begin(); it != In.end(); it++)
			if (Cur.find(*it) == Cur.end()) {
				bool nw = Check(it->first, it->second, false);
				ok = ok && nw;
			}
		for (int j = i; j < to; j++) {
			bool curok = ok;
			set <ii>::iterator it = In.find(ii(a[j], b[j]));
			if (it != In.end()) In.erase(it);
			else In.insert(ii(a[j], b[j]));
			Restore();
			for (set <ii>::iterator it = Cur.begin(); it != Cur.end() && curok; it++)
				if (In.find(*it) != In.end())
					curok = Check(it->first, it->second, true);
			printf("%s\n", curok? "YES": "NO");
		}
	}
	return 0;
}