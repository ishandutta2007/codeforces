#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int Maxl = 26;
const int Maxn = 105;

int n;
string s[Maxn];
vector <int> neigh[Maxl];
int in[Maxl];
int tk[Maxl];
int seq[Maxl], slen;

bool Possible(const string &a, const string &b)
{
	for (int i = 0; i < a.length() && i < b.length(); i++)
		if (a[i] != b[i]) { neigh[a[i] - 'a'].push_back(b[i] - 'a'); in[b[i] - 'a']++; return true; }
	return a.length() < b.length();
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (i) if (!Possible(s[i - 1], s[i])) { printf("Impossible\n"); return 0; }
	}
	for (int i = 0; i < Maxl; i++)
		if (!in[i] && !tk[i]) { tk[i] = true; seq[slen++] = i; }
	for (int i = 0; i < Maxl; i++) {
		int v = seq[i];
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (--in[u] == 0 && !tk[u]) { tk[u] = true; seq[slen++] = u; }
		}
	}
	if (slen != Maxl) { printf("Impossible\n"); return 0; }
	for (int i = 0; i < Maxl; i++)
		printf("%c", 'a' + seq[i]);
	printf("\n");
	return 0;
}