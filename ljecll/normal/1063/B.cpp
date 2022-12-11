/*
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

random_device(rd);
mt19937 rng(rd());
const long long FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

struct custom_hash
{
	template<class T>
    unsigned long long operator()(T v) const
	{
		unsigned long long x = v;
		x += FIXED_RANDOM; x += 11400714819323198485ull;
        x = (x ^ (x >> 30)) * 13787848793156543929ull;
        x = (x ^ (x >> 27)) * 10723151780598845931ull;
        return x ^ (x >> 31);
    }
};

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U> using hash_table = gp_hash_table<T, U, custom_hash>;

template<class T>
void readi(T &x)
{
	x = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		x = -x;
	}
}
template<class T>
void printi(T output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int buf[20], n = 0;
	while(output)
	{
		buf[n] = ((output % 10));
		output /= 10;
		n++;
	}
	for (n--; n >= 0; n--)
	{
		putchar(buf[n] + '0');
	}
	return;
}
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
long long expo(long long a, long long e, long long mod)
{
	return ((e == 0) ? 1 : ((expo(a * a % mod, e >> 1, mod)) * ((e & 1) ? a : 1) % mod));
}
template<class T, class U>
T nmod(T &x, U mod)
{
	if (x >= mod) x -= mod;
}
template<class T>
T gcd(T a, T b)
{
	return (b ? gcd(b, a % b) : a);
}
template<class T>
T randomize(T mod)
{
	return (uniform_int_distribution<T>(0, mod - 1))(rng);
}

#define y0 ___y0
#define y1 ___y1
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;
#define sz(x) ((int) (x.size()))

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-9;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 2013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N, M, L, R;
bool grid[MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int dist[MAXN][MAXN];
deque<pair<int, pii> > q;
pii start;
int ans;

bool valid(int x, int y)
{
	return (0 <= x && x < N && 0 <= y && y < M && grid[x][y]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	cin >> N >> M >> start.fi >> start.se >> L >> R;
	ckmin(L, N * M); ckmin(R, N * M);
	start.fi--; start.se--;
	for (int i = 0; i < N; i++)
	{
		string temps;
		cin >> temps;
		for (int j = 0; j < M; j++)
		{
			grid[i][j] = (temps[j] == '.');
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dist[i][j] = INF;
		}
	}
	dist[start.fi][start.se] = 0;
	q.PB(MP(0, start));
	while(!q.empty())
	{
		int x = q.front().se.fi, y = q.front().se.se, d = q.front().fi;
		q.pop_front();
		if (d != dist[x][y])
		{
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i], nd = d + (i == 1);
			if (!valid(nx, ny))
			{
				continue;
			}
			if (dist[nx][ny] > nd)
			{
				dist[nx][ny] = nd;
				if (i == 1)
				{
					q.PB(MP(nd, MP(nx, ny)));
				}
				else
				{
					q.PF(MP(nd, MP(nx, ny)));
				}
			}
		}
	}
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < M; j++)
	// 	{
	// 		cerr << dist[i][j] << ' ';
	// 	}
	// 	cerr << endl;
	// }
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!valid(i, j)) continue;
			int dy = j - start.se, nl = dist[i][j], nr = dy + nl;
			if (nl <= L && nr <= R)
			{
				ans++;
				// cerr << "yes " << i << ' ' << j << endl;
			}
		}
	}
	cout << ans << '\n';
 	//1 and 3 are bad!

	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}