#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxl = 26;
const int Maxm = 1000000;

struct node {
	int ch[Maxl];
	int cnt;
	node() {
		fill(ch, ch + Maxl, 0);
		cnt = 0;
	}
};

char tmp[Maxn];
int n, m;
map <string, map <string, int> > M;
string str[Maxn];
int strcnt[Maxn];
ii lr[Maxn];
int mynode[Maxn];
int slen;
node V[Maxm];
int par[Maxm], siz[Maxm];
int vlen;
ll res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

int createNew() {
	par[vlen] = vlen;
	siz[vlen] = 1;
	return vlen++;
}

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

void Merge(int &A, int B)
{
	if (A == 0) { A = B; return; }
	if (B == 0) return;
	if (siz[A] < siz[B]) swap(A, B);
	siz[A] += siz[B]; par[B] = A;
	V[A].cnt += V[B].cnt;
	for (int i = 0; i < Maxl; i++)
		Merge(V[A].ch[i], V[B].ch[i]);
}

int Count(int tr, const string &s, int lvl)
{
	if (tr == 0 || lvl < 0) return 0;
	int res = V[tr].cnt;
	int ind = s[lvl] - 'a';
	if (V[tr].ch[ind]) res += Count(V[tr].ch[ind], s, lvl - 1);
	return res;
}

int Solve(int lvl, const vector <int> &all)
{
	if (lvl >= m) {
		int v = all[0];
		lr[v] = ii(m, m - 1);
		mynode[v] = createNew();
		V[mynode[v]].cnt += strcnt[v];
		return mynode[v];
	}
	int root = 0;
	vector <int> spec[Maxl] = {};
	for (int i = 0; i < all.size(); i++)
		spec[str[all[i]][lvl] - 'a'].push_back(all[i]);
	for (int i = 0; i < Maxl; i++) if (!spec[i].empty()) {
		int got = Solve(lvl + 1, spec[i]);
		for (int j = 0; j < spec[i].size(); j++)
			res -= ll(strcnt[spec[i][j]]) * Count(root, str[spec[i][j]], m - 1);
		Merge(root, got);
		for (int j = 0; j < spec[i].size(); j++) {
			int v = spec[i][j];
			if (lvl + 1 == m || str[v][lvl] > str[v][lvl + 1]) {
				int pos = getPar(mynode[v]);
				V[pos].cnt -= strcnt[v];
				while (lr[v].first <= lr[v].second) {
					int ind = str[v][lr[v].second] - 'a';
					if (!V[pos].ch[ind]) V[pos].ch[ind] = createNew();
					pos = V[pos].ch[ind];
					lr[v].second--;
				}
				mynode[v] = pos;
				V[mynode[v]].cnt += strcnt[v];
			}
			lr[v].first = lvl;
		}
	}
	return root;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s; Read(s);
		string srt = s;
		sort(srt.begin(), srt.end());
		M[srt][s]++;
	}
	createNew();
	int was = 0;
	for (auto it = M.begin(); it != M.end(); it++) {
		slen = 0;
		int add = 0;
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			str[slen] = it2->first; strcnt[slen] = it2->second;
			res += 1337ll * ll(was) * strcnt[slen] + 2ll * ll(add) * strcnt[slen];
			add += strcnt[slen];
			slen++;
		}
		m = str[0].length();
		vector <int> seq;
		for (int i = 0; i < slen; i++)
			seq.push_back(i);
		Solve(0, seq);
		was += add;
	}
	cout << res << endl;
    return 0;
}