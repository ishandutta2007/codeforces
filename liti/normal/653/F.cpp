#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 500005;
const int LG = 20;
const int MOD1 = 1000000007;
const int MOD2 = 1000000007;
const int BASE1 = 701;
const int BASE2 = 727;
int pb1[MAX], pb2[MAX], ph1[MAX], ph2[MAX];
int get_hash1(int l, int r)
{
	return (ph1[r] - 1LL * ph1[l] * pb1[r - l] % MOD1 + MOD1) % MOD1;
}
int get_hash2(int l, int r)
{
	return (ph2[r] - 1LL * ph2[l] * pb2[r - l] % MOD2 + MOD2) % MOD2;
}
long long get_hash(int l, int r)
{
	return 1LL * get_hash1(l, r) * MOD2 + get_hash2(l, r);
}
long long suf[MAX];
long long r[LG][MAX], close[MAX];
int n;
int lcp(int x, int y)
{
	if (x == y)
		return n - x;
	if (x > y)
		swap(x, y);
	int ans = 0;
	for (int i = LG - 1; i >= 0 && y < n; i--)
		if (r[i][x] == r[i][y])
		{
			ans |= (1 << i);
			x += (1 << i);
			y += (1 << i);
		}
	return ans;
}
bool mark[MAX];
int cnt[MAX];
pair<pair<long long, long long>, int> tmp[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(close, -1, sizeof(close));
	pb1[0] = pb2[0] = 1;
	for (int i = 1; i < MAX; i++)
	{
		pb1[i] = 1LL * pb1[i - 1] * BASE1 % MOD1;
		pb2[i] = 1LL * pb2[i - 1] * BASE2 % MOD2;
	}
	string s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		ph1[i] = (1LL * ph1[i - 1] * BASE1 + s[i - 1]) % MOD1;
		ph2[i] = (1LL * ph2[i - 1] * BASE2 + s[i - 1]) % MOD2;
	}
	vector<int> st;
	for (int i = 0; i < n; i++)
		if (s[i] == '(')
			st.push_back(i);
		else if (!st.empty())
		{
			close[st.back()] = i;
			st.pop_back();
		}
	int t = 0;
	for (int i = 0; i < n; i++)
		if (!mark[i] && close[i] != -1)
		{
			int pos = i;
			while (close[pos] != -1)
			{
				mark[pos] = true;
				suf[t++] = get_hash(pos, close[pos] + 1);
				pos = close[pos] + 1;
			}
			suf[t++] = -1;
		}
	n = t;
	for (int i = n - 1; i >= 0; i--)
		if (suf[i] >= 0)
			cnt[i] = cnt[i + 1] + 1;
		else
			cnt[i] = 0;
	for (int i = 0; i < n; i++)
		r[0][i] = suf[i];
	for (int i = 1; i < LG; i++)
	{
		for (int j = 0; j < n; j++)
			if (j + (1 << (i - 1)) >= n)
				tmp[j] = make_pair(make_pair(r[i - 1][j], -1e9), j);
			else
				tmp[j] = make_pair(make_pair(r[i - 1][j], r[i - 1][j + (1 << (i - 1))]), j);
		sort(tmp, tmp + n);
		r[i][tmp[0].second] = 0;
		for (int j = 1; j < n; j++)
			if (tmp[j].first == tmp[j - 1].first)
				r[i][tmp[j].second] = r[i][tmp[j - 1].second];
			else
				r[i][tmp[j].second] = j;
	}
	long long ans = cnt[tmp[0].second];
	for (int i = 1; i < n; i++)
	{
		int cur = tmp[i].second;
		int prv = tmp[i - 1].second;
		int l = lcp(cur, prv);
		l = min(l, cnt[cur]);
		ans += cnt[cur] - l;
	}
	cout << ans << "\n";
	return 0;
}