#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	bool operator < (const Point& other) const
	{
		return x != other.x ? x < other.x : y < other.y;
	}
	Point operator + (const Point& other) const
	{
		return Point(x + other.x, y + other.y);
	}
	friend istream& operator >> (istream& in, Point& p)
	{
		in >> p.x >> p.y;
		return in;
	}
	friend ostream& operator << (ostream& out, const Point& p)
	{
		out << p.x << ' ' << p.y;
		return out;
	}
};

void solve()
{
	int n;
	cin >> n;
	vector<Point> ar(n), br(n);
	For(i, n)
		cin >> ar[i];
	For(i, n)
		cin >> br[i];
	sort(all(ar));
	sort(all(br));
	reverse(all(br));
	For(i, 1)
		cout << (ar[i] + br[i]) << '\n';
	For(i, n - 1)
		if ((ar[i] + br[i] < ar[i + 1] + br[i + 1]) || (ar[i + 1] + br[i + 1] < ar[i] + br[i]))
			throw;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}