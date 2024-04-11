/*
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct chash
{
	int operator()(int x) const
	{
		x ^= (x >> 20) ^ (x >> 12);
		return x ^ (x >> 7) ^ (x >> 4);
	}
	int operator()(long long x) const
	{
		return x ^ (x >> 32);
	}
};

template<typename T> using orderedset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using hashtable = gp_hash_table<T, U, chash>;

template<class T>
void readi(T &x)
{
	T input = 0;
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
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
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
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
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
template<class T, class U>
T normalize(T x, U mod = 1000000007)
{
	return (((x % mod) + mod) % mod);
}
long long randomizell(long long mod)
{
	return ((1ll << 45) * rand() + (1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}
int randomize(int mod)
{
	return ((1ll << 15) * rand() + rand()) % mod;
}

#define y0 ___y0
#define y1 ___y1
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-10;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 69

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N, M;
vector<pii> beg, fin;
int occ[MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
vector<ppp> res1, res2;

bool valid(int x, int y)
{
	return (0 < x && x <= N && 0 < y && y <= N);
}

void compute_dist()
{
	//compute distances from (x, y) to (1, x)
	// debug(occ[1][1]);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				dist[i][j][k] = INF;
			}
		}
		if (occ[i][i] != -1)
		{
			// cerr << "bump " << i << endl;
			continue;
		}
		// cerr << "lolol " << 1 << ' ' << i << " still alive\n";
		dist[i][i][i] = 0;
		queue<pair<int, pii> > q;
		q.push({0, {i, i}});
		while(!q.empty())
		{
		 	int x = q.front().se.fi, y = q.front().se.se, d = q.front().fi;
			// cerr << "dist " << 1 << ' ' << i << ' ' << x << ' ' << y << " = " << d << endl;
			// cerr << q.size() << endl;
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int X = x + dx[j], Y = y + dy[j];
				// cerr << X << ' ' << Y << ' ' << occ[X][Y] << endl;
				// cerr << 1 << ' ' << i << " to " << X << ' ' << Y << ' ' << d + 1 << ' ' << dist[i][X][Y] << ' ' << valid(X, Y) << endl;
				if (valid(X, Y) && dist[i][X][Y] > d + 1 && (occ[X][Y] == i - 1 || occ[X][Y] == -1))
				{
					// cerr << "dist " << 1 << ' ' << i << " to " << X << ' ' << Y << ' ' << d + 1 << endl;
					dist[i][X][Y] = d + 1;
					if (occ[X][Y] == -1)
					{
						q.push({d + 1, {X, Y}});
						// cerr << "push " << d + 1 << ' ' << X << ' ' << Y << endl;
					}
				}
			}
		}
	}
}
vector<ppp> moves(vector<pii> pos)
{
	vector<ppp> res;
	// cerr << "hi " << pos[0].fi << ' ' << pos[0].se << endl;
	//if all the guys are bad or smt
	// for (int i = 0; i < pos.size(); i++)
	// {
	// 	cerr << "pos[" << i << "] = " << pos[i].fi << ' ' << pos[i].se << endl;
	// }
	while(true)
	{
		bool solved = true, notone = false;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				occ[i][j] = -1;
			}
		}
		for (int i = 0; i < pos.size(); i++)
		{
			// cerr << "pos[" << i << "] = " << pos[i].fi << ' ' << pos[i].se << endl;
			occ[pos[i].fi][pos[i].se] = i;
			if (pos[i] != MP(i + 1, i + 1))
			{
				solved = false;
			}
		}
		if (solved)
		{
			break;
		}
		compute_dist();
		bool change = false;
		for (int i = 0; i < pos.size(); i++)
		{
			if (pos[i] == MP(i + 1, i + 1))
			{
				continue;
			}
			// cerr << pos[i].fi << ' ' << pos[i].se << " want " << 1 << ' ' << i + 1 << ' ' << dist[i + 1][pos[i].fi][pos[i].se] << endl;
			if (dist[i + 1][pos[i].fi][pos[i].se] >= INF)
			{
				continue;
			}
			//yay!
			int x = pos[i].fi, y = pos[i].se;
			while(x != i + 1 || y != i + 1)
			{
				// cerr << 1 << ' ' << i + 1 << " => " << x << ' ' << y << ' ' << dist[i + 1][x][y] << endl;
				for (int j = 0; j < 4; j++)
				{
					int X = x + dx[j], Y = y + dy[j];
					if (valid(X, Y) && dist[i + 1][X][Y] == dist[i + 1][x][y] - 1)
					{
						res.PB({{x, y}, {X, Y}});
						x = X;
						y = Y;
						break;
					}
				}
				// cerr << x << ' ' << y << endl;
			}
			pos[i] = {i + 1, i + 1};
			change = true;
			// cerr << "wohoo solved " << i << endl;
			break;
		}
		if (!change)
		{
			//everybody is trapped
			int idx;
			for (int i = 0; i < pos.size(); i++)
			{
				if (pos[i] != MP(i + 1, i + 1))
				{
					idx = i;
					break;
				}
			}
			if (pos[idx].fi == N)
			{
				res.PB({{pos[idx].fi, pos[idx].se}, {N - 1, pos[idx].se}});
				pos[idx] = {N, pos[idx].se};
			}
			else
			{
				res.PB({{pos[idx].fi, pos[idx].se}, {pos[idx].fi + 1, pos[idx].se}});
				pos[idx].fi++;
			}
		}
	}
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	srand(time(0));
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// if (fopen("input.in", "r"))
	// {
	// 	freopen ("input.in", "r", stdin);
	// 	freopen ("output.out", "w", stdout);
	// }
	cin >> N >> M;
	if (N == 1)
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		beg.PB({x, y});
	}
	res1 = moves(beg);
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		fin.PB({x, y});
	}
	res2 = moves(fin);
	reverse(res2.begin(), res2.end());
	for (ppp &x : res2)
	{
		swap(x.fi, x.se);
	}
	cout << res1.size() + res2.size() << '\n';
	for (ppp x : res1)
	{
		cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se.fi << ' ' << x.se.se << '\n';
	}
	for (ppp x : res2)
	{
		cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se.fi << ' ' << x.se.se << '\n';
	}
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}