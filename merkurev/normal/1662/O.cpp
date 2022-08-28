#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int R = 22;
const int D = 360;

bool wup[R + 1][D], wside[R + 1][D], was[R + 1][D];
queue<pair2<int>> q;
int n;
char tp[20];

void go(int x, int y)
{
	if (!was[x][y])
	{
		was[x][y] = true;
		q.push({x, y});
	}
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < D; j++)
		{
			wup[i][j] = false; // i -> i + 1
			wside[i][j] = false; // j -> j + 1
		}
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%s", tp);
		if (tp[0] == 'C')
		{
			int r, t1, t2;
			scanf("%d%d%d", &r, &t1, &t2);
			for (int j = t1; j != t2; j = (j + 1) % D)
			{
				wup[r - 1][j] = true;
			}
		} else
		{
			int r1, r2, t;
			scanf("%d%d%d", &r1, &r2, &t);
			t = (t - 1 + D) % D;
			for (int j = r1; j < r2; j++) wside[j][t] = true;
		}
	}
	for (int i = 0; i <= R; i++)
	{
		for (int j = 0; j < D; j++) was[i][j] = false;
	}
	q.push({R, 0});
	while (!q.empty())
	{
		auto [curr, curt] = q.front();
		q.pop();
		if (curr > 0 && !wup[curr - 1][curt]) go(curr - 1, curt);
		if (curr < R && !wup[curr][curt]) go(curr + 1, curt);
		if (!wside[curr][curt]) go(curr, (curt + 1) % D);
		if (!wside[curr][(curt - 1 + D) % D]) go(curr, (curt - 1 + D) % D);
	}
	if (was[0][0]) printf("YES\n");
	else printf("NO\n");
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++) solve();
    return 0;
}