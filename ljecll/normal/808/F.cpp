/*
PROG: cf808f
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

long long readi()
{
	long long input = 0;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	bool negative = false;
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = 10 * input + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	return input;
}
void printi(long long output)
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
string reads()
{
	string input = "";
	char c = ' ';
	while (c <= ' ')
	{
		c = getchar();
	}
	while (c > ' ')
	{
		input += c;
		c = getchar();
	}
	return input;
}
int sgn(long long x)
{
	if (x < 0) 
	{
		return -1;
	}
	if (x > 0) 
	{
		return 1;
	}
	return 0;
}
long long randomize(long long x)
{
	return (((1ll << 31) * rand()) + rand()) % x;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-30;

#define CO 10007
#define INF 1000000007
#define HASHMOD 333555577577777ll
#define LLINF 2696969696969696969ll
#define CO 1000037
#define MAXN 200010
#define MAXM 100010


long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<ll, ll> pll;

int N, K;
pip cards[MAXN];
vector<pii> arr;
bool prime[MAXN];
bool one;
int ans;
int S = 0, T = 1, E = 2;
int level[MAXN];
ll from[2 * MAXM], to[2 * MAXM], cap[2 * MAXM], nxt[2 * MAXM], head[2 * MAXM];
ll res;
ll tot;

void addedge(int u, int v, ll sz)
{
	//	cerr << u << ' ' << v << ' ' << sz << endl;
	from[E] = u;
	to[E] = v;
	cap[E] = sz;
	nxt[E] = head[u];
	head[u] = E;
	E++;
	from[E] = v;
	to[E] = u;
	cap[E] = 0;
	nxt[E] = head[v];
	head[v] = E;
	E++;
}
bool bfs()
{
	for (int i = 0; i <= arr.size() + 1; i++)
	{
		level[i] = -1;
	}
	queue<int> q;
	q.push(S);
	level[S] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i > 0; i = nxt[i])
		{
			int v = to[i];
			if (cap[i] > 0 && level[v] == -1)
			{
				level[v] = level[u] + 1;
				q.push(v);
				if (v == T)
				{
					return true;
				}
			}
		}
	}
	return false;
}
ll aug(int u, ll flo)
{
	if (u == T)
	{
		res += flo;
		return flo;
	}
	ll rem = flo, gain = 0;
	for (int i = head[u]; i > 0 && rem > 0; i = nxt[i])
	{
		int v = to[i];
		if (cap[i] > 0 && level[v] == level[u] + 1)
		{
			gain = aug(v, min(rem, cap[i]));
			cap[i] -= gain;
			cap[i ^ 1] += gain;
			rem -= gain;
		}
	}
	return flo - rem;
}
ll dinic()
{
	res = 0ll;
	while(bfs())
	{
		aug(S, LLINF);
	}
	return res;
}
bool check()
{
	for (int i = 0; i < arr.size() + 2; i++)
	{
		head[i] = 0;
	}
	E = 2;
	for (int i = 0; i < arr.size(); i++)
	{
		int val = arr[i].fi, magic = arr[i].se;
		if (magic % 2)
		{
			//add edges to the starting guy
			addedge(S, i + 2, val);
			for (int j = 0; j < i; j++)
			{
				if (prime[magic + arr[j].se])
				{
					addedge(i + 2, j + 2, INF);
				}
			}
		}
		else
		{
			addedge(i + 2, T, val);
			for (int j = 0; j < i; j++)
			{
				if (prime[magic + arr[j].se])
				{
					addedge(j + 2, i + 2, INF);
				}
			}
		}
	}
	ll res = tot - dinic();
	//	cerr << res << endl;
	return (res >= K);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf808f.in", "r"))
	{	
		freopen ("cf808f.in", "r", stdin);
		freopen ("cf808f.out", "w", stdout);
	}
	cin >> N >> K;
	for (int i = 2; i < MAXN; i++)
	{
		prime[i] = true;
	}
	for (int i = 2; i < MAXN; i++)
	{
		if (!prime[i])
		{
			continue;
		}
		for (int j = i; j < MAXN/i; j++)
		{
			prime[j * i] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> cards[i].se.fi >> cards[i].se.se >> cards[i].fi; //power, magic #, level
	}
	sort(cards, cards + N);
	for (int i = 0; i < N; i++)
	{
		if (cards[i].se.se == 1)
		{
			if (one)
			{
				for (int j = 0; j < arr.size(); j++)
				{
					if (arr[j].se == 1)
					{
						tot += (cards[i].se.fi - arr[j].fi);
						arr[j].fi = cards[i].se.fi;
					}
				}
				if (check())
				{
					cout << cards[i].fi << '\n';
					return 0;
				}
				continue;
			}
			one = true;
		}
		//		cerr << "level " << cards[i].fi << ' ' << "power " << cards[i].se.fi << ' ' << "magic " << cards[i].se.se << endl;
		arr.PB(cards[i].se);
		tot += cards[i].se.fi;
		if (check())
		{
			cout << cards[i].fi << '\n';
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}