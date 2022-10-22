#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

char tmp[10];
int n, m, k;
map <string, int> ID;
string cur;
int seq[Maxn], slen;
vector <int> neigh[Maxn];
int in[Maxn];

int getID(const string &s)
{
	auto it = ID.find(s);
	if (it == ID.end()) return -1;
	return it->second;
}

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

void Gen(int lvl, const string &s)
{
	if (lvl >= k) {
		int id = getID(cur);
		if (id != -1) seq[slen++] = id;
	} else {
		cur[lvl] = '_';
		Gen(lvl + 1, s);
		cur[lvl] = s[lvl];
		Gen(lvl + 1, s);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		string s; Read(s);
		ID.insert(make_pair(s, i));
	}
	for (int i = 1; i <= m; i++) {
		string s; Read(s);
		cur.resize(k);
		slen = 0;
		Gen(0, s);
		bool was = false;
		int mt; scanf("%d", &mt);
		for (int j = 0; j < slen; j++)
			if (mt == seq[j]) was = true;
			else {
				neigh[mt].push_back(seq[j]);
				in[seq[j]]++;
			}
		if (!was) { printf("NO\n"); return 0; }
	}
	slen = 0;
	for (int i = 1; i <= n; i++) if (in[i] == 0)
		seq[slen++] = i;
	for (int i = 0; i < slen; i++) {
		int v = seq[i];
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (--in[u] == 0) seq[slen++] = u;
		}
	}
	if (slen == n) {
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("%d%c", seq[i], i + 1 < n? ' ': '\n');
	} else printf("NO\n");
    return 0;
}