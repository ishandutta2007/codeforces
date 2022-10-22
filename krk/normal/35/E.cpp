#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

struct pos {
	int x, y, z;
	pos(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) { }
	bool operator <(const pos &p) const {
		if (x != p.x) return x < p.x;
		if (z != p.z) return z < p.z;
		return z == -1? y < p.y: y > p.y;
	}
};

const int Maxn = 200005;

int n;
pos p[Maxn];
map <int, int> seq;
vector <ii> res;

void Add(const ii &p)
{
	if (res.size() >= 2 && (res[res.size() - 2].first == res.back().first && res.back().first == p.first ||
		                    res[res.size() - 2].second == res.back().second && res.back().second == p.second))
		res.pop_back();
	res.push_back(p);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int h, l, r; scanf("%d %d %d", &h, &l, &r);
		p[2 * i] = pos(l, h, -1); p[2 * i + 1] = pos(r, h, 1);
	}
	sort(p, p + 2 * n);
	for (int i = 0; i < 2 * n; i++) {
		if (seq.empty()) Add(ii(p[i].x, 0));
		else Add(ii(p[i].x, seq.rbegin()->first));
		if (p[i].z == -1) seq[p[i].y]++;
		else if (--seq[p[i].y] == 0) seq.erase(p[i].y);
		if (seq.empty()) Add(ii(p[i].x, 0));
		else Add(ii(p[i].x, seq.rbegin()->first));
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}