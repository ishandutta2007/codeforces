/*
PROG: cf995a
LANG: C++11
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
 */
#include <bits/stdc++.h>

using namespace std;

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
long long randomize(long long mod)
{
	return ((1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-20;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 51

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;
int grid[5][MAXN];
vector<pair<int, pii> > vec, ans;
vector<pii> pos;
int sent;

void move(int x, pii coor)
{
	vec.PB(MP(x, coor));
	ans.PB(MP(x, coor));
}
void shift()
{
	//check if anybody can go home!
	for (int i = 0; i < N; i++)
	{
		if (grid[1][i] == grid[0][i] && grid[1][i] != 0)
		{
//			cerr << "sent " << grid[1][i] << endl;
			move(grid[1][i], MP(0, i));
			grid[1][i] = 0;
			sent++;
		}
		if (grid[2][i] == grid[3][i] && grid[2][i] != 0)
		{
//			cerr << "sent " << grid[1][i] << endl;
			move(grid[2][i], MP(3, i));
			grid[2][i] = 0;
			sent++;
		}
	}
	vec.clear();
	//now do a shift
	int loc = 0;
	for (int i = 1; i <= 2 * N; i++)
	{
		if (grid[pos[i - 1].fi][pos[i - 1].se] == 0)
		{
			loc = i;
			break;
		}
	}
	for (int i = loc; i < loc + 2 * N; i++)
	{
		if (grid[pos[i].fi][pos[i].se] == 0)
		{
			continue;
		}
		move(grid[pos[i].fi][pos[i].se], pos[i - 1]);
	}
	for (int i = 0; i < N; i++)
	{
		grid[1][i] = 0;
		grid[2][i] = 0;
	}
	for (auto x : vec)
	{
		grid[x.se.fi][x.se.se] = x.fi;
	}
	//	cerr << "shift\n";
	//	for (int k = 0; k < 4; k++)
	//	{
	//		for (int i = 0; i < N; i++)
	//		{
	//			cerr << grid[k][i] << ' ';
	//		}
	//		cerr << endl;
	//	}
	vec.clear();
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf995a.in", "r"))
	{	
		freopen ("cf995a.in", "r", stdin);
		freopen ("cf995a.out", "w", stdout);
	}
	cin >> N >> K;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}
	if (K == 2 * N)
	{
		bool flag = false;
		for (int j = 0; j < N; j++)
		{
			if (grid[0][j] == grid[1][j] || grid[2][j] == grid[3][j])
			{
				flag = true;
			}
		}
		if (!flag)
		{
			cout << "-1\n";
			return 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		pos.PB(MP(1, i));
	}
	for (int i = N - 1; i >= 0; i--)
	{
		pos.PB(MP(2, i));
	}
	for (int i = 0; i < N; i++)
	{
		pos.PB(MP(1, i));
	}
	for (int i = N - 1; i >= 0; i--)
	{
		pos.PB(MP(2, i));
	}
	while(sent < K)
	{
		shift();
		//cyclic shift everything one over
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
	{
		cout << x.fi << ' ' << x.se.fi + 1 << ' ' << x.se.se + 1 << '\n';
	}
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}