#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...) 42
#endif


typedef long long int int64;

const int maxn = (int) 2e5 + 100;

const int L = 6;
const int K = 2;
const int p = 31;
const int N = maxn * 2;

int mods_list[] = {(int)1e9 + 7, (int)1e9 + 17, (int)1e9 + 87, (int)1e9 + 97, (int)1e9 + 123, (int)1e9 + 223};
int mods[K];
int pow_p[K][N];

int add(int a, int b, int mod)
{
	int res = a + b;
	if (res >= mod)
		res -= mod;
	return res;
}

int sub(int a, int b, int mod)
{
	int res = a - b;
	if (res < 0)
		res += mod;
	return res;
}

int mul(int a, int b, int mod)
{
	return (int64)a * b % mod;
}

struct Hash
{
	int h[K];

	Hash()
	{
		for (int i = 0; i < K; i++)
			h[i] = 0;
	}

	Hash(char c)
	{
		for (int i = 0; i < K; i++)
			h[i] = (int)(c - 'a' + 1);
	}

	bool operator == (Hash o)
	{
		for (int i = 0; i < K; i++)
			if (h[i] != o.h[i])
				return false;
		return true;
	}

	bool operator != (Hash o)
	{
		return !(*this == o);
	}

	Hash operator + (Hash o)
	{
		Hash res;
		for (int i = 0; i < K; i++)
			res.h[i] = add(h[i], o.h[i], mods[i]);
		return res;
	}

	Hash operator - (Hash o)
	{
		Hash res;
		for (int i = 0; i < K; i++)
			res.h[i] = sub(h[i], o.h[i], mods[i]);
		return res;
	}

	Hash up(int st)
	{
		Hash res;
		for (int i = 0; i < K; i++)
			res.h[i] = mul(h[i], pow_p[i][st], mods[i]); 
		return res;
	}
};

void init()
{
	int p1 = rand() % L;
	int p2 = rand() % L;
	while (p1 == p2)
		p2 = rand() % L;
	mods[0] = mods_list[p1];
	mods[1] = mods_list[p2];
	for (int i = 0; i < K; i++)
	{
		pow_p[i][0] = 1;
		for (int j = 1; j < N; j++)
			pow_p[i][j] = mul(pow_p[i][j - 1], p, mods[i]);
	}
}


const int alp = 26;
int nxt[maxn][alp];

int used[alp];
int mt[maxn][alp];
int sz;
char s[maxn], t[maxn];
Hash p_hash_s[alp][maxn], p_hash_t[alp][maxn];

void calc_h(char str[], int len, Hash res[maxn])
{
	for (int i = 0; i < len; i++)
	{
		res[i] = Hash(str[i]).up(i);
		if (i != 0)
			res[i] = res[i] + res[i - 1];
	}
}

char buf_str[maxn];

void calc_h0(char str[], int len, Hash res[alp][maxn])
{
	for (char c = 'a'; c <= 'z'; c++)
	{
		for (int i = 0; i < len; i++)
		{
			if (str[i] == c)
				buf_str[i] = 'a';
			else
				buf_str[i] = 'b';
		}
		calc_h(buf_str, len, res[(int)(c - 'a')]);
	}
}

Hash get_hash(int l, int r, Hash h[maxn])
{
	Hash res = h[r];
	if (l != 0)
		res = res - h[l - 1];
	res = res.up(N / 2 - l);
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	init();

	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	scanf("%s", t);

	calc_h0(s, n, p_hash_s);
	calc_h0(t, m, p_hash_t);

	for (int i = 0; i < alp; i++)
	{
		nxt[n][i] = n;
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < alp; j++)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}

	vector<int> ans;
	memset(mt, -1, sizeof mt);
	for (int i = 0; i <= n - m; i++)
	{
		for (int c = 0; c < alp; c++)
		{
			if (nxt[i][c] < i + m)
			{
				int d = t[nxt[i][c] - i] - 'a';
				mt[i][c] = d;
				mt[i][d] = c;
			}
		}
		
		bool good = true;
		for (int c = 0; c < alp; c++)
		{
			if (mt[i][c] == -1)
				continue;
			int to = mt[i][c];

			Hash h1 = get_hash(i, i + m - 1, p_hash_s[c]);
			Hash h2 = get_hash(0, m - 1, p_hash_t[to]);
			if (h1 != h2)
				good = false;
		}

		if (good)
			ans.push_back(i);
	}

	printf("%d\n", (int)ans.size());
	for (int x : ans)
		printf("%d ", x + 1);

	return 0;
}