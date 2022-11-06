#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).cntd()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll reast1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;


const int N = 1000010;
const int mod = 1e9 + 7;
int n, p, k[N];

int qpow(int x, int times)
{
	int res = 1;
	while (times)
	{
		if (times & 1) res = 1LL * res * x % mod;
		x = 1LL * x * x % mod;
		times >>= 1;
	}
	return res;
}

pii first(set<pii> &S)
{
	if (sz(S)) return *S.rbegin();
	else return mp(-1, -1);
}

void add(set<pii> &S, int pos)
{
	while (1)
	{
		auto it = S.lower_bound(mp(pos, 0));
		if (it != S.end() && (*it) == mp(pos, p - 1))
		{
			auto it2 = it;
			it ++;
			S.erase(it2);
			pos ++;
		}
		else break;
	}
	auto it = S.lower_bound(mp(pos, 0));
	if (it == S.end() || it -> X != pos) S.insert(mp(pos, 1));
	else
	{
		int t = it -> Y + 1;
		S.erase(it);
		S.insert(mp(pos, t));
	}
}

int main()
{
	int T = read();
	while (T --)
	{
		n = read();
		p = read();
		rep(i, 1, n) k[i] = read();

		sort(k + 1, k + n + 1);
		reverse(k + 1, k + n + 1);
		set<pii> st1, st2;
		int sum1 = 0, sum2 = 0;
		rep(i, 1, n)
		{
			while (st1.size() && first(st1) == first(st2))
			{
				st1.erase(*st1.rbegin());
				st2.erase(*st2.rbegin());
			}
			bool flag = 0;
			if (sz(st1) || sz(st2)) flag = (first(st1) < first(st2));
			if (flag)
			{
				add(st1, k[i]);
				sum1 += qpow(p, k[i]);
				if (sum1 >= mod) sum1 -= mod;
			}
			else
			{
				add(st2, k[i]);
				sum2 += qpow(p, k[i]);
				if (sum2 >= mod) sum2 -= mod;
			}
			//cout << sum1 << " " << sum2 << " " << flag << endl;
		}
		while (st1.size() && first(st1) == first(st2))
		{
			st1.erase(*st1.rbegin());
            st2.erase(*st2.rbegin());
		}
		bool flag = 0;
		if (sz(st1) || sz(st2)) flag = (first(st1) < first(st2));
		if (p == 1) {printf("%d\n", n % 2); continue;}
		if (flag) printf("%d\n", (sum2 - sum1 + mod) % mod);
		if (!flag) printf("%d\n",  (sum1 - sum2 + mod) % mod);
	}
	return 0;
}