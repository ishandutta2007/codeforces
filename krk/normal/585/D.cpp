#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 27;
const int Inf = 1000000000;

int n;
int L[Maxn], M[Maxn], W[Maxn];
map <ii, int> Mp;
int best = -Inf;
int ba, bb, bc;
int seq[Maxn];
bool ok;

void Gen(int lvl, int lim, int a = 0, int b = 0, int c = 0)
{
	if (lvl == lim) {
		map <ii, int>::iterator it = Mp.find(ii(b - a, c - a));
		if (it == Mp.end()) Mp[ii(b - a, c - a)] = a;
		else it->second = max(it->second, a);
	} else {
		Gen(lvl + 1, lim, a + L[lvl], b + M[lvl], c);
		Gen(lvl + 1, lim, a + L[lvl], b, c + W[lvl]);
		Gen(lvl + 1, lim, a, b + M[lvl], c + W[lvl]);
	}
}

void Gen2(int lvl, int lim, int a = 0, int b = 0, int c = 0)
{
	if (lvl == lim) {
		map <ii, int>::iterator it = Mp.find(ii(a - b, a - c));
		if (it != Mp.end()) {
			int f = it->second;
			if (a + f > best) {
				best = a + f;
				ba = f; bb = f + it->first.first, bc = f + it->first.second;
			}
		}
	} else {
		Gen2(lvl + 1, lim, a + L[lvl], b + M[lvl], c);
		Gen2(lvl + 1, lim, a + L[lvl], b, c + W[lvl]);
		Gen2(lvl + 1, lim, a, b + M[lvl], c + W[lvl]);
	}
}

void Gen3(int lvl, int lim, int a, int b, int c)
{
	if (lvl == lim) {
		if (a == 0 && b == 0 && c == 0)
			ok = true;
	} else {
		if (!ok) {
			seq[lvl] = 0; Gen3(lvl + 1, lim, a + L[lvl], b + M[lvl], c);
		}
		if (!ok) {
			seq[lvl] = 1; Gen3(lvl + 1, lim, a + L[lvl], b, c + W[lvl]);
		}
		if (!ok) {
			seq[lvl] = 2; Gen3(lvl + 1, lim, a, b + M[lvl], c + W[lvl]);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &L[i], &M[i], &W[i]);
	int h = n / 2;
	Gen(0, h);
	Gen2(h, n);
	if (best == -Inf) printf("Impossible\n");
	else {
		ok = false; Gen3(0, h, -ba, -bb, -bc);
		ok = false; Gen3(h, n, ba - best, bb - best, bc - best);
		for (int i = 0; i < n; i++)
			if (seq[i] == 0) printf("LM\n");
			else if (seq[i] == 1) printf("LW\n");
			else printf("MW\n");
	}
	return 0;
}