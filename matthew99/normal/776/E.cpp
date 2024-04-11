#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int max0 = 1000100;

bool vis[max0 + 5];

vector<int> pr;

inline void prepare()
{
	memset(vis, 0, sizeof vis);
	for (int i = 2; i <= max0; ++i) if (!vis[i])
	{
		pr.pb(i);
		for (int j = i << 1; j <= max0; j += i) vis[j] = 1;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	LL n, K;
	cin >> n >> K;
	K = (K + 1) >> 1;
	while (K--)
	{
		if (n == 1) break;
		LL nxt = 1;
		for (int i = 0; i < SZ(pr) && (LL)pr[i] * pr[i] <= n; ++i)
			if (!(n % pr[i]))
			{
				nxt *= pr[i] - 1, n /= pr[i];
				while (!(n % pr[i])) n /= pr[i], nxt *= pr[i];
			}
		if (n > 1) nxt *= n - 1;
		n = nxt;
	}
	cout << n % Mod << endl;
	return 0;
}