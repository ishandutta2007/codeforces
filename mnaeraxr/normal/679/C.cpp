#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 501;

string mat[510];
int acc1[maxn][maxn];
int acc2[maxn][maxn];
int mk[maxn * maxn];

unordered_map<int, pair<pii, pii>> envelop;

void update(int idx, int x, int y)
{
	if (envelop.count(idx) == 0)
	{
		envelop[idx] =
		{
			{	x, y},
			{	x, y}};
	}
	else
	{
		auto &p = envelop[idx];
		p.first.first = min(p.first.first, x);
		p.first.second = min(p.first.second , y);

		p.second.first = max(p.second.first, x);
		p.second.second = max(p.second.second, y);
	}
}

int ds[maxn * maxn];
int n, k;

int id(int x, int y)
{
	return n * x + y;
}

int root(int a)
{
	return ds[a] < 0 ? a : ds[a] = root(ds[a]);
}

bool join(int a, int b)
{
	a = root(a), b = root(b);
	if (a == b)
		return false;
	if (ds[a] > ds[b])
		swap(a, b);
	ds[a] += ds[b];
	ds[b] = a;
	return true;
}

bool inside(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n * n; ++i)
		ds[i] = -1;

	for (int i = 0; i < n; ++i)
	{
		cin >> mat[i];
		for (int j = 0; j < n; ++j)
		{
			int p = id(i, j), p1;

			acc1[i + 1][j + 1] = (mat[i][j] == 'X' ? 1 : 0) + acc1[i][j + 1]
					+ acc1[i + 1][j] - acc1[i][j];

			if (i)
			{
				p1 = id(i - 1, j);
				if (mat[i][j] == '.' && mat[i - 1][j] == '.')
					join(p, p1);
			}
			if (j)
			{
				p1 = id(i, j - 1);
				if (mat[i][j] == '.' && mat[i][j - 1] == '.')
					join(p, p1);
			}
		}
	}

//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < n; ++j)
//			root(id(i,j));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			if (mat[i][j] == '.')
			{
				int p = root(id(i, j));
				update(p, i, j);
			}
	}

	for (auto e : envelop)
	{
		pair<pii, pii> P = e.second;
		auto p1 = P.first;
		auto p2 = P.second;

		int t = -ds[e.first];

		int x1 = max(0, p2.first - k + 1);
		int y1 = max(0, p2.second - k + 1);
		int x2 = p1.first;
		int y2 = p1.second;

		if (x1 <= x2 && y1 <= y2)
		{
			acc2[x1][y1] += t;
			acc2[x2 + 1][y1] += -t;
			acc2[x1][y2 + 1] += -t;
			acc2[x2 + 1][y2 + 1] += t;
		}
	}

	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)
			acc2[i][j] += acc2[i - 1][j];

	for (int i = 0; i < n; ++i)
		for (int j = 1; j < n; ++j)
			acc2[i][j] += acc2[i][j - 1];

//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cout << acc2[i][j] << " ";
//		}
//		cout << endl;
//	}

	int best = 0;

	int timer = 1;

	for (int i = 0; i <= n - k; ++i)
		for (int j = 0; j <= n - k; ++j, ++timer){
//			cout << endl;
//			cout << "solve: " << i << " " << j << endl;
//			unordered_set<int> S;

			int ans = acc1[i + k][j + k] - acc1[i][j + k] - acc1[i + k][j] + acc1[i][j];
//			cout << ans << endl;
			ans += acc2[i][j];
//			cout << acc2[i][j] << endl;



			for (int h = 0, x, y; h < k; ++h){
				x = i - 1, y = h + j;
				if (inside(x, y) && mat[x][y] != 'X'){
					int p = root(id(x, y));
					if (mk[p] != timer){
						mk[p] = timer;
						ans += -ds[p];
					}
				}
				x = i + k, y = h + j;
				if (inside(x, y) && mat[x][y] != 'X'){
					int p = root(id(x, y));
					if (mk[p] != timer){
						mk[p] = timer;
						ans += -ds[p];
					}
				}
				x = i + h, y = j - 1;
				if (inside(x, y) && mat[x][y] != 'X'){
					int p = root(id(x, y));
					if (mk[p] != timer){
						mk[p] = timer;
						ans += -ds[p];
					}
				}
				x = i + h, y = j + k;
				if (inside(x, y) && mat[x][y] != 'X'){
					int p = root(id(x, y));
					if (mk[p] != timer){
						mk[p] = timer;
						ans += -ds[p];
					}
				}
			}

//			cout << i << " " << j << " " << ans << endl;

			best = max(ans, best);
		}

	cout << best << endl;

	return 0;
}