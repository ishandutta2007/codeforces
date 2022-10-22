#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

struct triple {
	int x, y;
	ll dist;
	triple(int x, int y, ll dist): x(x), y(y), dist(dist) {}
	bool operator <(const triple &b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		return dist < b.dist;
	}
};

const int Maxn = 2005;

int n;
int x[Maxn], y[Maxn];
map <triple, int> M;
ll res;

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

ll Dist(int a, int b) { return ll(x[a] - x[b]) * (x[a] - x[b]) + ll(y[a] - y[b]) * (y[a] - y[b]); }

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ii(x[i], y[i]) < ii(x[j], y[j])) {
				int a = x[j] - x[i], b = y[j] - y[i];
				int g = gcd(abs(a), abs(b));
				a /= g; b /= g;
				M[triple(a, b, Dist(i, j))]++;
			}
	for (map <triple, int>::iterator it = M.begin(); it != M.end(); it++)
		res += ll(it->second) * (it->second - 1) / 2;
	printf("%I64d\n", res / 2);
    return 0;
}