#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ctime>
#include <cstring>
#include <random>
#include <iomanip>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
typedef long double ld;

#define For(i, n) for (int i = 0; i < (n); ++i)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define TIMED_FUNC TimerRegion timer_func(__FUNCTION__);

struct Timer
{
	static map<string, Timer> ar;

	lint time;
	lint last;
	bool running;
	int count;
	Timer() : time(0), running(false), count(0) {}
#ifdef LOCAL
	void start()
	{
		if (running)
			throw;
		running = true;
		last = clock();
	}
	void stop()
	{
		if (!running)
			throw;
		running = false;
		time += clock() - last;
		++count;
	}
	static void start(string name)
	{
		if (!ar.count(name))
			ar[name] = Timer();
		ar[name].start();
	}
	static void stop(string name)
	{
		if (!ar.count(name))
			throw;
		ar[name].stop();
	}
	ld time_f()
	{
		return (ld)time / CLOCKS_PER_SEC;
	}
	ld avg_time_f()
	{
		return time_f() / count;
	}
#else
	void start() {}
	void stop() {}
	static void start(string name) {}
	static void stop(string name) {}
	ld time_f() { return 0; }
	ld avg_time_f() { return 0; }
#endif
};

map<string, Timer> Timer::ar;

struct TimerRegion
{
	string name;
	TimerRegion(string _name) : name(_name)
	{
		Timer::start(name);
	}
	~TimerRegion()
	{

		Timer::stop(name);
	}
};

const int MOD1 = 1'000'000'007;
const int MOD2 = 1'000'000'009;
const int PRIME1 = 10007;
const int PRIME2 = 1'000'003;
int INV1;
int INV2;
const int MAXN = (int)1e5 + 5;
int POW1[MAXN * 2];
int POW2[MAXN * 2];

int add(int a, int b, int m)
{
	a += b;
	if (a >= m)
		a -= m;
	return a;
}

int sub(int a, int b, int m)
{
	return add(a, m - b, m);
}

int mul(int a, int b, int m)
{
	return ((lint)a * b) % m;
}

int pow(int a, int b, int m)
{
	return b == 0 ? 1 : b & 1 ? mul(pow(a, b - 1, m), a, m) : pow(mul(a, a, m), b / 2, m);
}

struct Hash
{
	int a, b, size;
	Hash() : a(0), b(0), size(0) {}
	Hash(int n) : a(n % MOD1), b(n % MOD2), size(1) {}
	Hash(int a, int b, int size) : a(a), b(b), size(size) {}
	Hash operator + (const Hash& h) const
	{
		return Hash(add(a, h.a, MOD1), add(b, h.b, MOD2), max(size, h.size));
	}
	Hash operator << (int n) const
	{
		return Hash(mul(n < MAXN * 2 ? POW1[n] : pow(PRIME1, n, MOD1), a, MOD1),
			mul(n < MAXN * 2 ? POW2[n] : pow(PRIME2, n, MOD2), b, MOD2), size + n);
	}
	Hash concat(const Hash& other) const
	{
		return (*this) + (other << size);
	}
	bool operator < (const Hash& h) const
	{
		return a != h.a ? a < h.a : b < h.b;
	}
};

vector<int> graph[MAXN];
Hash hash_down[MAXN];
Hash hash_up[MAXN];
int sz[MAXN];

Hash dfs1(int v, int from = -1)
{
	sz[v] = 1;
	Hash h = Hash(1);
	vector<Hash> children;
	for (auto e : graph[v])
		if (e != from)
		{
			children.push_back(dfs1(e, v));
			sz[v] += sz[e];
		}
	sort(all(children));
	for (auto e : children)
		h = h.concat(e);
	h = h.concat(2);
	hash_down[v] = h;
	return h;
}

void dfs2(int v, int from = -1)
{
	vector<Hash> children;
	for (auto e : graph[v])
		if (e != from)
			children.push_back(hash_down[e]);
	if (children.empty())
		return;
	if (from != -1)
		children.push_back(hash_up[v]);
	sort(all(children));

	vector<Hash> pref(sz(children));
	vector<Hash> suf(sz(children));
	pref[0] = children[0];
	suf.back() = children.back();
	for (int i = 1; i < sz(children); ++i)
		pref[i] = pref[i - 1].concat(children[i]);
	for (int i = sz(children) - 2; i >= 0; --i)
		suf[i] = children[i].concat(suf[i + 1]);

	for (auto e : graph[v])
		if (e != from)
		{
			int i = lower_bound(all(children), hash_down[e]) - children.begin();
			hash_up[e] = Hash(1).concat(i ? pref[i - 1] : Hash()).concat(i == sz(suf) - 1 ? Hash() : suf[i + 1]).concat(2);
			dfs2(e, v);
		}
}

struct Profile
{
	map<Hash, int> mp;
	int res, res_val;
	Profile() : res(0), res_val(0) {}
	void add(Hash h)
	{
		if (mp.count(h))
			++mp[h];
		else
			mp[h] = 1;
	}
	void remove(Hash h)
	{
		if (!mp.count(h))
			throw;
		--mp[h];
		if (mp[h] == 0)
			mp.erase(h);
	}
	void update(int v)
	{
		if (sz(mp) >= res_val)
		{
			res_val = sz(mp);
			res = v;
		}
	}
};

void dfs3(int v, int from, Profile& profile)
{
	profile.update(v);
	for (auto e : graph[v])
		if (e != from)
		{
			profile.remove(hash_down[e]);
			profile.add(hash_up[e]);
			dfs3(e, v, profile);
			profile.remove(hash_up[e]);
			profile.add(hash_down[e]);
		}
}

void solve()
{
	TIMED_FUNC;
	int n;
	cin >> n;
	For(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs1(0);
	dfs2(0);
	/*For(i, n)
	{
		cout << add(hash_down[i].a, mul(hash_down[i].b, 998244353, 1000000123), 1000000123) << ' ' <<
			add(hash_up[i].a, mul(hash_up[i].b, 998244353, 1000000123), 1000000123) << '\n';
	}*/
	Profile profile;
	For(i, n)
		profile.add(hash_down[i]);
	dfs3(0, -1, profile);
	cout << profile.res + 1 << '\n';
#ifdef LOCAL
	cout << profile.res_val << '\n';
#endif
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	POW1[0] = POW2[0] = 1;
	for (int i = 1; i < MAXN * 2; ++i)
	{
		POW1[i] = mul(POW1[i - 1], PRIME1, MOD1);
		POW2[i] = mul(POW2[i - 1], PRIME2, MOD2);
	}
	INV1 = pow(PRIME1, MOD1 - 2, MOD1);
	INV2 = pow(PRIME2, MOD2 - 2, MOD2);
	solve();

#ifdef LOCAL
	printf("\n\n");
	for (auto it : Timer::ar)
	{
		printf("%s = %.3lf\n", it.first.c_str(), it.second.time_f());
	}
#endif
	return 0;
}