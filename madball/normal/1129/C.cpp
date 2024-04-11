#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

const int MOD = (int)1e9 + 7;

int add(int a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

void relax(int& a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}

struct Trie
{
	Trie* nxt[2];
	char c;
	Trie* par;
	int ans;
	Trie()
	{
		nxt[0] = nxt[1] = NULL;
		par = NULL;
		ans = 0;
	}
	void recalc(int& global_ans)
	{
		static char s[5];
		Trie* p = this;
		For(i, 4)
		{
			s[i] = '0' + p->c;
			p = p->par;
			if (p == NULL)
				break;
			if (i == 3)
			{
				if (strcmp(s, "0011") == 0)
					continue;
				if (strcmp(s, "0101") == 0)
					continue;
				if (strcmp(s, "1110") == 0)
					continue;
				if (strcmp(s, "1111") == 0)
					continue;
			}
			relax(ans, p->ans);
			relax(global_ans, p->ans);
		}
	}
	void add(vector<char>& ar, int pos, int& global_ans)
	{
		if (pos == sz(ar))
			return;
		Trie*& n = nxt[ar[pos]];
		if (n == NULL)
		{
			n = new Trie();
			n->c = ar[pos];
			n->par = this;
			n->recalc(global_ans);
		}
		n->add(ar, pos + 1, global_ans);
	}
} trie;

void solve()
{
	int m;
	cin >> m;
	trie.ans = 1;
	vector<char> ar(m);
	For(i, m)
	{
		int a;
		cin >> a;
		ar[i] = a;
	}
	reverse(all(ar));
	int ans = 0;
	for (int i = m - 1; i >= 0; --i)
	{
		trie.add(ar, i, ans);
		cout << ans << '\n';
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}