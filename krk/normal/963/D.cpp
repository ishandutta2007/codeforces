#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 2000000007;
const int mod = 1000000007;
const int arg1 = 631;
const int Maxn = 100005;
const int Maxl = 26;

struct node {
	node *ch[Maxl];
	int ind;
	node() {
		for (int i = 0; i < Maxl; i++)
			ch[i] = nullptr;
		ind = -1;
	}
};

int pw[Maxn];
char tmp[Maxn];
string s;
int n;
int K[Maxn];
string M[Maxn];
int H[Maxn];
vector <int> my[Maxn];
node *tr;

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

void Add(node *tr, const string &s, int lvl, int ind)
{
	if (lvl >= s.length()) tr->ind = ind;
	else {
		int nd = s[lvl] - 'a';
		if (!tr->ch[nd]) tr->ch[nd] = new node();
		Add(tr->ch[nd], s, lvl + 1, ind);
	}
}

void Find(node *tr, const string &s, int lvl, int ind)
{
	if (tr->ind != -1) my[tr->ind].push_back(ind);
	if (lvl >= s.length()) return;
	int nd = s[lvl] - 'a';
	if (!tr->ch[nd]) return;
	Find(tr->ch[nd], s, lvl + 1, ind);
}

int getHash(int l, int r)
{
	int res = H[r];
	l--;
	if (l >= 0) res = (res - ll(pw[r - l]) * H[l] % mod + mod) % mod;
	return res;
}

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw[i] = ll(pw[i - 1]) * arg1 % mod;
	Read(s);
	int h = 0;
	for (int i = 0; i < s.length(); i++) {
		h = (ll(h) * arg1 + ll(s[i] - 'a' + 1)) % mod;
		H[i] = h;
	}
	tr = new node();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &K[i]); Read(M[i]);
		if (M[i].length() < 320) Add(tr, M[i], 0, i);
		else {
			int myh = 0;
			for (int j = 0; j < M[i].length(); j++)
				myh = (ll(myh) * arg1 + ll(M[i][j] - 'a' + 1)) % mod;
			for (int j = 0; j + M[i].length() <= s.length(); j++)
				if (myh == getHash(j, j + int(M[i].length()) - 1))
					my[i].push_back(j);
		}
	}
	for (int i = 0; i < s.length(); i++)
		Find(tr, s, i, i);
	for (int i = 0; i < n; i++)
		if (my[i].size() < K[i]) printf("-1\n");
		else {
			int res = Inf;
			for (int j = K[i] - 1; j < my[i].size(); j++)
				res = min(res, my[i][j] - my[i][j - (K[i] - 1)]);
			res += M[i].length();
			printf("%d\n", res);
		}
	return 0;
}