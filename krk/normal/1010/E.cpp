#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 8;
const int Inf = 1000000000;

struct triple {
	int x, y, z;
	int ind;
	triple(int x = 0, int y = 0, int z = 0, int ind = -1): x(x), y(y), z(z), ind(ind) {}
	bool operator <(const triple &t) const {
		if (x != t.x) return x < t.x;
		if (y != t.y) return y < t.y;
		if (z != t.z) return z < t.z;
		return ind < t.ind;
	}
};

int xmax, ymax, zmax;
int n, m, k;
ii xp, yp, zp;
vector <triple> V[Maxm];
int res[Maxn];
map <int, int> M;

void Init(ii &p) { p.first = Inf; p.second = -Inf; }

void Extend(ii &p, int val) { p.first = min(p.first, val); p.second = max(p.second, val); }

bool In(const ii &p, int val) { return p.first <= val && val <= p.second; } 

void Add(int mask, int x, int y, int z)
{
	V[mask].push_back(triple(x, y, z));
}

void addZ(int mask, int x, int y, int z)
{
	if (In(zp, z)) {
		Add(mask, x, y, 0);
		Add(mask | 1 << 2, x, y, -zmax);
	} else if (z > zp.second) Add(mask, x, y, z);
		   else Add(mask | 1 << 2, x, y, -z);
}

void addY(int mask, int x, int y, int z)
{
	if (In(yp, y)) {
		addZ(mask, x, 0, z);
		addZ(mask | 1 << 1, x, -ymax, z);
	} else if (y > yp.second) addZ(mask, x, y, z);
		   else addZ(mask | 1 << 1, x, -y, z);
}

void addX(int mask, int x, int y, int z)
{
	if (In(xp, x)) {
		addY(mask, 0, y, z);
		addY(mask | 1 << 0, -xmax, y, z);
	} else if (x > xp.second) addY(mask, x, y, z);
	  	   else addY(mask | 1 << 0, -x, y, z);
}

void Push(int mask, int x, int y, int z, int ind)
{
	V[mask].push_back(triple(x, y, z, ind));
}

void pushZ(int mask, int x, int y, int z, int ind)
{
	Push(mask, x, y, z, ind);
	Push(mask | 1 << 2, x, y, -z, ind);
}

void pushY(int mask, int x, int y, int z, int ind)
{
	pushZ(mask, x, y, z, ind);
	pushZ(mask | 1 << 1, x, -y, z, ind);
}

void pushX(int mask, int x, int y, int z, int ind)
{
	pushY(mask, x, y, z, ind);
	pushY(mask | 1 << 0, -x, y, z, ind);
}

void Insert(int x, int y)
{
	map <int, int>::iterator it = M.lower_bound(x);
	while (it != M.end() && y <= it->second) M.erase(it++);
	it = M.upper_bound(x);
	if (it != M.begin()) {
		it--;
		if (it->second <= y) return;
	}
	M[x] = y;
}

bool checkMore(int x, int y)
{
	map <int, int>::iterator it = M.upper_bound(x);
	if (it != M.begin()) {
		it--;
		return it->second <= y;
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &xmax, &ymax, &zmax);
	scanf("%d %d %d", &n, &m, &k);
	Init(xp); Init(yp); Init(zp);
	for (int i = 0; i < n; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		Extend(xp, x); Extend(yp, y); Extend(zp, z);
	}
	for (int i = 0; i < m; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		if (In(xp, x) && In(yp, y) && In(zp, z)) { printf("INCORRECT\n"); return 0; }
		addX(0, x, y, z);
	}
	printf("CORRECT\n");
	for (int i = 0; i < k; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		if (In(xp, x) && In(yp, y) && In(zp, z)) res[i] = 1;
		else pushX(0, x, y, z, i);
	}
	for (int i = 0; i < Maxm; i++) {
		M.clear();
		sort(V[i].begin(), V[i].end());
		for (int j = 0; j < V[i].size(); j++) if (V[i][j].ind == -1)
			Insert(V[i][j].y, V[i][j].z);
		else if (checkMore(V[i][j].y, V[i][j].z)) res[V[i][j].ind] = -1;
	}
	for (int i = 0; i < k; i++)
		if (res[i] == 1) printf("OPEN\n");
		else if (res[i] == 0) printf("UNKNOWN\n");
		else if (res[i] == -1) printf("CLOSED\n");
	return 0;
}