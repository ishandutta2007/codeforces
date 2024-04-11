#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 10005;
const int Maxb = 31;

struct linker {
	int x, y, id;
	linker(int x = 0, int y = 0, int id = 0): x(x), y(y), id(id) {}
	bool operator <(const linker &b) const {
		if (y != b.y) return y > b.y;
		if (x != b.x) return x > b.x;
		return id < b.id;
	}
};

int n;
linker L[Maxn];
int xbas[Maxb];
int rval[Maxb], masktaken[Maxn];
vector <ii> res;

int getBit(int x)
{
	if (x == 0) return -1;
	for (int i = Maxb - 1; i >= 0; i--)
		if (x & 1 << i) return i;
}

void Swap(int a, int b)
{
	if (a == b) return;
	res.push_back(ii(L[a].id, L[b].id));
	res.push_back(ii(L[b].id, L[a].id));
	res.push_back(ii(L[a].id, L[b].id));
	swap(L[a].x, L[b].x);
	int ab = getBit(L[a].x), bb = getBit(L[b].x);
	if (ab != -1) xbas[ab] = a;
	if (bb != -1) xbas[bb] = b;
}

void writeMask(int x)
{
	for (int i = 0; i < Maxb; i++)
		if (masktaken[L[x].id] & 1 << i)
			res.push_back(ii(L[x].id, rval[i]));
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &L[i].x); L[i].id = i;
		for (int b = Maxb - 1; b >= 0; b--)
			if (L[i].x & 1 << b)
				if (xbas[b]) { res.push_back(ii(i, xbas[b])); L[i].x ^= L[xbas[b]].x; }
				else { xbas[b] = i; break; }
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &L[i].y); int num = L[i].y; L[i].y = 0;
		for (int b = Maxb - 1; b >= 0; b--)
			if (num & 1 << b)
				if (xbas[b]) { num ^= L[xbas[b]].x; L[i].y |= 1 << b; }
				else { printf("-1\n"); return 0; }
	}
	int cur = 1;
	while (true) {
		sort(L + cur, L + n + 1);
		for (int i = cur; i <= n; i++) {
			int b = getBit(L[i].x);
			if (b != -1) xbas[b] = i;
		}
		int b = getBit(L[cur].y);
		if (b == -1) {
			for (int i = cur; i <= n; i++) {
				if (L[i].x) res.push_back(ii(L[i].id, L[i].id));
				writeMask(i);
			}
			break;
		} else {
			Swap(cur, xbas[b]);
			writeMask(cur);
			for (int i = b - 1; i >= 0; i--)
				if (L[cur].y & 1 << i) res.push_back(ii(L[cur].id, L[xbas[i]].id));
			rval[b] = L[cur].id; masktaken[L[cur].id] ^= 1 << b; 
			for (int i = cur + 1; i <= n; i++)
				if (L[i].y & 1 << b) {
					L[i].y ^= L[cur].y;
					masktaken[L[i].id] ^= masktaken[L[cur].id];
				}
		}
		cur++;
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}