#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

char tmp[Maxn];
int tlen;
map <string, int> H, P;
string nam[Maxn];
vector <int> my[Maxn];
int srt[Maxn];
int n;
vector <vector <int> > res;

int getID(map <string, int> &M, const string &s)
{
	if (M.find(s) == M.end()) {
		int cur = M.size();
		M[s] = cur;
	}
	return M[s];
}

bool Less(const int &a, const int &b)
{
	if (my[a].size() != my[b].size()) return my[a].size() < my[b].size();
	for (int i = 0; i < my[a].size(); i++)
		if (my[a][i] != my[b][i]) return my[a][i] < my[b][i];
	return false;
}

bool Eq(const int &a, const int &b)
{
	if (my[a].size() != my[b].size()) return false;
	for (int i = 0; i < my[a].size(); i++)
		if (my[a][i] != my[b][i]) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp); tlen = strlen(tmp);
		string a, b;
		int j = 7;
		for (; j < tlen && tmp[j] != '/'; j++)
			a += string(1, tmp[j]);
		for (; j < tlen; j++)
			b += string(1, tmp[j]);
		int ida = getID(H, a), idb = getID(P, b);
		nam[ida] = a;
		my[ida].push_back(idb);
	}
	for (int i = 0; i < H.size(); i++) {
		sort(my[i].begin(), my[i].end());
		my[i].erase(unique(my[i].begin(), my[i].end()), my[i].end());
	}
	for (int i = 0; i < H.size(); i++)
		srt[i] = i;
	sort(srt, srt + H.size(), Less);
	for (int i = 0, j; i < H.size(); i = j) {
		j = i + 1;
		while (j < H.size() && Eq(srt[i], srt[j])) j++;
		if (j - i > 1) {
			vector <int> cur;
			for (int l = i; l < j; l++)
				cur.push_back(srt[l]);
			res.push_back(cur);
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		for (int j = 0; j < res[i].size(); j++)
			printf("http://%s%c", nam[res[i][j]].c_str(), j + 1 < res[i].size()? ' ': '\n');
	return 0;
}