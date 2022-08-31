#include <bits/stdc++.h>

using namespace std;

//using ll = int64_t;
using ll = long long;
using ull = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = double;

#define X first
#define Y second

int64_t power(int64_t a, int64_t b, int64_t p)
{
	if (!b) return 1;
	int64_t t = power(a, b >> 1, p);
	t = t * t % p;
	if (b & 1) t = t * a % p;
	return t;
}

//mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
inline void freshmin(T& a, const T& b)
{
	if (a > b) a = b;
}

template<class T>
inline void freshmax(T& a, const T& b)
{
	if (a < b) a = b;
}

const ll B = 31;
//const ll MOD = 1000000007;
const int INF = 1000000010;
const ll INFll = 4000000000000000000LL;
const int MAXN = 500010;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

int n;
u64 mx;
u64 res[MAXN];

u64 query(int L, int R)
{
	printf("?");
	printf(" %d", R-L+1);
	for (int i = L; i <= R; ++i) printf(" %d", i);
	printf("\n");
	fflush(stdout);
	ull x;
	scanf("%llu", &x);
	return x;
}

u64 query(vector<int> &q)
{
	if (q.empty()) return 0;
	printf("?");
	printf(" %d", q.size());
	for (auto x : q) printf(" %d", x);
	printf("\n");
	fflush(stdout);
	ull x;
	scanf("%llu", &x);
	return x;
}

void solve()
{
	scanf("%d", &n);

	mx = query(1, n);
	vector<pii> v(64);
	for (int k = 0; k < 64; ++ k)
		if (mx >> k & 1)
		{
			v[k] = { 1, n };
		}
		else
		{
			v[k] = { 0, 0 };
		}
	for (int ttt = 1; ttt <= 11; ++ttt)
	{
		set<int> q;
		for (int k = 0; k < 64; ++k)
		{
			auto [L, R] = v[k];
			if (L == 0) continue;
			if (L > R) continue;
			int m = (L + R) / 2;
			for (int i = L; i <= m; ++i)
			{
				q.insert(i);
			}
		}
		vector<int> qc(q.begin(), q.end());
		u64 feedback = query(qc);
		for (int k = 0; k < 64; ++k)
		{
			auto [L, R] = v[k];
			if (L == 0) continue;
			if (L > R) continue;
			int m = (L + R) / 2;
			if (feedback >> k & 1)
			{
				for (int i = 1; i <= n; ++i)
					if (!(L <= i && i <= m)) res[i] |= 1ULL << k;
				R = m;
			}
			else
			{
				for (int i = 1; i <= n; ++i)
					if (!(m + 1 <= i && i <= R)) res[i] |= 1ULL << k;
				L = m + 1;
			}
			v[k] = { L, R };
		}

		++ttt;
		--ttt;
	}

	{
		set<int> q;
		for (int k = 0; k < 64; ++k)
		{
			auto [L, R] = v[k];
			if (L == 0) continue;
			if (L > R) continue;
			q.insert(L);
		}
		vector<int> qc;
		for (int i = 1; i <= n; ++i) if (q.count(i) == 0) qc.push_back(i);
		u64 feedback = query(qc);
		for (int k = 0; k < 64; ++k)
		{
			auto [L, R] = v[k];
			if (L == 0) continue;
			if (L > R) continue;
			res[L] |= feedback;
			for (int kk = 0; kk < 64; ++kk) if (k != kk)
			{
				auto [LL, RR] = v[kk];
				if (LL == 0 || LL > RR) continue;
				res[L] |= 1ULL << kk;
			}
		}
	}

	printf("!");
	for (int i = 1; i <= n; ++i)
		printf(" %llu", res[i]);
	puts("");
	fflush(stdout);
}

int main()
{

	int T = 1;
	//read(T);
	for (int test = 1; test <= T; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}

	return 0;
}