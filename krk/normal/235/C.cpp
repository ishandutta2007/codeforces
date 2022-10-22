#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 2 * Maxn;
const int Maxl = 26;

struct node {
	int len, link;
	int nxt[Maxl];
	int cnt;
	node() { len = 0; link = -1; fill(nxt, nxt + Maxl, -2); cnt = 0; }
};

string s;
node sa[Maxm];
int siz = 1, lst;
vector <int> seq[Maxn];
int n;
int kmp[Maxm];
int res;

void Extend(int ch)
{
	int cur = siz++;
	sa[cur].len = sa[lst].len + 1; sa[cur].cnt = 1;
	int p;
	for (p = lst; p != -1 && sa[p].nxt[ch] == -2; p = sa[p].link)
		sa[p].nxt[ch] = cur;
	if (p == -1) sa[cur].link = 0;
	else {
		int q = sa[p].nxt[ch];
		if (sa[p].len + 1 == sa[q].len) sa[cur].link = q;
		else {
			int clone = siz++;
			sa[clone].len = sa[p].len + 1;
			for (int i = 0; i < Maxl; i++) sa[clone].nxt[i] = sa[q].nxt[i];
			sa[clone].link = sa[q].link;
			for (; p != -1 && sa[p].nxt[ch] == q; p = sa[p].link)
				sa[p].nxt[ch] = clone;
			sa[q].link = sa[cur].link = clone;
		}
	}
	lst = cur;
}

int getTimes(const string &s)
{
	int i = 0, j = -1; kmp[0] = -1;
	while (i < s.length()) {
		while (j >= 0 && s[i] != s[j]) j = kmp[j];
		i++; j++;
		kmp[i] = j;
	}
	return s.length() - 1 - kmp[s.length() - 1];
}

int main()
{
	char tmp[Maxn];
	scanf("%s", tmp); s = tmp;
	for (int i = 0; i < s.length(); i++)
		Extend(s[i] - 'a');
	for (int i = 1; i < siz; i++)
		seq[sa[i].len].push_back(i);
	for (int i = s.length(); i > 0; i--)
		for (int j = 0; j < seq[i].size(); j++) {
			int v = seq[i][j];
			sa[sa[v].link].cnt += sa[v].cnt;
		}
	string x;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", tmp); x = tmp;
		int len = x.length(); x = x + x;
		int lim = getTimes(x);
		res = 0;
		int cur = 0;
		int r = 0;
		for (int l = 0; l < lim; l++) {
			if (r < l) r++;
			while (r - l < len && sa[cur].nxt[x[r] - 'a'] != -2) {
				cur = sa[cur].nxt[x[r] - 'a']; r++;
			}
			if (r - l == len) res += sa[cur].cnt;
			if (l == r) cur = 0;
			else if (sa[sa[cur].link].len >= r - l - 1) cur = sa[cur].link;
		}
		printf("%d\n", res);
	}
	return 0;
}