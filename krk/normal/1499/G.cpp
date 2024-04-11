#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

struct pos {
	int a, b;
	bool sam;
	pos(int a = 0, int b = 0, bool sam = false): a(a), b(b), sam(sam) {}
};

const int Maxm = 400004;
const int mod = 998244353;

int n1, n2, m;
int spec[Maxm];
int par[Maxm], siz[Maxm];
int col[Maxm];
ii H[Maxm];
ii glob;
vector <pos> seq;

ii Get(int v)
{
	if (par[v] == v) return ii(v, 0);
	ii my = Get(par[v]);
	par[v] = my.first;
	col[v] ^= my.second;
	return ii(par[v], col[v]);
}

ii Add(ii a, ii b)
{
	return ii((a.first + b.first) % mod, (a.second + b.second) % mod);
}

ii Sub(ii a, ii b)
{
	return ii((a.first - b.first + mod) % mod, (a.second - b.second + mod) % mod);
}

void Do(const pos &p)
{
	glob = Sub(glob, H[p.a]);
	glob = Sub(glob, H[p.b]);
	par[p.b] = p.a;
	siz[p.a] += siz[p.b];
	col[p.b] = p.sam;
	if (p.sam) H[p.a] = Add(H[p.a], ii(H[p.b].second, H[p.b].first));
	else H[p.a] = Add(H[p.a], H[p.b]);
	glob = Add(glob, H[p.a]);
}

void Undo(const pos &p)
{
	glob = Sub(glob, H[p.a]);
	if (p.sam) 
		H[p.a] = Sub(H[p.a], ii(H[p.b].second, H[p.b].first));
	else H[p.a] = Sub(H[p.a], H[p.b]);
	glob = Add(glob, H[p.a]);
	glob = Add(glob, H[p.b]);
}

void Union(int a, int b)
{
	ii para = Get(a), parb = Get(b);
	if (para.first == parb.first) return;
	if (siz[para.first] < siz[parb.first])
		swap(para, parb);
	seq.push_back(pos(para.first, parb.first, para.second == parb.second));
	Do(seq.back());
}

int main()
{
	scanf("%d %d %d", &n1, &n2, &m);
	int my = 1;
	for (int i = 1; i <= m; i++) {
		my = ll(my) * 2 % mod;
		int x, y; scanf("%d %d", &x, &y);
		y += n1;
		par[i] = i;
		siz[i] = 1;
		col[i] = 0;
		H[i] = ii(0, my);
		if (spec[x]) {
			Union(spec[x], i);
			spec[x] = 0;
		} else spec[x] = i;
		if (spec[y]) {
			Union(spec[y], i);
			spec[y] = 0;
		} else spec[y] = i;
	}
	int q; scanf("%d", &q);
	while (q--) {
		int typ, x, y; scanf("%d", &typ);
		if (typ == 1) {
			my = ll(my) * 2 % mod; m++;
			scanf("%d %d", &x, &y);
			y += n1;
			par[m] = m;
			siz[m] = 1;
			col[m] = 0;
			H[m] = ii(0, my);
			if (spec[x]) {
				Union(spec[x], m);
				spec[x] = 0;
			} else spec[x] = m;
			if (spec[y]) {
				Union(spec[y], m);
				spec[y] = 0;
			} else spec[y] = m;
			printf("%d\n", glob.first); fflush(stdout);
		} else {
			vector <int> res;
			for (int i = 1; i <= m; i++) if (Get(i).second == 1)
				res.push_back(i);
			printf("%d", int(res.size()));
			for (int i = 0; i < res.size(); i++)
				printf(" %d", res[i]);
			printf("\n"); fflush(stdout);
		}
	}
    return 0;
}