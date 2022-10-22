#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

int q;
map <int, int> up, down;

ll Cross(ll ax, ll ay, ll bx, ll by) { return ax * by - ay * bx; }

bool Inside(map <int, int> &M, int x, int y)
{
	map <int, int>::iterator it = M.lower_bound(x);
	if (it == M.end()) return false;
	if (it->first == x) return y >= it->second;
	if (it == M.begin()) return false;
	map <int, int>::iterator it2 = it; it2--;
	return Cross(it->first - it2->first, it->second - it2->second, x - it2->first, y - it2->second) >= 0ll;
}

void Insert(map <int, int> &M, int x, int y)
{
	if (Inside(M, x, y)) return;
	M[x] = y;
	map <int, int>::iterator it = M.find(x), it2 = it; it2--;
	while (it != M.begin() && it2 != M.begin()) {
		it = it2; it2--;
		if (Cross(x - it2->first, y - it2->second, it->first - it2->first, it->second - it2->second) < 0)
			break;
		M.erase(it);
	}
	it = M.find(x), it2 = it; it2++;
	while (it2 != M.end()) {
		it = it2; it2++;
		if (it2 == M.end()) break;
		if (Cross(it2->first - x, it2->second - y, it->first - x, it->second - y) < 0)
			break;
		M.erase(it);
	}
}

int main()
{
	scanf("%d", &q);
	while (q--) {
		int t, x, y; scanf("%d %d %d", &t, &x, &y);
		if (t == 1) { Insert(up, x, y); Insert(down, x, -y); }
		else printf("%s\n", Inside(up, x, y) && Inside(down, x, -y)? "YES": "NO");
	}
	return 0;
}