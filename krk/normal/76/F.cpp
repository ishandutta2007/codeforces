#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> dd;

const int Maxn = 100005;
const ld eps = 1e-7l;

int n;
int x[Maxn], t[Maxn];
int v;
ld ang, sn, cs;
dd c[Maxn];
vector <ld> seq;

bool Less(const dd &a, const dd &b)
{
	if (fabs(a.first - b.first) > eps) return a.first < b.first;
	if (fabs(a.second - b.second) > eps) return a.second < b.second;
	return false; 
}

int getRes1()
{
	seq.clear();
	for (int i = 0; i < n; i++) if (c[i].first + eps >= 0.0l && c[i].second + eps >= 0.0l) {
		int lef = 0, rig = int(seq.size()) - 1;
		int ind = seq.size();
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (c[i].second + eps < seq[mid]) { ind = mid; rig = mid - 1; }
			else lef = mid + 1;
		}
		if (ind < seq.size()) seq[ind] = c[i].second;
		else seq.push_back(c[i].second);
	}
	return seq.size();
}

int getRes2()
{
	seq.clear();
	for (int i = 0; i < n; i++) {
		int lef = 0, rig = int(seq.size()) - 1;
		int ind = seq.size();
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (c[i].second + eps < seq[mid]) { ind = mid; rig = mid - 1; }
			else lef = mid + 1;
		}
		if (ind < seq.size()) seq[ind] = c[i].second;
		else seq.push_back(c[i].second);
	}
	return seq.size();
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &t[i]);
	scanf("%d", &v);
	ang = atan(1.0l / ld(v)); sn = sin(ang), cs = cos(ang);
	for (int i = 0; i < n; i++)
		c[i] = dd(x[i] * sn + t[i] * cs, -x[i] * sn + t[i] * cs);
	sort(c, c + n, Less);
	printf("%d %d\n", getRes1(), getRes2());
	return 0;
}