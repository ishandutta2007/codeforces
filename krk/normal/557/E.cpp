#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;

string s;
bool dp[Maxn][Maxn];
int k;

struct trie {
	trie *a, *b;
	int lst, cnt;
	trie() { a = NULL; b = NULL; cnt = 0; }
};

trie *tr;

bool Ok(int l, int r) { return l >= r || dp[l][r]; }

void Insert(trie *tr, int ind)
{
	tr->lst = ind; tr->cnt++;
	if (ind < s.length())
		if (s[ind] == 'a') {
			if (!tr->a) tr->a = new trie();
			Insert(tr->a, ind + 1);
		} else {
			if (!tr->b) tr->b = new trie();
			Insert(tr->b, ind + 1);
		}
}

bool Get(trie *tr, int lvl, int &k, ii &res)
{
	if (lvl && dp[tr->lst - lvl][tr->lst - 1])
		if (tr->cnt >= k) { res = ii(tr->lst - lvl, tr->lst - 1); return true; }
		else k -= tr->cnt;
	if (tr->a)
		if (Get(tr->a, lvl + 1, k, res)) return true;
	if (tr->b)
		if (Get(tr->b, lvl + 1, k, res)) return true;
	return false;
}

int main()
{
	cin >> s;
	for (int l = 1; l <= s.length(); l++)
		for (int j = 0; j + l <= s.length(); j++) {
			int r = j + l - 1;
			dp[j][r] = s[j] == s[r] && Ok(j + 2, r - 2);
		}
	tr = new trie();
	for (int i = 0; i < s.length(); i++)
		Insert(tr, i);
	cin >> k;
	ii res; Get(tr, 0, k, res);
	printf("%s\n", s.substr(res.first, res.second - res.first + 1).c_str());
	return 0;
}